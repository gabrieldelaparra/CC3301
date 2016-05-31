#include <pthread.h> //pthread;
#include <stdio.h> //printf;
#include <stdlib.h> //malloc;

#include "reunion.h"

struct reunion {
	pthread_mutex_t *m;
	pthread_cond_t *cond;
	int count;
};

Reunion *nuevaReunion(){
	Reunion *r = (Reunion*)malloc(sizeof(r));
	r->m = malloc(sizeof(pthread_mutex_t));	
	pthread_mutex_init(r->m, NULL);
	r->cond = malloc(sizeof(pthread_cond_t));
	pthread_cond_init(r->cond, NULL);
	r->count = 0;
	return r;
}

void entrar(Reunion *r){
	pthread_mutex_lock(r->m);
	r->count++;	
	pthread_mutex_unlock(r->m);
}

void concluir(Reunion *r){	
	pthread_mutex_lock(r->m);	
	r->count--;	
	pthread_cond_broadcast(r->cond);	
	while(r->count > 0){ 
		pthread_cond_wait(r->cond,r->m);
	}
	pthread_mutex_unlock(r->m);
}



