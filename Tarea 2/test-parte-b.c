#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "t2.h"

char *pals[]= { 
"alimento", 
"lluvia", 
"Bolsillo", 
"celularr", 
"corre", 
"techo",
"eembarcacion", 
"posada", 
"taladro", 
NULL 
};

char *defs[]= {
  "sustancia ingerida por un ser vivo",
  "condensacion del vapor de agua contenida en las nubes",
  NULL,
  NULL,
  NULL,
  "parte superior de un edificio que lo cubre y cierra",
  NULL,
  "establecimiento economico de hospedaje destinado a albergar viajeros",
  "herramienta aguda o cortante con que se agujerea la madera",
  NULL
};

int main(int argc, char **argv) {
  for (int i=0; pals[i]!=NULL; i++) {
    char *def= consultar("dicc.txt", pals[i], LINEAS);
    if (def==NULL) {
      if (defs[i]!=NULL) {
        fprintf(stderr, "consultar falla no encontrando %s\n", pals[i]);
        exit(1);
      }
    }
    else {
      if (defs[i]==NULL) {
        fprintf(stderr, "consultar falla encontrando %s\n", pals[i]);
        exit(1);
      }
      else if (strcmp(def, defs[i])!=0) {
        fprintf(stderr, "el valor asociado a %s no es %s\n", pals[i], def);
        exit(1);
      }
      free(def);
    }
  }
    
  printf("Felicitaciones: la parte b de su tarea funciona correctamente\n");

  return 0;
}
