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

int main()
{
	unset1(0x70);
	unset1(0);
	unset1(1);
	printf("\n");
	
	int_Size();
	printf("\n");
	
	bits1(0x048b6048);
	bits1(0xFFFFFFFF);
	bits1(0x7FFFFFFF);
	bits1(0x1);
	printf("\n");
	
	extractMask(0xFFFFFFFF,0,16);
	extractMask(0xFFFFFFFF,1,30);
	extractMask(0xFFFFFFFF,8,16);
	extractMask(0xFFFFFFFF,0,0);
	extractMask(0xFFFFFFFF,0,1);	
	extractMask(0xFFFFFFFF,0,32);	
	extractMask(0xFFFFFFFF,31,1);
	extractMask(0xFFFFFFFF,32,0);
	extractMask(0x048b6048,0,4);
	extractMask(0x048b6048,8,12);
	printf("\n");
	
	rotate(1,1);	
	rotate(2,1);	
	rotate(3,1);	
	rotate(11,1);	
	printf("\n");
	
	rotate(1,-1);	
	rotate(2,-1);	
	rotate(3,-1);	
	rotate(11,-1);	
	printf("\n");
	
	printf("%i \n",abs(-1));
	printf("%i \n",abs(-20));
	printf("%i \n",abs(20));
	printf("%i \n",abs(0));
	printf("%i \n",abs(-0));
}