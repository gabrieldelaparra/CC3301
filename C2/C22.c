#include <string.h>
#include <stdio.h>

typedef double (*Function) (void *p, double x);

double integral(Function f, void *p, double xi, double xf, int n){
	double h = (xf-xi)/n;
	double a = (f(p,xi)+f(p,xf))/2;
	double s = 0;
	for(int i = 1; i<n; i++){
		s = s + f(p,xi+i*h);
	}
	return h*(a+s);
}

int main(int argc, char *argv[]){
	
}