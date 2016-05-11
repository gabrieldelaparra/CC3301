#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "t2.h"

#define N 8

int cmp_nombres(void *a, int k, void *x) {
  char **nombres= a, *nom= x;
  int str =  strcmp(nombres[k], nom);
  return str;
}

int buscar_nombre(char **nombres, int n, char *nom) {
  return buscar(nombres, n, nom, cmp_nombres);
}

char *nombres[]={ "alberto", "ana", "diego", "juan",
                  "maria", "pedro", "silvia", "ximena" };

char *otros[]={ "Alberto", "silviaa", "xximena", "jua", "dieg0", NULL};

int main(int argc, char **argv) {
  for (int i= 0; i<8; i++) {
	  int pos = buscar_nombre(nombres, N, nombres[i]);
    if (pos!=i) {
      fprintf(stderr, "buscar falla no encontrando %s\n", nombres[i]);
      exit(1);
    }
	else{
		// printf("Found: %s Pos: %d\n ### \n",nombres[i],pos);
	}
  }

  for (int j= 0; otros[j]!=NULL; j++) {
    if (buscar_nombre(nombres, N, otros[j])!=-1) {
      fprintf(stderr, "buscar falla encontrando %s\n", otros[j]);
      exit(1);
    }
  }

  printf("Felicitaciones: la parte a de su tarea funciona correctamente\n");

  return 0;
}
