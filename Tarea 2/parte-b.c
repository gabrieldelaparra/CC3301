#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "t2.h"

int cmp_nombres(void *a, int k, void *x) {
  char **nombres= a, *nom= x;
  int str =  strcmp(nombres[k], nom);
  return str;
}

int buscar_nombre(char **nombres, int n, char *nom) {
  return buscar(nombres, n, nom, cmp_nombres);
}

char **getWords(char *nom_dic, int n_lin){
	FILE *file = fopen(nom_dic, "r");
	
	char **arr = malloc(n_lin* sizeof(char *));
	if (arr)
	{
	  for (int i = 0; i < n_lin; i++)
	  {
		fseek(file, i*ANCHO,SEEK_SET);
		int j = 0;
		int colon = 0;
		while(colon != (int)':'){
			j++;
			colon = fgetc(file);			  
		}
		//printf("Alloc: %d ", j);
		arr[i] = malloc(j);
		
		fseek(file, i*ANCHO,SEEK_SET);
		for(int k = 0; k < j-1;k++){
			arr[i][k] = 0;
			arr[i][k] = fgetc(file);
		}
		arr[i][j-1] = 0;
		//printf("%s \n", arr[i]);
	  }
	}
	fclose(file);
	//printf("\n");
	return arr;
}

char *consultar(char *nom_dic, char *pal, int n_lin){

	char **arr = getWords(nom_dic, n_lin);
	FILE *file = fopen(nom_dic, "r");
	char *ret;
	int line = buscar_nombre(arr,n_lin,pal);
	//printf("Found: %s Pos: %d\n ### \n",pal, line);
	
	if(line != -1){
		int firstColon = (line)*ANCHO + strlen(pal)+1;
		fseek(file, firstColon,SEEK_SET);
		//printf("firstColon: %d\n",firstColon);
		
		int j = 0;
		int colon = 0;
		while(colon != (int)':'){
			j++;
			colon = fgetc(file);			  
		}
		
		ret = malloc(j);
		
		fseek(file, firstColon,SEEK_SET);
		for(int k = 0; k < j-1;k++){
			ret[k] = 0;
			ret[k] = fgetc(file);
		}
		ret[j-1] = 0;
		//printf("Ret: %s\n",ret);		
		fclose(file);
		return ret;
	}
	
	fclose(file);
	//printf("Ret: NULL\n");
	
	return NULL;
}
