typedef struct Stack Stack;
	
void Stack_Init(Stack *S);
void* Stack_Top(Stack *S);
void Stack_Push(Stack *S, void *d);
void Stack_Pop(Stack *S);
int Stack_Empty(Stack *S);