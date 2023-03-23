#include <stdio.h>
#include <stdlib.h>

const int MAXLEN = 100;

typedef char T;

typedef struct stack
{
	T* s;
	T* end;
	int len;
} Stack, * pStack, ** ppStack;

pStack init();
void push(ppStack pp, T x);
T top(pStack p) { if (!isempty(p)) return *(p->end - 1); printf("ERROR: Stack is empty"); return NULL; }
T pop(ppStack pp);
void printc(pStack p);
int isempty(pStack p);

pStack init()
{
	pStack p = (pStack)malloc(sizeof(pStack));
	if (p)
	{
		p->end = p->s = (T*)malloc(sizeof(T) * MAXLEN);
		p->len = 0;
	}
	return p;
}

void push(ppStack pp, T x)
{
	pStack p = *pp;
	if (p->len < MAXLEN - 1)
	{
		*(p->end++) = x;
		return;
	}
	printf("ERROR: Stack is full\n");
}

T pop(ppStack pp)
{
	pStack p = *pp;
	if (p->s == p->end)
	{
		printf("ERROR: Stack is empty");
		return NULL;
	}
	T x = *(--p->end);
	return x;
}

void printc(pStack p)
{
	T* temp = p->s;
	while (temp != p->end)
		printf("%c", *temp), temp++;
	printf("\n");
}

int isempty(pStack p)
{
	if (p->s == p->end)
		return 1;
	return 0;
}

int main()
{
	pStack stack = init();
	push(&stack, 'x');
	push(&stack, 'y');
	printc(stack);
	pop(&stack);
	printc(stack);
	return 0;
}