#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "t2.h"

int buscar(void *a, int n, void *x, Comparador cmp){
  /* funcion pedida, busqueda generica. */

  int fin = n;
  int ini = 0;
  int indice;
  int value;

  while (fin >= ini){
    /* busqueda binaria iterativa */

    indice = ini + (fin - ini)/2;
    value = cmp(a, indice, x);

    if( value == 0){
      /* encontre el x que busco */
      return indice;
    }
    else if( value > 0){
      /* el valor en indice es mayor a x */
      fin = indice-1;
    }
    else{
      /* el valor en indice es menor a x */
      ini = indice+1;
    }

  }

  /* si no retorne antes, no encontre x */
  return -1;
}
