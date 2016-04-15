#include <stdio.h> //printf
#include <stdlib.h> //malloc
#include <string.h> //strings



void basic(){
	char *s = "chao";
	char r[] = {'h','o','l','a',0};
	char t[5] = {0};
	
	printf("s: %s \n",s);
	printf("r: %s \n",r);
	printf("t: %s \n",t);
	printf("\n");

	printf("Cambio r[0]\n");
	//s[0] = 'H'; //SegFault, cierra el programa;
	r[0] = 'H';
	printf("r[0] = H: %s \n",r);
	
	printf("\n");
}

int length(char* s){ //Entra un puntero de chars que apunta a un arreglo;
	int count = 0;
	while(*s != 0){
		*s++;
		count++;
	}
	return count;
}

char* copy(char* d, char* s){
	int i =0;
	while(*s != 0)
	{
		d[i] = s[i];
		i++;
	}
	return d;
}

char* copyN(char* d, char* s, int l)
{
	int i = 0;
	for(i=0;i<l;i++){
		d[i]=s[i];
	}
	return d;
}

void funciones(){
	char *s = "chao";
	char r[] = {'h','o','l','a',0};
	char t[5] = {0};
	
	int sLen = strlen(s);
	int rLen = strlen(r);
	int tLen = strlen(t);
	printf("sLen: %d\n",sLen); //4
	printf("rLen: %d\n",rLen); //4
	printf("tLen: %d\n",tLen); //0
	printf("\n");
	
	printf("StrCpy(t,s):\n");
	copy(t,s);
	printf("t: %s \n",t);
	tLen = length(t);
	printf("tLen: %d\n",tLen); //4
	printf("\n");
	
	printf("StrNCpy(t,r,2):\n");
	copyN(t,r,2);
	printf("t: %s \n",t); //Queda con los dos caracteres finales de hola, se superpone lo que había copiado anteriormente;
	tLen = length(t);
	printf("tLen: %d\n",tLen); //4
	printf("\n");
	
	printf("Vaciar t\n"); //Los strings se vacían con 0s;
	int i = 0;
	for(i=0; i<tLen;i++){
		t[i]=0;
	}
	printf("t: %s \n",t);
	tLen = length(t);
	printf("tLen: %d\n",tLen); //0
	printf("\n");
	
	printf("StrNCpy(t,r,2):\n");
	copyN(t,r,2);
	printf("t: %s \n",t); 
	tLen = length(t);
	printf("tLen: %d\n",tLen); //2
	printf("\n");
	
	printf("StrCat(t,r + """ """ +s)\n");
	copyN(t,r,4);
	strcat(t," ");
	strcat(t,s);
	printf("t: %s \n",t); 
		tLen = strlen(t);
	printf("tLen: %d\n",tLen); //9
	
	printf("\n");
}

int main(){
	basic();
	funciones();
}