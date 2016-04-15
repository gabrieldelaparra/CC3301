#include <stdio.h> //printf
#include <strings.h> //strings
#include <stdlib.h> //malloc

typedef struct node{
	int value;
	struct node *next;
} Node;

void printNode(Node* n){
	printf("Node: Address: %i Value: %i Next: %d\n", &n, n->value, n->next==NULL ? 0xFF : (n->next)->value);
}

void printNodeList(Node *n){
	if(n != NULL){
		printNode(n);
		printNodeList(n->next);
	}
}

void addNodeEnd(Node* head, Node* new)
{
	Node* current = head;
	while(current->next != NULL){
		current=current->next;
	}
	current->next=new;
}

Node* insertOrdered(Node* head, Node* new){
	if(new->value<head->value){
		printf("Insert Head\n");
		new->next=head;
		return new;
	}
	
	Node* current = head;
	
	while(current!=NULL){
		if(current->next==NULL){
			printf("Insert End\n");
			current->next = new;
			return head;
		}
		
		int nextValue = (current->next)->value;
		
		if(nextValue < new->value){
			printf("Next\n");
			current = current->next;
		}
		else{ //nextValue > new->value
			printf("Insert: current:%i new: %i\n", current->value, new->value);
			new->next=current->next;
			current->next = new;
			return head;
		}
	}
}

void insertNodes(){
	Node n5 = {5,NULL};
	Node n3 = {3,&n5};
	Node n1 = {1,&n3};
	Node* head = &n1;
	printNodeList(head);
	printf("\n");
	
	printf("AddEnd\n");
	Node n7 = {7, NULL};
	addNodeEnd(head, &n7);
	printNodeList(head);
	printf("\n");

	printf("Insert 0:\n");
	Node n0 = {0,NULL};	
	head = insertOrdered(head,&n0);
	printNodeList(head);
	printf("\n");
	
	printf("Insert 4:\n");
	Node n4 = {4,NULL};	
	head = insertOrdered(head,&n4);
	printNodeList(head);
	printf("\n");
	
	printf("Insert 9:\n");
	Node n9 = {9,NULL};	
	head = insertOrdered(head,&n9);
	printNodeList(head);
	printf("\n");
	
	printf("Insert 2:\n");
	Node n2 = {2,NULL};	
	head = insertOrdered(head,&n2);
	printNodeList(head);
	printf("\n");
}


int main()
{
	insertNodes();

	// struct punto w={1.0,-2.5};
	// struct punto z={2.0,0};
	// struct punto q = NewPoint(2,0);
	// struct punto *r = mallocPoint(2,0);
	
	// printPnt(SumaP(&w,&q));
	// printPnt(Suma(&w,r));
	// free(r);
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