#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
	struct Node *nxt[26];
} Node;

typedef struct Trie {
	Node *root;
}Trie;

Node *newNode() {
	Node *n = (Node*) malloc(sizeof(Node));
	for (int i=0;i<26;i++) {
		n->nxt[i] = NULL;
	}
	return n;
}

Trie *build() {
	Trie *t = (Trie*)malloc(sizeof (Trie));
	t->root = newNode();
	return t;
}

void insert(Trie *t, string s) {
	Node *ptr = t->root;
	for (int i=0;i<(int)s.size();i++) {
		if (ptr->nxt[ s[i] - 'a' ] == NULL) {
			printf("Inserido um no %c\n",s[i]);
			ptr->nxt[ s[i] - 'a' ] = newNode();
		}
		
		ptr = ptr->nxt[ s[i] - 'a' ];
	}
}

bool query(Trie *t, string s) {
	Node *ptr = t->root;
	for (int i=0;i<(int)s.size();i++) {
		if (ptr->nxt[ s[i] - 'a' ] == NULL) {
			printf("Falhou no caractere %c\n",s[i]);
			return false;
		}
		ptr = ptr->nxt[ s[i] - 'a' ];	
	}
	
	return true;
}

int main () {
	Trie *t = build();
	insert(t, "aba");
	insert(t, "abacate");
	assert(query(t, "aba"));
	assert(query(t, "abaca"));
	assert(!query(t, "abx"));
}
