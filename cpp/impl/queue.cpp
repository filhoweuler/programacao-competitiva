#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* next;
};

typedef struct Node Node;

struct Queue {
	Node *front, *back;
};

typedef struct Queue Queue;

Queue *build();
void insert(Queue* q, int value);
int front(Queue* q);
void pop(Queue* q);
bool empty(Queue* q);

int main () {

	Queue *q = build();
	
	insert(q, 10);
	cout << front(q) << endl;
	insert(q, 15);
	insert(q, 20);
	insert(q, 25);
	cout << front(q) << endl;
	pop(q);
	cout << front(q) << endl;
	pop(q);
	cout << front(q) << endl;
	pop(q);
	cout << front(q) << endl;
	pop(q);
	if (empty(q)) cout << "A fila esta vazia. Correto!\n";
	else cout << "Deu ruim." << endl;
	
}

Queue* build() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->front = NULL;
	q->back = NULL;
	return q;
}

void insert(Queue* q, int value) {
	Node* no = (Node*) malloc(sizeof (Node));
	no->data = value;
	no->next = NULL;
	if (empty(q)) {
		q->back = q->front = no;
	} else {
		q->back->next = no;
		q->back = no;
	}
}

int front(Queue* q) {
	return q->front->data;		
}

void pop(Queue* q) {
	if (!empty(q)) {
		Node* aux = q->front;
		q->front = q->front->next;
		if (q->front == NULL) q->back = NULL;
		free(aux);
	}
}

bool empty(Queue* q) {
	return q->front == NULL;
}


