#include <stdio.h> //printf
#include <strings.h> //strings
#include <stdlib.h> //malloc


int palindrome(char* s){
	int size = strlen(s);
	int i = 0;
	for(i=0;i<(size/2);i++){
		if(s[i]!=s[size-1-i]) return 0;
	}
	return 1;
}

int mystrcmp(char* s1, char* s2){
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	int i=0;
	int max = l2;
	if(l1>l2)max=l1;
	
	for(i=0;i<max;i++){
		if(s1[i]>s2[i]) return 1;
		else if(s1[i]<s2[i]) return -1;
	}
	return 0;
}

char* reverse(char* s){
	int len = strlen(s);
	char* r = (char*)malloc(sizeof(char)*(len+1)); //Considerando el cero final;
	int i = 0;
	
	for(i = 0;i<len;i++){
		*(r+i)=*(s+len-1-i);
	}
	*(r+len)=0;
	return r;
}

void reverse2(char* s){
	int len = strlen(s);	
	int i = 0;
	char c = 0;
	for(i = 0; i < (len/2); i++){
		c=*(s+i);
		*(s+i) = *(s+len-1-i);
		*(s+len-1-i) = c;
	}
}

void reverse3(char* s){
	char c;
	char *p= s+ strlen(s) -1;
	while(p>s){
		c=*s;
		*s=*p;
		*p=c;
		
		s++;
		p--;
	}
}

int main()
{
	// printf("%i\n", palindrome("ABA"));
	// printf("%i\n", palindrome("ABBA"));
	// printf("%i\n", palindrome("ABABA"));
	// printf("%i\n", palindrome("ABABC"));
	// printf("\n");
	
	// printf("%i\n", palindrome("A"));
	// printf("%i\n", palindrome("AC"));
	// printf("\n");
	
	// printf("%i\n", mystrcmp("A","B"));
	// printf("%i\n", mystrcmp("B","A"));
	// printf("%i\n", mystrcmp("A","A"));
	// printf("\n");
	
	// printf("%i\n", mystrcmp("AAAB","AAAA"));
	// printf("%i\n", mystrcmp("AAAA","AAAB"));
	// printf("%i\n", mystrcmp("AAAA","AAAA"));
	// printf("\n");
	
	// char* p = reverse("ALAMEDA");
	// printf("%s\n",p);
	// free(p);
	// printf("\n");
	
	// char s[] = {'h','o','l','a',0};	
	// printf("%s\n",s);
	// reverse2(s);
	// printf("%s\n",s);
	// printf("\n");
	
	
	// int uno = 1;
	// int* p = &uno;
	// printf("%i\n",p);
	// printf("%i\n",&uno);
	// printf("%i\n",*p);
	// printf("%i\n",&p);
	
	
	// int* p2 = 1;
	// printf("%i\n",p2);
	// printf("%i\n",*p2);
	// printf("%i\n",&p2);
	
	
	// insertNodes();

	// struct punto w={1.0,-2.5};
	// struct punto z={2.0,0};
	// struct punto q = NewPoint(2,0);
	// struct punto *r = mallocPoint(2,0);
	
	// printPnt(SumaP(&w,&q));
	// printPnt(Suma(&w,r));
	// free(r);
	// basic();
}


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
