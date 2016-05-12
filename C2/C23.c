//Parejas en disco;
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define FALSE 0;
#define TRUE 1;

typedef struct nodo {
	char *nombre, *pareja;
	int listo;
	struct nodo *prox;
} Nodo;

void bailar_con(char * pareja){}

void alimentarse(){}

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

Nodo *mujeres; //Compartido;
Nodo *hombres; //Compartido;

void emparejar(char sexo, char *nombre, char *pareja){
	Nodo nodo;
	nodo.nombre = nombre;
	nodo.pareja = pareja;
	nodo.listo = FALSE;
	
	pthread_mutex_lock(&m);
	if(sexo=='m'){
		if(mujeres != NULL){
			strcpy(pareja, mujeres->nombre);
			strcpy(mujeres->pareja, nombre);
			mujeres->listo = TRUE;
			mujeres = mujeres->prox;
		}
		else{
			nodo.prox = hombres;
			hombres = &nodo;
			while(!nodo.listo)
				pthread_cond_wait(&cond,&m);
		}
	}
	else{
		if(hombres != NULL){
			strcpy(pareja, hombres->nombre);
			strcpy(hombres->pareja, nombre);
			hombres->listo = TRUE;
			hombres = hombres->prox;
		}
		else{
			nodo.prox = mujeres;
			mujeres = &nodo;
			while(!nodo.listo)
				pthread_cond_wait(&cond,&m);
		}
	}
	pthread_cond_broadcast(&cond);
	pthread_mutex_unlock(&m);
}

void hombre(char *nombre){
	for(;;){
		char pareja[100];
		emparejar('m', nombre, pareja);
		bailar_con(pareja);
		alimentarse();
	}
}

void mujer(char *nombre){
	for(;;){
		char pareja[100];
		emparejar('f', nombre, pareja);
		bailar_con(pareja);
		alimentarse();
	}
}

int main(int argc, char* argv[]){
	hombres = (Nodo*)malloc(sizeof(Nodo));
	mujeres = (Nodo*)malloc(sizeof(Nodo));	
}
