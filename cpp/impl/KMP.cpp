#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1050

int n, m, pre[MAX_N];

int kmp(int* T, int* P) {
	
	int ans = 0;	
	//compute preffix function
	int k = 0;
	pre[0] = 0;
	for (int p = 1; p < m; p++) {
		while (k > 0 && P[p] != P[k]) {
			k = pre[k];
		}
		
		if (P[p] == P[k]) ++k;
		
		pre[p] = k;
	}
	
	for (int i=0;i<m;i++) cout << pre[i] << " ";
	cout << endl;
	int q = 0;
	//match
	for (int i=0;i<n;i++) {
		while (q > 0 && P[q] != T[i]) 
			q = pre[q];
		if (P[q] == T[i]) 
			++q;
		if (q == m) { 
			++ans; 
			q = pre[q-1]; 
		}
	}
	
	return ans;
}

int main () {
	int a[MAX_N], b[MAX_N];
	cin >> n;
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	cin >> m;
	for (int i=0;i<m;i++) {
		scanf("%d",&b[i]);
	}
	
	cout << kmp(a, b) << endl;
}
