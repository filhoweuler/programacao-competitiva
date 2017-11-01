#include <stdio.h>
#include <stdlib.h>

//assert

void assert(int test) {
	if (test == 0) { 
		printf("Assertion failed\n");
		exit(0);
	}
}

//bst structure
typedef struct Node {
	int data;
	struct Node *left, *right;	
} Node;

Node *newNode(int value);

void inorder(Node *bst);

Node *insert(Node *bst, int value);

int search(Node *bst, int value);


int main () {

	Node *root = NULL;
	root = insert(root, 5);
	assert(root != NULL);
	assert(root->data == 5);
	
	insert(root, 8);
	insert(root, 3);
	
	assert(root->left->data == 3);
	assert(root->right->data == 8);
	
	insert(root, 1);
	
	assert(root->left->left->data == 1);
	
	assert(search(root, 1) == 1);
	assert(search(root, 3) == 1);
	assert(search(root, 8) == 1);
	assert(search(root, 12) == -1);
	assert(search(root, 2) == -1);	

	printf("Fim dos testes.\n");
	exit(0);
}

Node *newNode(int value) {
	Node *p = (Node*) malloc(sizeof(Node));
	p->left = NULL;
	p->right = NULL;
	p->data = value;
	return p;
}

void inorder(Node *bst) {
	if (bst != NULL) {
		inorder(bst->left);
		printf("%d\n",bst->data);
		inorder(bst->right);
	}
}

Node *insert(Node *bst, int value) {
	if (bst == NULL) return newNode(value);
	
	if (value < bst->data) {
		bst->left = insert(bst->left, value);
	} else {
		bst->right = insert(bst->right, value);
	}
	
	return bst;
}

int search (Node *bst, int value) {
	if (bst == NULL) return -1;
	if (bst->data == value) return 1;
	
	if (value < bst->data) return search(bst->left, value);
	else return search(bst->right, value);
}
