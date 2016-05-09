#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char **P;
	pthread_mutex_t m;
	pthread_cond_t cond;
} Est;

Est *E = NULL;

int ubicar(char *nom, int k){
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
	pthread_mutex_lock(&E->m);
	int p = ubicar(nom,k);
	//Ojo con los paréntesis, el while(p = ubicar(nom,k) == -1) daba siempre p=0;
	while((p = ubicar(nom,k)) == -1){ 
		pthread_cond_wait(&E->cond,&E->m);
	}
	
	for(int i = 0; i<k;i++){
		E->P[p+i] = malloc(strlen(nom));
		E->P[p+i] = nom;
	}
	pthread_cond_broadcast(&E->cond);
	pthread_mutex_unlock(&E->m);
	return p;
}

void liberar(char *nom){
	for(int i=0; i<5;i++){
		if(E->P[i] == nom){
			printf("FREE: %d\n",i);	
			// free(E->P[i]); //Si pongo un free(E->P[i]), crashea.
			E->P[i] = NULL; //Esto funciona pero no es lo deseado !
		}
	}	
}

void printE(){
	for(int i=0;i<5;i++){
		printf("[%s]",E->P[i]); //NULL x 5
	}
	printf("\n");
}

int main(){
	E = malloc(sizeof(Est));
	E->m = PTHREAD_MUTEX_INITIALIZER;
	E->cond = PTHREAD_COND_INITIALIZER;
	E->P = malloc(5*sizeof(char*));

	printE();
	
	int a = reservar("nom",3);
	printf("%d\n",a);	
	printE();
	
	a = reservar("nom2",2);
	printf("%d\n",a);
	
	printE();
	
	//!!
	liberar("nom");
	
	printE();
	
	a = reservar("nom3",1);
	printf("%d\n",a);	
	printE();	
	
	a = reservar("nom4",1);
	printf("%d\n",a);	
	printE();	
	
	a = reservar("nom5",1);
	printf("%d\n",a);	
	printE();	
}