#include <bits/stdc++.h>

using namespace std;

int n, w;

int kmp (vector<int> &T, vector<int> &P) {
	int ans = 0, k = 0;
	int pre[w];
	pre[0] = 0;
	for (int p = 1; p < w; ++p) {
		while (k > 0 && P[p] != P[k]) k = pre[k];
		if (P[p] == P[k]) ++k;
		pre[p] = k;
	}
	int p = 0;
	
	for (int i = 0; i < n; i++) {
		while (p > 0 && P[p] != T[i]) p = pre[p];
		if (P[p] == T[i]) ++p;
		if (p == w) {
			++ans;
			p = pre[p-1];
		}
	}
	return ans;
}

int main () {
	ios::sync_with_stdio(false);
	
	
	int a[205050], b[205050];
	vector<int> da, db;
	cin >> n >> w;
	
	for (int i=0;i<n;i++) {
		cin >> a[i];
		if (i != 0) da.push_back(a[i]-a[i-1]);
	}
	for (int i=0;i<w;i++) {
		cin >> b[i];
		if (i != 0) db.push_back(b[i]-b[i-1]);
	}
	if (w == 1) { cout << n << '\n'; exit(0); }
	
	n--;w--;
	cout << kmp(da, db) << endl;
	
}
