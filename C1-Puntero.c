#include <stdio.h>
#include <stdlib.h>
int y = 20;

int arrayTest(){
	int *p = malloc(10*sizeof(int));
	
	int s = 0;
	int i;
	for(i=0;i<10;i++)
		*(p+i) = i*i;
	for(i=0;i<10;i++)
		printf("p[%i]: %d",i,*(p+i));
}

int main()
{
	arrayTest();
	
	// int* p = intMalloc();
	// printf("p: %i\n", *p);
	// free(p);
	// printf("p: %i\n", *p); //Cualquier cosa;
	
	// swapPtrs();
	// swapDoubles();
	// swapInts();
	// desreferencia();
	// basicoPunteros();
	// basico();
}

int* intMalloc()
{
	int *q = malloc(sizeof(int));
	*q = 2;
	printf("q: %i\n",*q);
	return q;
}


void swapPtrVal(int** ppa, int** ppb){
	int temp = **ppa;
	**ppa = **ppb;
	**ppb = temp;
}

void swapPtr(int** ppa, int** ppb){
	int *temp = *ppa;
	*ppa = *ppb;
	*ppb = temp;
}

void swapPtrs(){
	int a = 1, b = 2;
	int* pa = &a;
	int* pb = &b;
	printf("a: %i \n",a);
	printf("b: %i \n",b);
	printf("pa: %i \n",pa);
	printf("pb: %i \n",pb);
	printf("*pa: %i \n",*pa);
	printf("*pb: %i \n",*pb);

	printf("\nswapPtr(&pa, &pb);\n");
	swapPtr(&pa, &pb);
	printf("a: %i \n",a);
	printf("b: %i \n",b);
	printf("pa: %i \n",pa);
	printf("pb: %i \n",pb);
	printf("*pa: %i \n",*pa);
	printf("*pb: %i \n",*pb);

	printf("\nswapPtrVal(&pa, &pb);\n");
	swapPtrVal(&pa,&pb);
	printf("a: %i \n",a);
	printf("b: %i \n",b);
	printf("pa: %i \n",pa);
	printf("pb: %i \n",pb);
	printf("*pa: %i \n",*pa);
	printf("*pb: %i \n",*pb);
	printf("\n");
}

void swapDoubleP(double *a, double *b){
	double temp = *a;
	*a = *b;
	*b = temp;
}

void swapDoubles(){
	double a = 1.1;
	double b = 2.7;
	printf("a %%f: %f \n",a);
	printf("b %%f: %f \n",b);
	
	printf("a %%g: %g \n",a);
	printf("b %%g: %g \n",b);
	
	printf("a %%e: %e \n",a);
	printf("b/%%e: %e \n",b);
	printf("\nswapDoubleP(&a,&b);: \n");
	swapDoubleP(&a,&b);
	printf("a: %f \n",a);
	printf("b: %f \n",b);
	printf("\n");
}

void swapInt(int a, int b){
	int temp = a;
	a = b;
	b = temp;
}

void swapIntP(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swapInts(){
	int a = 1;
	int b = 2;
	printf("a: %i \n",a);
	printf("b: %i \n",b);
	printf("\nswapInt(a,b);: \n");
	swapInt(a,b);
	printf("a: %i \n",a);
	printf("b: %i \n",b);
	printf("\nswapIntP(&a,&b);: \n");
	swapIntP(&a,&b);
	printf("a: %i \n",a);
	printf("b: %i \n",b);
	printf("\n");
}

int noReturn(){
	
}

void basico(){
	printf("y: %i \n",y); 
	y=10; //Probando si se le puede asignar algo a una variable global. Si se puede.
	printf("y: %i \n",y);
	printf("\n");
	
	printf("noReturn(): %i \n", noReturn()); //regresa 7; Cambio a 24;
	printf("\n");
}

void basicoPunteros(){

	
	int *p;
	int a;

	printf("unassigned p: %i \n",p); //es la dirección de p;
	printf("unassigned *p: %i \n",*p); //es el valor al que apunta p;
	printf("unassigned &p: %i \n",&p); //es la dirección del puntero *p
	printf("\n");
	
	printf("unassigned a: %i \n",a);
	printf("//unnasigned *a: //error: invalid type argument of unary '*' (have 'int')\n"); //error: invalid type argument of unary '*' (have 'int')
	printf("unassigned &a: %i \n",&a);
	printf("\n");
	
	
	a = 30;
	printf("assigned a=30, a: %i \n",a);
	printf("//unnasigned *a: //error: invalid type argument of unary '*' (have 'int')\n"); //error: invalid type argument of unary '*' (have 'int')
	printf("assigned &a: %i \n",&a); //&a es la dirección de p;
	printf("\n");
	
	p = (int*)10;
	printf("assigned p=(int*)10: %i \n",p); //es la dirección de p;
	printf("//assigned *p:  Error, se cerro la aplicacion, probablemente por intentar leer memoria fuera de alcance;\n"); //es el valor al que apunta p; //Error, se cerró la aplicación, probablemente por intentar leer memoria fuera de alcance;
	printf("assigned &p: %i \n",&p); //es la dirección del puntero *p; se mantujo igual;
	printf("\n");
	
	p=&a;
	printf("assigned p=&a: %i \n",p); //es la dirección de p;
	printf("assigned *p: %i \n",*p); //es el valor al que apunta p, en este caso, el valor de a;
	printf("assigned &p: %i \n",&p); //es la dirección del puntero *p; se mantujo igual de nuevo. En general &p no cambia, es la dirección del int* p;
}

void desreferencia(){
	int v = 20;
	int w;
	int *p;
	
	p=&v;
	printf("assigned p=&v: %i \n",p); 
	printf("unassigned w: %i \n",w); 
	w=*p; //w=v;)
	printf("assigned w=*p: %i \n",w); 
	*p=30; //v=30;
	printf("assigned *p=30: %i \n",*p); 
	printf(" p: %i \n",p); //dirección de v;
	printf("&v: %i \n",&v);
	printf(" w: %i \n",w);
	printf(" v: %i \n",v);
	
	p=&w;
	*p=40; //w=40;
	printf(" p=&w, p: %i \n",p); //dirección de w;
	printf("*p=40, w: %i \n",w);
	printf(" v: %i \n",v);
	
	printf(" w: %i \n",w);
}

