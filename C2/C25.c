//char *swap(char *s);
#include <pthread.h> //pthread;
#include <stdio.h> //printf;
#include <stdlib.h> //malloc;
#include <string.h> //strlen, strcpy;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

typedef struct {
	char *s1;
	char *s2;
	int c;
} SWAP;

SWAP *S = NULL;

void initialize(){
	printf("init\n");
	S = (SWAP*) malloc(sizeof(SWAP));
	S->c = 0;
}

char *swap (char *s){
	printf("s:%s\n",s);	
	pthread_mutex_lock(&m);
	if(S->c%2 == 0){ //No hay nadie esperando;
		printf("C:%d\n",S->c);
		S->s1 = (char*)malloc(sizeof(strlen(s)+1));
		strcpy(S->s1,s);
		S->c++;
		while(S->c%2 != 0){
			pthread_cond_wait(&cond, &m);
		}
		pthread_mutex_unlock(&m);
		return S->s2;
	}
	else { //Alguien está esperando;
		printf("C:%d\n",S->c);
		S->s2 = (char*)malloc(sizeof(strlen(s)+1));
		strcpy(S->s2,s);
		S->c++;
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&m);
		return S->s1;
	}
	return NULL;
}

void *cmp(void *p){
	char *a = (char *)p;
	printf("a: %s Swap: %s \n",a, swap(a)); 
	return NULL;
}

int main(int argc, char *argv[]){
	printf("Main\n");
	initialize();
	pthread_t t1;
	pthread_t t2;
	pthread_t t3;
	pthread_t t4;
	pthread_create(&t1, NULL, cmp, "oro");
	pthread_create(&t2, NULL, cmp, "plata");
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_create(&t3, NULL, cmp, "hierro");
	pthread_create(&t4, NULL, cmp, "magnesio");
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
}