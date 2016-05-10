#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#include "reserva.h"

typedef struct{
	char **P;
	pthread_mutex_t m;//= PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t cond;// = PTHREAD_COND_INITIALIZER;
} Est;

Est *E = NULL;

void myInit(){
	if(E == NULL){
		E = (Est*)malloc(sizeof(Est));
		pthread_mutex_init(&E->m, NULL);
		pthread_cond_init(&E->cond, NULL);
		E->P = (char**)malloc(5*sizeof(char*));
	}
}

int ubicar(char *nom, int k){
	myInit();
	int f = -1;
	int c = 0;
	for(int i=0; i<5; i++){
		if(E->P[i]==NULL){
			c++;
			if(c==k){
				f=i+1-c;
				return f;
			}
		}
		else {
			c=0; f=-1;
		}
	}
	return f;
}

int reservar(char *nom, int k){
	myInit();
	
	pthread_mutex_lock(&E->m);
	int p = ubicar(nom,k);
	//Ojo con los paréntesis, el while(p = ubicar(nom,k) == -1) daba siempre p=0;
	while((p = ubicar(nom,k)) == -1){ 
		pthread_cond_wait(&E->cond,&E->m);
	}
	
	for(int i = 0; i<k;i++){
		// printf("MALLOC p+i: %d\n",p+i);
		E->P[p+i] = (char*)malloc(strlen(nom)+1); //+1 por el final del string;
		strcpy(E->P[p+i], nom);
		// E->P[p+i] = nom;
	}
	pthread_cond_broadcast(&E->cond);
	pthread_mutex_unlock(&E->m);
	return p;
}

void liberar(char *nom){
	pthread_mutex_lock(&E->m);
	for(int i=0; i<5;i++){
		if(E->P[i] != NULL){
			if(strcmp(E->P[i],nom)==0){
				// printf("FREE: %d\n",i);	
				free(E->P[i]); //Con free(E->P[i]), crashea.
				E->P[i] = NULL; //Esto funciona, pero no es lo deseado !
			}
		}
	}	
	pthread_cond_broadcast(&E->cond);
	pthread_mutex_unlock(&E->m);
}

void printE(){
	for(int i=0;i<5;i++){
		printf("[%s]",E->P[i]); //NULL x 5
	}
	printf("\n");
}
/* Implemente aca las funciones reservar y liberar */
