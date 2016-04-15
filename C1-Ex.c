#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int espacio(char *s, char *p, char *r) {
  int ss = strlen(s);
  int pp = strlen(p);
  int rr = strlen(r);
  int i= 0;
  int matches = 0;
  for(i=0;i<ss-pp;i++)
  {
	  if(strncmp(s+i,p,pp)==0)matches++;
  }
  return ss+(rr-pp)*matches+1;
}

char *substituir(char *s, char *p, char *r) {
  int ss = strlen(s);
  int pp = strlen(p);
  int rr = strlen(r);
  int esp = espacio(s,p,r);
  char* sub = (char*)malloc(sizeof(char)*esp);
  int i=0;
  
  for(i=0;i<ss-pp;i++){
	  if(strncmp(s+i,p,pp)==0){
		strcpy(sub+i,r);	  
		i=i+rr;
	  }
	  else sub[i]=s[i];
  }
  sub[esp]=0;
  return sub;
}

int main() {
	// printf("%i",espacio("hola mundo", "hello", "bonjour"));
  if (espacio("hola mundo", "hello", "bonjour")!=11)
    printf("falla test 1\n");
  else if (espacio("hola mundo", "ola", "ello")!=12)
    printf("falla test 2\n");
  else if (espacio("elgatotemelperro", "el", "un")!=17)
    printf("falla test 3\n");
  else if (strcmp(substituir("hola mundo", "hello", "bonjour"),
             "hola mundo") != 0)
    printf("falla test 4\n");
  else if (strcmp(substituir("hola mundo", "ola", "ello"),
                  "hello mundo") != 0)
    printf("falla test 5\n");
  else if (strcmp(substituir("elgatotemelperro", "el", "un"),
                  "ungatotemunperro") != 0)
    printf("falla test 6\n");
  else
    printf("Todos los tests funcionan correctamente\n");
  return 0;
}

