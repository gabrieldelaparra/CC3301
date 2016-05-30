#include "integral.h"
#include <stdlib.h>

typedef struct{
	double xi, xf;
	int n;
} Param;
	
double g_aux(void *ptr, double x){
	double y= *(double*)ptr;
	return g(x, y);
}

double integral_g_dx(double xi, double xf, double y, int n){
	return integral(g_aux, &y, xi, xf, n);
}

double integral_g_dx_aux(void* p, double y){
	Param *q = (Param *)p;
	return integral_g_dx(q->xi,q->xf,y,q->n);
}
	
double integral_g_dx_dy(double xi, double xf, int n, double yi, double yf, int m){
	Param *p = (Param*) malloc(sizeof(Param));
	p->xi=xi;
	p->xf=xf;
	p->n=n;
	return integral(integral_g_dx_aux, p, yi, yf, m);
}