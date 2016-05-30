#include <pthread.h>

#include "reunion.h"

typedef struct reunion {
	pthread_mutex_t m;//= PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t cond;// = PTHREAD_COND_INITIALIZER;
	int count;
  ... // declare acá un mutex y una condición y los contadores que
      // Ud. necesitará para resolver el problema de sincronización
};

Reunion *nuevaReunion(){
	
}

