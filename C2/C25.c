//char *swap(char *s);
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

typedef struct {
	char *s1;
	char *s2;
	int c;
} SWAP;

SWAP *S = NULL;

void initialize(){
	printf("init");
	S = (SWAP*) malloc(sizeof(SWAP));
	S->c = 0;
}

char *swap (char *s){
	printf("s:%s",s);
	pthread_mutex_lock(&m);
	if(S->c%2 == 0){ //No hay nadie esperando;
		S->s1 = (char*)malloc(sizeof(strlen(s)+1));
		strcpy(S->s1,s);
		S->c++;
		while(S->c%2 != 0){
			pthread_cond_wait(&cond, &m);
		}
		pthread_mutex_unlock(&m);
		return S->s2;
	}
	else //Alguien está esperando;
	{
		S->s2 = (char*)malloc(sizeof(strlen(s)+1));
		strcpy(S->s2,s);
		S->c++;
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&m);
		return S->s2;
	}
	return NULL;
}

int main(int argc, char *argv[]){
	initialize();
	char a[5] = {'h','o','l','a',0};
	char *b = (char*)malloc(5);
	strcpy(b,"chao");
	printf("a: %s",a);
	printf("b: %s",b);
	b = swap(a);
	printf("a: %s",a);
	printf("b: %s",b);
}