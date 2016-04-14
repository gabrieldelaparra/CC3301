#include <stdio.h>

int y = 20;

int noReturn(){
	
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

int main()
{
	desreferencia();
	// printf("y: %i \n",y); 
	// y=10; //Probando si se le puede asignar algo a una variable global. Si se puede.
	// printf("y: %i \n",y);
	// printf("\n");
	
	// printf("noReturn(): %i \n", noReturn()); //regresa 7; Cambio a 24;
	// printf("\n");
	
	// int *p;
	// int a;

	// printf("unassigned p: %i \n",p); //es la dirección de p;
	// printf("unassigned *p: %i \n",*p); //es el valor al que apunta p;
	// printf("unassigned &p: %i \n",&p); //es la dirección del puntero *p
	// printf("\n");
	
	// printf("unassigned a: %i \n",a);
	// printf("//unnasigned *a: //error: invalid type argument of unary '*' (have 'int')\n"); //error: invalid type argument of unary '*' (have 'int')
	// printf("unassigned &a: %i \n",&a);
	// printf("\n");
	
	
	// a = 30;
	// printf("assigned a=30, a: %i \n",a);
	// printf("//unnasigned *a: //error: invalid type argument of unary '*' (have 'int')\n"); //error: invalid type argument of unary '*' (have 'int')
	// printf("assigned &a: %i \n",&a); //&a es la dirección de p;
	// printf("\n");
	
	// p = (int*)10;
	// printf("assigned p=(int*)10: %i \n",p); //es la dirección de p;
	// printf("//assigned *p:  Error, se cerro la aplicacion, probablemente por intentar leer memoria fuera de alcance;\n"); //es el valor al que apunta p; //Error, se cerró la aplicación, probablemente por intentar leer memoria fuera de alcance;
	// printf("assigned &p: %i \n",&p); //es la dirección del puntero *p; se mantujo igual;
	// printf("\n");
	
	// p=&a;
	// printf("assigned p=&a: %i \n",p); //es la dirección de p;
	// printf("assigned *p: %i \n",*p); //es el valor al que apunta p, en este caso, el valor de a;
	// printf("assigned &p: %i \n",&p); //es la dirección del puntero *p; se mantujo igual de nuevo. En general &p no cambia, es la dirección del int* p;
}