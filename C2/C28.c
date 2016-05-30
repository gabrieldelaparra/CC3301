// caja isapre

#include <pthread.h> //pthread;
#include <stdio.h> //printf;
#include <stdlib.h> //malloc;
#include <string.h> //strlen, strcpy;
#include <unistd.h> //sleep;

#define FALSE 0
#define TRUE 1
#define N 2

typedef struct {
	char *id;
	int isDisponible;
} Caja;

Caja *cajas[N];

pthread_t *empleados[N];

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void inicializar(){
	for (int i = 0; i<N;i++){
		cajas[i] = (Caja *) malloc(sizeof(Caja));
		cajas[i]->isDisponible = FALSE;
	}
	cajas[0]->n = {'A',0};
	cajas[1]->n = {'B',0};
	cajas[2]->n = {'C',0};
	cajas[3]->n = {'D',0};
	cajas[4]->n = {'E',0};
	cajas[5]->n = {'F',0};
	cajas[6]->n = {'G',0};
	cajas[7]->n = {'H',0};
}

void *cobrar(void *ptr){
	// char c = (Caja)ptr;
	for(;;){
		pthread_mutex_lock(&m);
		while(isEmpty(cola)){
			pthread_cond_wait(&cond,&m);
		}
		
		
		
	}
}

int getCajaDisponible(){
	int j = -1;
	for(int i = 0;i<N;i++){
		if(cajas[i]->isDisponible == TRUE)
			return j;
	}
	return j;
}

char *solicitar_caja(){
	int p = getCajaDisponible();
	while(p != -1){
		pthread_cond_wait(&cond,&m);
		p = getCajaDisponible();
	}
	return cajas[p]->id;
}

int main(int argc, char *argv[]){
	inicializar();
}
