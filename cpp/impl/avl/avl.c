#include <stdio.h>
#include <stdlib.h>

//assert
void assert(int test) {
	if (test == 0) {
		printf("Assertion failed.\n");
		exit(0);
	}
}

//avl

typedef struct Node {
	int data;
	int height;
	struct Node *left, *right;	
} Node;

int max(int a, int b);

int height(Node *no);

Node *newNode(int value);

Node *insert(Node *avl, int value);

Node *insert_balanceado(Node *avl, int value);

Node *delete(Node *avl, int value);

Node *delete_balanceado(Node *avl, int value);

Node *rightRotate(Node *y);

Node *leftRotate(Node *x);

int getBalance(Node *avl);

void inorder(Node *avl);

Node *minNode(Node *avl);

int main () {

	Node *root = NULL;
	assert(root == NULL);
	
	root = insert(root, 5);
	insert(root, 3);
	insert(root, 2);
	insert(root, 2);
	
	assert((minNode(root))->data == 2);
	
	assert(height(root) == 3);
	assert(height(root->left) == 2);
	assert(height(root->left->left) == 1);
	
	root = rightRotate(root);
	
	assert(root->data == 3);
	assert(root->right->data == 5);
	assert(root->left->data == 2);
	assert(height(root) == 2);
	assert(height(root->left) == height(root->right) && height(root->right) == 1);
	
	inorder(root);
	printf("\n");
	root = delete_balanceado(root, 2);
	inorder(root);
	printf("\n");
	root = delete_balanceado(root, 8);
	inorder(root);
	printf("\n");
	
	Node *root_balanceada = NULL;
	root_balanceada = insert_balanceado(root_balanceada, 4);
	assert(root_balanceada->data == 4);
	
	//causa desbalanco esquerdo
	root_balanceada = insert_balanceado(root_balanceada, 2);
	root_balanceada = insert_balanceado(root_balanceada, 1);
	
	assert((minNode(root_balanceada))->data == 1);
	
	inorder(root_balanceada);
	
	assert(root_balanceada->data == 2);	

	printf("\nFim dos testes.\n");
	exit(0);
}

int max(int a, int b) {
	return (a > b)? a : b;
}

int height(Node *no) {
	if (no == NULL) return 0;
	
	return no->height;
}

Node *newNode(int value) {
	Node *no = (Node*) malloc(sizeof(Node));
	no->height = 1;
	no->data = value;
	no->left = NULL;
	no->right = NULL;
	return no;
}

Node *insert(Node *avl, int value) {
	if (avl == NULL) { 
		printf("Inserido o no de valor %d\n\n",value);
		return newNode(value);
	}
	
	if (value < avl->data) {
		avl->left = insert(avl->left, value);
	} else if (value > avl->data) {
		avl->right = insert(avl->right, value);
	} else {
		printf("Inserção não realizada!! No duplicado na arvore!\n\n");
		return avl;
	}
	
	avl->height = 1 + max(height(avl->left), height(avl->right));
	
	//nao desbalanceou, retorna raiz nao modificada
	return avl;
}

Node *insert_balanceado(Node *avl, int value) {
	if (avl == NULL) {
		printf("Inserido o no de valor %d\n\n",value); 
		return newNode(value);
	}
	
	if (value < avl->data) {
		avl->left = insert(avl->left, value);
	} else if (value > avl->data) {
		avl->right = insert(avl->right, value);
	} else {
		printf("Inserção não realizada!! No duplicado na arvore!\n\n");
		return avl;
	}
	
	avl->height = 1 + max(height(avl->left), height(avl->right));
	
	int balance = getBalance(avl);
	
	//left left
	if (balance > 1 && value < avl->left->data) {
		return rightRotate(avl);
	}
	
	//right right
	if (balance < -1 && value > avl->right->data) {
		return leftRotate(avl);
	}
	
	//left right
	if (balance > 1 && value > avl->left->data) {
		avl->left = leftRotate(avl->left);
		return rightRotate(avl);
	}
	
	//right left
	if (balance < -1 && value < avl->right->data) {
		avl->right = rightRotate(avl->right);
		return leftRotate(avl);
	}
	
	//nao desbalanceou, retorna raiz nao modificada
	return avl;
}

Node *rightRotate(Node *y) {
	Node *x = y->left;
	Node *T2 = x->right;
	
	x->right = y;
	y->left = T2;
	
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	
	return x;
}

Node *leftRotate(Node *x) {
	Node *y = x->right;
	Node *T2 = y->left;
	
	y->left = x;
	x->right = T2;
	
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	
	return y;
}

int getBalance(Node *avl) {
	if (avl == NULL) return 0;
	
	return height(avl->left) - height(avl->right);
}

void inorder(Node *avl) {
	if (avl != NULL) {
		inorder(avl->left);
		printf("%d\n",avl->data);
		inorder(avl->right);
	}
}

Node *minNode(Node *avl) {
	Node *curr = avl;
	
	while (curr->left != NULL) {
		curr = curr->left;
	}
	
	return curr;
}

Node *delete(Node *avl, int value) {
	if (avl == NULL) return avl;
	
	if (value < avl->data) {
		avl->left = delete(avl->left, value);
	} else if (value > avl->data) {
		avl->right = delete(avl->right, value);
	} else {
		//estamos no nó a ser deletado
		//um ou nenhum filho
		if ((avl->left == NULL) || (avl->right == NULL)) {
			Node *tmp = avl->left ? avl->left : avl->right;
			
			if (tmp == NULL) {
				tmp = avl;
				avl = NULL;
			} else {
				*avl = *tmp;
			}
			
			free(tmp);
		} else {
			Node *tmp = minNode(avl->right);
			
			avl->data = tmp->data;
			
			avl->right = delete(avl->right, tmp->data);
		}
				
	}
	
	if (avl == NULL) return avl;
	
	avl->height = 1 + max(height(avl->right) , height(avl->left));
	
	return avl;
}

Node *delete_balanceado(Node *avl, int value) {
	if (avl == NULL) return avl;
	
	if (value < avl->data) {
		avl->left = delete(avl->left, value);
	} else if (value > avl->data) {
		avl->right = delete(avl->right, value);
	} else {
		//estamos no nó a ser deletado
		//um ou nenhum filho
		if ((avl->left == NULL) || (avl->right == NULL)) {
			Node *tmp = avl->left ? avl->left : avl->right;
			
			if (tmp == NULL) {
				tmp = avl;
				avl = NULL;
			} else {
				*avl = *tmp;
			}
			
			free(tmp);
		} else {
			Node *tmp = minNode(avl->right);
			
			avl->data = tmp->data;
			
			avl->right = delete(avl->right, tmp->data);
		}
				
	}
	
	if (avl == NULL) return avl;
	
	avl->height = 1 + max(height(avl->right) , height(avl->left));
	
	int balance = getBalance(avl);
	
	if (balance > 1) {
		//left left
		if (getBalance(avl->left) >= 0) {
			return rightRotate(avl);
		}
		//left right
		if (getBalance(avl->left) < 0) {
			avl->left = leftRotate(avl->left);
			return rightRotate(avl);
		}
	}
	
	if (balance < -1) {
		//right right
		if (getBalance(avl->right) <= 0) {
			return leftRotate(avl);
		}
		//right left
		if (getBalance(avl->right) > 0) {
			avl->right = rightRotate(avl->right);
			return leftRotate(avl);
		}
	}
	
	return avl;
}
