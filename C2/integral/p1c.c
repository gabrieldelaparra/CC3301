#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "integral.h"

#define L 8

pthread_t ts[L];

// pthread_mutex_t mt = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
	double xi, xf, yi, yf;
	int n, m;
	double res;
} Par;

double result=0;

void *compFun(void *p) {
	Par *par = (Par*)p;	
	par->res = integral_g_dx_dy(par->xi,par->xf,par->n,par->yi,par->yf,par->m);
	return NULL;
}

double integral_g_dx_dy_par(double xi, double xf, int n, double yi, double yf, int m){
	int i = 0;
	double s = (yf-yi)/L;
	
	// Par prr[8];
	
	Par **prr = (Par **) malloc(L*sizeof(Par*));
	
	for(i = 0;i<L;i++){
		// prr[i] = (Par){xi,xf,yi+(s*i),yi+(s*(i+1)),n,m/L};
		prr[i] = (Par*) malloc(sizeof(Par));
		prr[i]->xi = xi;
		prr[i]->xf = xf;
		prr[i]->yi = yi+(s*i);
		prr[i]->yf = yi+(s*(i+1));
		prr[i]->m = m/L;
		prr[i]->n = n;
		pthread_create(&ts[i],NULL, compFun, prr[i]);
	}
	
	for(i=0; i<L;i++){
		pthread_join(ts[i], NULL);
		result += prr[i]->res;
	}
	return result;
}
