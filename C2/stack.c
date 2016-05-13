#include <stdio.h>
#include "stack.h"

#define STACK_MAX 100

typedef struct {
    void*     data[STACK_MAX];
    int     size;
} Stack;

void Stack_Init(Stack *S)
{
    S->size = 0;
}

int Stack_Empty(Stack *S){
	return S->size;
}

void* Stack_Top(Stack *S)
{
    if (S->size == 0) {
        fprintf(stderr, "Error: stack empty\n");
        return NULL;
    } 

    return S->data[S->size-1];
}

void Stack_Push(Stack *S, void *d)
{
    if (S->size < STACK_MAX)
        S->data[S->size++] = d;
    else
        fprintf(stderr, "Error: stack full\n");
}

void Stack_Pop(Stack *S)
{
    if (S->size == 0)
        fprintf(stderr, "Error: stack empty\n");
    else
        S->size--;
}

int main(int argc, char *argv[]){
}