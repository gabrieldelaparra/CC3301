#include <stdio.h>

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
	int mask = 1<<7;
	int msb = c&mask;
	return c<<1+msb;
}

unsigned char rotateRight(unsigned char c){
	int mask = 1;
	int lsb = c&mask;
	return c>>1+lsb<<7;
}

unsigned char rotate(unsigned char c, int bit){
	if(bits>0)
		return rotateRight)(c);
	else
		return rotateLeft(c);
}

void printBinary(unsigned int b){
	int i = 0;
	for(i=0; i<32; i++){
		printf("%i",b<<(31-i));
	}
	printf("\n");
}

void printBinaryChar(unsigned char c){
	int i = 0;
	for(i=0; i<8; i++){
		printf("%i",b<<(7-i));
	}
	printf("\n");
}

int main()
{
	

	printBinaryChar(rotate(1),0);	
	printBinaryChar(rotate(2),0);	
	printBinaryChar(rotate(3),0);	
	printBinaryChar(rotate(11),0);	
	
	printBinaryChar(rotate(1),-1);	
	printBinaryChar(rotate(2),-1);	
	printBinaryChar(rotate(3),-1);	
	printBinaryChar(rotate(11),-1);	
	
	printf("%i \n",abs(-1));
	printf("%i \n",abs(-20));
	printf("%i \n",abs(20));
	printf("%i \n",abs(0));
	printf("%i \n",abs(-0));
}