#include <bits/stdc++.h>

using namespace std;

typedef struct Node{ 
	int data;
	struct Node *next;
}Node;

typedef struct Stack{
	Node *top;
} Stack;

Stack *build();
bool empty(Stack *s);
void insert(Stack *s, int value);
int top(Stack *s);
void pop(Stack *s);

int main() {

	Stack *s = build();
	assert(empty(s));
	
	insert(s, 10);
	assert(!empty(s));
	assert(top(s) == 10);
	
	insert(s, 20);
	assert(top(s) == 20);
	
	pop(s);
	assert(top(s) == 10);

	pop(s);
	assert(empty(s));	
}

Stack *build() {
	Stack *s = (Stack*) malloc(sizeof (Stack));
	s->top = NULL;
	return s;
}

bool empty(Stack *s) {
	return s->top == NULL;
}

void insert(Stack *s, int value) {
	Node *no = (Node*) malloc(sizeof (Node));
	no->data = value;
	no->next = s->top;
	s->top = no;
}

int top(Stack *s) {
	return s->top->data;
}

void pop(Stack *s) {
	Node *aux = s->top;
	s->top = s->top->next;
	free(aux);
}
