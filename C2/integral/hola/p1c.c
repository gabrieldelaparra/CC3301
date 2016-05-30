#include <pthread.h>
#include "integral.h"
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
double s=0;

typedef struct{
	double xi, xf, yi, yf;
	int n,m;
	double res;
} params;

void *f(void *q){
	params* p = (params*)q;
	p->res = integral_g_dx_dy(p->xi, p->xf, p->n, p->yi, p->yf, p->m);

	return NULL;
}

double integral_g_dx_dy_par(double xi, double xf, int n, double yi, double yf, int m){

	pthread_t t[8];
	params *q[8];
	double dif = (yf-yi)/8;
	int i;
	for(i=0;i<8;i++){
		q[i] = {xi,xf,yi+(i*dif),yi+((i+1)*dif),n,m/8};
	}
	for(i=0;i<8;i++){
		pthread_create(&t[i],NULL,f,&q[i]);
	}
	
	for(i=0;i<8;i++){
		pthread_join(t[i],NULL);
	}
	return s;
}

