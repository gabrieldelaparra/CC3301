#include "integral.h"
#include <stdlib.h>

typedef struct {
	double xi, xf;
	int n;
} Param;


double g_aux(void *ptr, double x) {
	double y= *(double *)ptr;
	return g(x, y);
}

double integral_g_dx(double xi, double xf, double y, int n) {
	return integral(g_aux, &y, xi, xf, n);
}

double integral_g_dx_aux(void *p, double y){
	Param *par = (Param *)p;
	return integral_g_dx(par->xi,par->xf,y,par->n);
	// // Alternativamente:
	// double xi = ((Param *)p)->xi;
	// double xf = ((Param *)p)->xf;
	// int n = ((Param *)p)->n;
	// return integral_g_dx(xi,xf,y,n);
}


double integral_g_dx_dy(double xi, double xf, int n, double yi, double yf, int m){
	// Param p = {xi, xf, n}; //Tambien aplica, más corta!
	// return integral(integral_g_dx_aux, &p, yi, yf, m);
	// //Alternativamente:




	Param *p = (Param*) malloc(sizeof(Param));
	p->xi=xi;
	p->xf=xf;
	p->n=n;
	return integral(integral_g_dx_aux, p, yi, yf, m);
}