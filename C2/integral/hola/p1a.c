typedef double (*Funcion)(void *p, double x);

double integral(Funcion f, void *p, double xi, double xf, int n){
	double h = (xf - xi)/n;
	double a = (f(p,xi)+f(p,xf))/2;
	int i=0;
	for (i=1;i<n;i++){
		a+=f(p,xi+i*h);
	}
	return h*a;
}
