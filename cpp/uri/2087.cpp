#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
	int counter;
	bool isLast;
	struct Node *next[26];
	
	Node() {
		counter = 0;
		isLast = false;
		for (int i=0; i<26;i++) {
			next[i] = NULL;
		}
	}
} Node;

typedef struct Trie {
	Node *root;
	Trie() {
		root = new Node();
	}
	
	bool insert(string s) {
		bool good = true;
		Node *ptr = root;
		for (int i=0;i<(int)s.size();i++) {
			int go = s[i] - 'a';
			if (ptr->next[go] == NULL) {
				ptr->next[go] = new Node();
			}
			
			ptr = ptr->next[go];
			ptr->counter++;
			
			if (ptr->isLast && ptr->counter >= 2) good = false;
		}
		
		ptr->isLast = true;
		
		return (ptr->counter < 2 && good);
	}
} Trie;

bool can(Node *ptr) {
	
	if (ptr->counter > 1 && ptr->isLast) return false;
	
	bool ans = true;
	
	for (int i=0;i<26;i++) {
		if (ptr->next[i] != NULL) {
			ans &= can(ptr->next[i]);
		}
	}
	
	return ans;
}

void clear(Node *ptr) {
	for (int i=0;i<26;i++) {
		if (ptr->next[i] != NULL) 
			clear(ptr->next[i]);
	}
	delete(ptr);
}

int main () {
	int n;
	while (cin >> n) {
		if (n == 0) break;
		getchar();
		Trie *t = new Trie();
		bool ans = true;
		for (int i=0;i<n;i++) {
			string s;
			getline(cin, s);
			ans &= t->insert(s);
		}
		if (ans) cout << "Conjunto Bom" << endl;
		else cout << "Conjunto Ruim" << endl;
		clear(t->root);
		delete(t);
	}
}
