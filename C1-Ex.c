#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int espacio(char *s, char *p, char *r) {
  return 0;
}

char *substituir(char *s, char *p, char *r) {
  return s;
}

int main() {
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

