//compartir, primavera 2013;

#include <pthread.h> //pthread;
#include <stdio.h> //printf;
#include <stdlib.h> //malloc;
#include <string.h> //strlen, strcpy;
#include <unistd.h> //sleep;

#define FALSE 0
#define TRUE 1

int count = 0;
int isDisponible = FALSE;
void *p;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void compartir(void *ptr){
	printf("Compartir...\n");
	pthread_mutex_lock(&m);
	if(count==0){
		pthread_mutex_unlock(&m);
		printf("...NADIE PARA COMPARTIR\n");
		return;
	}
	else{
		//CopiarPTRaEspacioComun(ptr); // p = ptr;
		isDisponible=TRUE;
		pthread_cond_broadcast(&cond);		
	}
	pthread_mutex_unlock(&m);
	
	pthread_mutex_lock(&m);
	while(count!=0){
		printf("WAIT DEVOLVER\n");
		pthread_cond_wait(&cond, &m);
	}
	//SacarPTRdeEspacioComun(); // p = NULL;
	printf("DEVOLVIO\n");
	isDisponible=FALSE;
	pthread_mutex_unlock(&m);
	printf("...Compartir\n");
}

void *acceder(){
	printf("Acceder...\n");
	pthread_mutex_lock(&m);
	count++;
	while(isDisponible==FALSE){
		printf("WAIT ACCEDER\n");
		pthread_cond_wait(&cond, &m);
	}
	sleep(1); //read(p);
	
	printf("ACCEDIO\n");
	pthread_mutex_unlock(&m);
	printf("...Acceder\n");
	return NULL;
}

void devolver(){
	printf("Devolver...\n");
	pthread_mutex_lock(&m);
	count--;	
	pthread_cond_broadcast(&cond);
	pthread_mutex_unlock(&m);
	printf("...Devolver\n");
}

void *comp(void *pt){
	compartir(pt);
	return NULL;
}

void *acc(void *pt){
	acceder();
	return NULL;
}

void *dev(void *pt){
	devolver();
	return NULL;
}

int main(int argc, char *argv[]){
	pthread_t t1;
	pthread_t t2;
	pthread_t t3;
	pthread_t t4;
	
	// pthread_create(&t1,NULL,comp,NULL); printf("compartir t1\n");
	
	pthread_create(&t4,NULL,acc,NULL); printf("Acceder t4\n");
	pthread_create(&t3,NULL,acc,NULL); printf("Acceder t3\n");
	pthread_create(&t1,NULL,comp,NULL); printf("compartir t1\n");
	pthread_create(&t2,NULL,acc,NULL); printf("Acceder t2\n");
	
	pthread_create(&t4,NULL,dev,NULL); printf("Devolver t4\n");
	pthread_create(&t2,NULL,dev,NULL); printf("Devolver t2\n");
	pthread_create(&t3,NULL,dev,NULL); printf("Devolver t3\n");

	pthread_join(t4,NULL);
	pthread_join(t3,NULL);
	pthread_join(t2,NULL);
	pthread_join(t1,NULL);
	
}