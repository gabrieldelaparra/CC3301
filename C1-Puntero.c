#include <stdio.h>

int v = 20;

int noReturn(){
	
}

int main()
{
	v=10; //probando si se le puede asignar algo a una variable global. Si se puede.
	printf("v: %i \n",v);
	
	printf("noReturn(): %i", noReturn()); //regresa 7;
}