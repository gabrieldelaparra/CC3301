#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nodo{
	char c;
	struct nodo *izq, *der;		
} Nodo;

void printNodo(Nodo *a){
	if(a==NULL)return;
	printf("Nodo: %c I: %c D: %c\n",a->c, a->izq==NULL ? '-' : (a->izq)->c, a->der==NULL ? '-' : (a->der)->c);
	printNodo(a->izq);
	printNodo(a->der);
}	
	
int k_primeros(Nodo **pa, int k){
	printNodo(*pa);
	printf("k:%i\n",k);
	
	Nodo *a = *pa;
	if(k==0){
		*pa=NULL;
	}
	else if(a==NULL)
	{
		printf("hoja\n");
		return 1;
	}
	else 
	{
		k=k-k_primeros(&a->izq,k);
		*pa = a->izq;
		if(k>0 && a->der != NULL){
			k = k-k_primeros(&a->der,k);
		}
	}
	return k;
}

int main(){
	Nodo nt = {'t',NULL,NULL};
	Nodo nu = {'u',&nt,NULL};
	Nodo nr = {'r',NULL,NULL};
	Nodo ns = {'s',&nr,&nu};
	Nodo nw = {'w',NULL,NULL};
	Nodo nx = {'x',NULL,&nw};
	Nodo nv = {'v',&ns,&nx};
	
	
	// Nodo nu = {'u',&nt,NULL};
	Nodo *tree = &nv;
	printNodo(tree);
	printf("\n");
	
	int kk = k_primeros(&tree,3);
	printf("kk: %i\n",kk);
	printNodo(tree);
}