#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char E;
	pthread_mutex_t m;
	pthread_cond_t cond;
} Est;

int main(){
	
}