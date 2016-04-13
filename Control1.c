#include <stdio.h>

void printBinaryChar(unsigned char c){
	int i = 0;
	printf("%i: ",c);
	for(i=0; i<8; i++){
		printf("%i",(c&(1<<(7-i)))>>(7-i));
	}
	printf("\n");
}

void printBinary(unsigned int b){
	int i = 0;
	for(i=0; i<32; i++){
		printf("%i",b<<(31-i));
	}
	printf("\n");
}

int minus(int x){
	return 1+~x;
}

int isNeg(int x){
	return ((1<<31)&x)>>31;
}

int abs(int x){
	if(isNeg(x)) 
		return minus(x);
	else 
		return x;
}

unsigned char rotateLeft(unsigned char c){
	unsigned char mask = 1<<7;
	unsigned char msb = c&mask;
	printf("LFT: ");
	printBinaryChar((c<<1)+msb);
	return (c<<1)+msb;
}

unsigned char rotateRight(unsigned char c){
	unsigned char mask = 1;
	unsigned char lsb = c&mask;
	printf("RGT: ");
	printBinaryChar((c>>1)+(lsb<<7));
	return (c>>1)+(lsb<<7);
}

unsigned char rotate(unsigned char c, int bits){
	printf("SRC: ");
	printBinaryChar(c);
	if(bits>=0)
		return rotateRight(c);
	else
		return rotateLeft(c);
}

int main()
{
	rotate(1,0);	
	rotate(2,0);	
	rotate(3,0);	
	rotate(11,0);	
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