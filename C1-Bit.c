#include <stdio.h>

int charSize = sizeof(char)*8;
int intSize = sizeof(int)*8;

void printBinaryUChar(unsigned char c){
	int i = 0;
	printf("%i:",c);
	for(; i < charSize; i++){
		if(!(i % 4)) 
			printf(" ");
		printf("%i",(c & (1 << (charSize - 1 - i))) >> (charSize - 1 - i));
	}
	printf("\n");
}

void printBinaryUInt(unsigned int b){
	int i = 0;
	printf("%i:",b);
	for(; i < intSize; i++){
		if(!(i%4)) 
			printf(" ");
		printf("%i",(b & (1 << (intSize - 1 - i))) >> (intSize - 1 - i));
	}
	printf("\n");
}

void printBinaryInt(int b){
	int i = 0;
	printf("%i:",b);
	for(; i < intSize; i++){
		if(!(i%4)) 
			printf(" ");
		printf("%i",(b & (1 << (intSize - 1 - i))) >> (intSize - 1 - i));
	}
	printf("\n");
}



int posicionBits(int x, int p, int n){
	printf("X: ");
	printBinaryInt(x);
	printf("P: ");
	printBinaryInt(p);
	int intSize = sizeof(x)*8;
	int i = 0;
	for(;i<intSize-n;i++){
		int mask = (1<<(n+i))-1;
		int masked = (x&mask)>>i;
		if(masked==p)
			return i;
	}
	return -1;
}

int recursiva(unsigned int x, int s){
	unsigned int mask = (1<<(s>>1))-1;

	unsigned nMasked = (x&~mask)>>(s>>1);
	unsigned masked = x&mask;
	
	if	(!s) 
		return 0;
	
	if(nMasked==1) 
		return 1+(s>>1);
	
	else if (nMasked>1) 
		return (s>>1) + recursiva(nMasked,(s>>1));
	
	else 
		return recursiva(masked,(s>>1));
}

int bitMasSignificativo(unsigned int x){
	printBinaryUInt(x);
	return recursiva(x, sizeof(x)*8);
}

int minus(int x){
	return 1 + ~x;
}

int isNeg(int x){
	return ((1 << (intSize - 1)) & x) >> (intSize - 1);
}

int abs(int x){
	if(isNeg(x)) 
		return minus(x);
	else 
		return x;
}

unsigned char rotateLeft(unsigned char c){
	unsigned char mask = 1 << 7;
	unsigned char msb = c & mask;
	printf("LFT: ");
	unsigned char r = (c << 1) + msb;
	printBinaryUChar(r);
	return r;
}

unsigned char rotateRight(unsigned char c){
	unsigned char mask = 1;
	unsigned char lsb = c & mask;
	printf("RGT: ");
	unsigned char r = (c >> 1) + (lsb << 7);
	printBinaryUChar(r);
	return r;
}

unsigned char rotate(unsigned char c, int bits){
	printf("SRC: ");
	printBinaryUChar(c);
	unsigned char r = 0;
	if(bits)
		r = rotateRight(c);
	else
		r = rotateLeft(c);
	printf("\n");
	return r;
}

unsigned int fullMask(int i){
	unsigned int mask = !i ? -1 : (1 << intSize - i) - 1; 
	printf("Mask: ");
	printBinaryUInt(mask);
	return mask;
}

unsigned int reverseMask(int i){
	unsigned int mask = i==intSize ? (-1) : ~((-1)<<i);
	printf("Mask: ");
	printBinaryUInt(mask);
	return mask;
}

unsigned int customMask(int i, int k){
	unsigned int mask = k == intSize ? -1 : ((1 << k) - 1) << intSize - i - k;
	printf("Mask: ");
	printBinaryUInt(mask);
	return mask;
}

unsigned int extractMask(unsigned int x, int i, int k){
	printf("SRC: ");
	printBinaryUInt(x);
	//unsigned int r = (x&customMask(i,k))>>intSize-(i+k);
	unsigned int r = (x & fullMask(i)) >> intSize - (i + k);
	printf("EXT: ");
	printBinaryUInt(r);
	printf("\n");
	return r;	
}

int bits1(int n){
	printf("SRC: ");
	printBinaryInt(n);
	int i = 0;
	int count = 0;
	for (;i < (intSize-1);i++){ //Hasta 31, para no considerar el signo;
		unsigned int mask = (1<<i);
		int iBit = n & mask;
		if(iBit > 0)
			count++;
	}
	printf("CNT: %i \n", count);
	return count;
}

int int_Size(){
	int i = ~0;
	int count = 0;
	do{
		count++;
		i = i << 1;
		printf("i: %i \n", i);
	}while(i);
	printf("CNT: %i \n", count);
	return count;
}

int unset1(int n){
	printf("SRC: ");
	printBinaryInt(n);
	int i = 0;
	for(; i < sizeof(int)*8; i++){
		unsigned int mask = 1<<(intSize-i);	
		int masked = n&mask;
		if(masked){							
			int r = ~mask & n;
			printf("UST1: ");
			printBinaryInt(r);
			return r;
		}
	}
	return -1;
}

int sizeOfInt(){
	unsigned int f = ~0;
	int count=0;
	while(f){
		count++;
		f<<=1;
	}
	return count; //Alternativamente return count>>3;
}

int is64Bits(){
	return sizeof(long long)*8==64;
}

int isUnsignedChar(){
	char c = 0xFF;
	return (c>0);
}


unsigned int repBits(unsigned int x, int i, int k, unsigned int val){
	printf("src: ");
	printBinaryUInt(x);
	
	printf("val: ");
	printBinaryUInt(val);
	
	int intSize = sizeof(x)*8;
	
	//Construir la mascara:
	printf("intSize - i: %i \n", intSize-i-k);
	unsigned int mask = k==32 ? (-1) : (~((-1)<<k))<<(intSize-i-k);
	printf("Mask: ");
	printBinaryUInt(mask);
	
	unsigned int elim = x&~mask;
	printf("Elim: ");
	printBinaryUInt(elim);

	unsigned int r = elim + (val<<(intSize-i-k));
	printf("r: ");
	printBinaryUInt(r);
	
	return r;
}

int main()
{
	repBits(0x12345678, 0, 4, 0xf); //0xf2345678
	printf("\n");
	
	repBits(0x12345678, 4, 8, 0xaa); //0x1aa45678
	printf("\n");
	
	repBits(0x00000000, 31, 1, 1); //0x00000001
	printf("\n");
	
	repBits(0x89abcdef, 0, 32, 0x12345678); //
	printf("\n");
	
	// printf("SizeOfInt: %i \n", sizeOfInt());
	// printf("is64Bits: %i \n", is64Bits());
	// printf("isUnsignedChar: %i \n", isUnsignedChar());
	
	// reverseMask(4);
	// reverseMask(0);
	// reverseMask(31);
	// reverseMask(32);
	// printf("\n");
	
	// fullMask(28);
	// fullMask(32);	
	// fullMask(1);
	// fullMask(0);
	// printf("\n");
	
	// customMask(28,4);
	// customMask(0,0);
	// customMask(1,31);
	// customMask(0,32);
	// printf("\n");
	
	// printf("PBits: %i \n", posicionBits(8,2,2));
	// printf("PBits: %i \n", posicionBits(9,0,1));
	// printf("PBits: %i \n", posicionBits(5161651,59,6)); //14
	// printf("PBits: %i \n", posicionBits(5161651,0xFF,6)); //-1
	
	
	// printf("MSB: %i \n", bitMasSignificativo(0x1F));
	// printf("MSB: %i \n", bitMasSignificativo(0x3F));
	// printf("MSB: %i \n", bitMasSignificativo(0x1FFF));
	// printf("MSB: %i \n", bitMasSignificativo(0x0));
	// printf("MSB: %i \n", bitMasSignificativo(0x1));
	// printf("MSB: %i \n", bitMasSignificativo(0x007FFFFF));
	// printf("MSB: %i \n", bitMasSignificativo(0x01FFFFFF));
	// printf("MSB: %i \n", bitMasSignificativo(0x11FFFFFF));
	// printf("MSB: %i \n", bitMasSignificativo(0xFFFFFFFF));
	
	// unset1(0x70);
	// unset1(0);
	// unset1(1);
	// printf("\n");
	
	// int_Size();
	// printf("\n");
	
	// bits1(0x048b6048);
	// bits1(0xFFFFFFFF);
	// bits1(0x7FFFFFFF);
	// bits1(0x1);
	// printf("\n");
	
	// extractMask(0xFFFFFFFF,0,16);
	// extractMask(0xFFFFFFFF,1,30);
	// extractMask(0xFFFFFFFF,8,16);
	// extractMask(0xFFFFFFFF,0,0);
	// extractMask(0xFFFFFFFF,0,1);	
	// extractMask(0xFFFFFFFF,0,32);	
	// extractMask(0xFFFFFFFF,31,1);
	// extractMask(0xFFFFFFFF,32,0);
	// extractMask(0x048b6048,0,4);
	// extractMask(0x048b6048,8,12);
	// printf("\n");
	
	// rotate(1,1);	
	// rotate(2,1);	
	// rotate(3,1);	
	// rotate(11,1);	
	// printf("\n");
	
	// rotate(1,-1);	
	// rotate(2,-1);	
	// rotate(3,-1);	
	// rotate(11,-1);	
	// printf("\n");
	
	// printf("%i \n",abs(-1));
	// printf("%i \n",abs(-20));
	// printf("%i \n",abs(20));
	// printf("%i \n",abs(0));
	// printf("%i \n",abs(-0));
}