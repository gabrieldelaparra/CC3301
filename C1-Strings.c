#include <stdio.h> //printf
#include <stdlib.h> //malloc
#include <string.h> //strings



int main(){
	// ToUpper("hola");
	// ParseHex("adf123");
	// basic();
	// funciones();
}

char* ToUpper(char* s){
	printf("s: \"%s\" \n",s);
	char t[strlen(s)+1];	
	
	int i=0;
	for(i=0;i<strlen(s);i++){
		t[i] = s[i]-'a'+'A';
	}
	t[strlen(s)] = 0;
	printf("t: \"%s\" \n",t);
}

int ParseHex(char* s){
	printf("s: \"%s\" \n",s);	
	int i = 0;
	int num = 0;
	int sLen = strlen(s);
	printf("sLen: %i\n",sLen);
	while(*(s+i)!=0){
		printf("c: \'%c\' \n",*(s+i));
		int parse = 0;
		switch(*(s+i)){			
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			parse = (*(s+i)-'0')<<((sLen-i-1)*4);
			printf("p: %p \n",parse);
			num += parse;
			break;
			
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			parse = (*(s+i)-'a'+10)<<((sLen-i-1)*4);
			printf("p: %p \n",parse);
			num += parse;
			break;
			
			default:
			break;
		}
		i++;
	}
	printf("h: %i\n",num);
	printf("h: %p\n",num);
	return num;
}

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
	while(s[i] != 0)
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

char* Concat(char* t, char*s)
{
	printf("src t: \"%s\" \n",t); 
	printf("src s: \"%s\" \n",s); 
	
	int tLen = length(t);
	printf("tLen: %d\n",tLen); //0
	
	int i = 0;
	while(s[i] != 0){
		printf("t[tLen+i]: i:%i c:\'%c\' \n",t[tLen+i], t[tLen+i]);
		printf("s[i]: i:%i c:\'%c\' \n",s[i], s[i]);
		t[tLen+i] = s[i];
		i++;
	}
	printf("return t: %s \n",t);
	return t;
}

void funciones(){
	char *s = "chao";
	char r[] = {'h','o','l','a',0};
	char t[50] = {0};
	
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
	printf("t: %s \n",t); //Queda con los dos caracteres finales de hola, se superpone lo que hab�a copiado anteriormente;
	tLen = length(t);
	printf("tLen: %d\n",tLen); //4
	printf("\n");
	
	printf("Vaciar t\n"); //Los strings se vac�an con 0s;
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
	
	printf("StrCat(t,r + \" \" +s)\n");
	
	printf("copy(t,r)\n"); 
	copy(t,r);
	printf("copy(t,r) t: %s \n",t); 
	printf("\n");
	
	printf("Concat(t, )\n"); //Antes ten�a problemas con el concatenar, era porque no ten�a bien colocado el tama�o del arreglo de T y estaba dejando caracteres regados por todas partes, algo que no entend�a porqu� sucedia. Al cambiar el tama�o de t[i] a 50, dej� de suceder;
	Concat(t," ");
	printf("Concat(t, ) t: %s \n",t); 
	printf("\n");
	
	printf("Concat(t,s)\n");
	Concat(t,s);
	printf("Concat(t,s) t: %s \n",t); 
	printf("\n");
	
	tLen = strlen(t);
	printf("tLen: %d\n",tLen); //9
	
	printf("\n");
}