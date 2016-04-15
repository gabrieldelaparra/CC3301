#include <stdio.h> //printf
#include <strings.h> //strings
#include <stdlib.h> //malloc



int main()
{
	struct punto w={1.0,-2.5};
	// struct punto z={2.0,0};
	struct punto q = NewPoint(2,0);
	struct punto *r = mallocPoint(2,0);
	
	printPnt(SumaP(&w,&q));
	printPnt(Suma(&w,r));
	free(r);
	// basic();
}

typedef struct punto{
	float x, y;
} Punto;

void printPnt(struct punto p){
	printf("p=(%f, %f)\n",p.x,p.y);	
}

Punto Suma(Punto *u, Punto *v){
	struct punto s={(*u).x+(*v).x,(*u).y+(*v).y};
	return s;
}

struct punto SumaP(struct punto *u, struct punto *v){
	struct punto s={u->x+v->x,u->y+v->y};
	return s;
}

struct punto NewPoint(float x, float y){ //no hay problemas con la memoria porque no se pasa como puntero.
	struct punto n = {x,y};
	return n;
}

struct punto *mallocPoint(float x, float y){
	// struct punto n = malloc(sizeof(struct punto)); //ERROR
	struct punto *n = malloc(sizeof(struct punto));
	n->x=x;
	n->y=y;
	return n;
}

void basic(){
struct punto u, v;
struct punto z={1.0,-2.5};

z.x=2.0;
printf("z=(%f, %f)\n",z.x,z.y);	
}