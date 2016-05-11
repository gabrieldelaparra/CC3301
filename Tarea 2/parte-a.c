#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <math.h>

typedef int (*Comparador)(void *a, int k, void *x);

int c=0;

void printArray(char **a, int n){
	printf("\nArray: \n");
	for(int i = 0; i<n;i++){
		printf("Item: %s\n",a[i]);
	}
}

int buscar(void *a, int n, void *x, Comparador cmp){
	int p = c + (n-1)/2;
	int comp = (*cmp)(a,p,x);
	
	// printf("Search: %s Comp: %d N: %d P: %d C: %d \n",(char*)x,comp,n,p,c);
	// printArray((char**)a,n);
	
	// printf(" --- \n");
	//Invariante: Si el largo del arreglo es 1 y no es igual a ese valor, retorna -1;
	if(n==0 && comp!=0){ 
	// printf("NotFound! \n");
		c=0;
		return -1;
	}
	
	//Caso 1: Si en la comparación con el valor del medio, son iguales, retorna el valor del medio;
	if(comp == 0){
	// printf("Found! \n");
		c=0;
		return p;
	}
	
	//Caso 2: Si en la comparación con el valor del medio, es menor, 
	//aplica recursiva con la mitad inferior del arreglo, sumando el carry c;
	else if(comp > 0){
		// printf("<<LH \n");
		int b = buscar(a,n/2,x,cmp);		
		return c+b;
	}
	
	//Caso 3: Si en la comparación con el valor del medio, es mayor, 
	//aplica recursiva con la mitad superior del arreglo, sumando el carry c;
	else {
		if(n/2==0)
			c++;
		// printf(">>RH Add(c,%d) \n",c + n/2);
		
		c = c + (n/2);
		int b = buscar(a,n/2,x,cmp);
		if(b == -1) 
			return -1;
		return c+b;
	}
}
