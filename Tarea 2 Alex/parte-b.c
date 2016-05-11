#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "t2.h"

char *consultar(char *nom_dic, char *pal, int n_lin){
	
	FILE *file = fopen(nom_dic, "r");

	int res;

	res = buscar(file, n_lin, pal, cmpDic);

	if(res == -1){
		return NULL;
	}

	return definicion(file, res);
}

int cmpDic(void *a, int k, void *x){
	/* comparador que determina si la palabra x esta en la fila x del archivo a */
	fseek((FILE*)a, k*80 , SEEK_SET);

	int i = 0;
	char linea[80];
	char *pal = (char*)x;
	fread(linea, 1, 80, (FILE*)a);
	char palabra[80]="";

	while(*(linea + i) != ':'){
		*(palabra+i) = *(linea+i);
		i++;
	}

	return strcmp(palabra, pal);
}

char *definicion(FILE *file, int n){
	/* entrega la parte que corresponde a la definicion de la linea n del archivo file */
	fseek(file, n*80 , SEEK_SET);

	int i = 0;
	char *linea = malloc(80*sizeof(char));
	char *aux = linea;
	char *ret = malloc(80*sizeof(char));
	fread(linea, 1, 80, file);

	while(*linea != ':'){
		linea++;
	}

	linea++;

	while (*(linea+i) != ':'){
		i ++;
	}

	*(linea+i)=0;

	strcpy(ret, linea);
	free(aux);

	return ret;
}