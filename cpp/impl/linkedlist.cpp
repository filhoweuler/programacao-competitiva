#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* next;	
};

typedef struct Node Node;

typedef struct List {
	Node* fst;
} List;

List* build() {
	List* l = (List*) malloc(sizeof (List));
	l->fst = NULL;
	return l;
}

bool empty(List* l) {
	return l->fst == NULL; 
}

void insert(List* l, int value) {
	Node* no = (Node*)malloc(sizeof(Node));
	no->next = l->fst;
	no->data = value;
	l->fst = no;
}

void print(List* l) {
	Node* it = l->fst;
	while (it != NULL) {
		cout << it->data << endl;
		it = it->next;
	}
}

int main () {
	List* test = build();
	insert(test, 5);
	insert(test, 4);
	insert(test, 3);
	insert(test, 2);
	insert(test, 1);
	print(test);
}
