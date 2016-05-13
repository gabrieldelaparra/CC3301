//Pizzeria
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define STACK_MAX 100

typedef struct {
    void*     data[STACK_MAX];
    int     size;
} Stack;

void Stack_Init(Stack *S)
{
	S = (Stack *)malloc(sizeof(S));
    S->size = 0;
}

int Stack_Empty(Stack *S){
	return S->size;
}

void* Stack_Top(Stack *S)
{
    if (S->size == 0) {
        fprintf(stderr, "Error: stack empty\n");
        return NULL;
    } 

    return S->data[S->size-1];
}

void Stack_Push(Stack *S, void *d)
{
    if (S->size < STACK_MAX)
        S->data[S->size++] = d;
    else
        fprintf(stderr, "Error: stack full\n");
}

void Stack_Pop(Stack *S)
{
    if (S->size == 0)
        fprintf(stderr, "Error: stack empty\n");
    else
        S->size--;
}

typedef char Ingredientes;
typedef char Pizza;
typedef Stack *Cola;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

typedef struct {
	Ingredientes *ingr;
	Pizza *pizza;
	int fin;
} Orden;

Stack *cola;
pthread_t operador;



Orden *ordenar(Ingredientes *ingr){
	Orden *o = malloc(sizeof(*o));
	o->ingr = ingr;
	o->fin = 0;
	printf("agregar a cola\n");
	pthread_mutex_lock(&m);
	Stack_Push(cola,(void*)o);
	pthread_cond_broadcast(&cond);
	pthread_mutex_unlock(&m);
	return o;
}

void *ord(void *p){
	ordenar((Ingredientes *)p);
	return NULL;
}

Pizza *pizzaCruda(Ingredientes *ingr){
	return (Pizza*)ingr;
}

void hornear(Pizza *pizzas[]){
	printf("Hornear pizzas");
}

void *pizzeria(void *p){
	pthread_mutex_lock(&m);
	for(;;){
		Pizza *pizzas[4];
		Orden *ords[4];
		printf("Cola: %d\n", Stack_Empty(cola));
		while(Stack_Empty(cola))
			printf("Cola: %d\n", Stack_Empty(cola));
			pthread_cond_wait(&cond, &m);
		int i = 0, j;
		while(!Stack_Empty(cola) && i<4){
			ords[i] = (Orden *)Stack_Top(cola);
			pizzas[i] = pizzaCruda(ords[i]->ingr);
			i++;
		}
		pthread_mutex_unlock(&m);
		
		hornear(pizzas); //lento
		
		pthread_mutex_lock(&m);
		for(j = 0;j<i;j++){
			ords[i]->fin=1;
			ords[i]->pizza = pizzas[i];
		}
		pthread_cond_broadcast(&cond);
	}
}

Pizza *retirar(Orden *o){
	pthread_mutex_lock(&m);
	while (!o->fin)
		pthread_cond_wait(&cond,&m);
	pthread_mutex_unlock(&m);
	return o->pizza;
}

void initHorno(){
	Stack_Init(cola);
	pthread_create(&operador, NULL, pizzeria, NULL);
}

int main(int argc, char *argv[]){
	initHorno();
pthread_t t1;
pthread_t t2;
// pthread_t t3;
// pthread_t t4;
pthread_create(&t1,NULL,ord,(void *)'i');
pthread_create(&t2,NULL,ord,(void *)'a');
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}