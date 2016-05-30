typedef double (*Funcion)(void *p, double x);
double integral(Funcion f, void *p, double xi, double xf, int n){
	int h = (xf - xi)/n;
	int a = (f(p,xi)+f(p,xf))/2;
	int i;
	for (i=0;i<n;i++){
		a+=f(p,xi+k*h);
	}
	return h*a;
}

typedef struct(
	double xi;
	double xf;
	int n;
	) param;
	
double g_aux(void *ptr, double x){
	double y= *(double*)ptr;
	return g(x, y);
}

double integral_g_dx(double xi, double xf, int y, double n){
	
	return integral(g_aux, &y, xi, xf, n);
}
	
double integral_g_dx_dy(double xi, double xf, int n, double yi, double yf, int m){
	
	param* p = (param*)malloc(sizeof(param));
	p->xi=xi;
	p->xf=xf;
	p->n=n;
	
	return integral(integral_g_dx, param, yi, yf, m);
}