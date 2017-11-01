#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int nc = 1;
int L[10101010], R[10101010], tr[10101010], root[10101010];

void build (int no, int l, int r) {
	if (l==r) return;
	L[no] = nc++;
	R[no] = nc++;
	
	int mid = (l+r) >> 1;
	build(L[no], l, mid);
	build(R[no], mid+1, r);
}

int update(int no, int l, int r, int x) {
	int clone = nc++;
	tr[clone] = tr[no] + 1;
	if (l == r) return clone;

	L[clone] = L[no];
	R[clone] = R[no];
	
	//cout << "ow = " << tr[clone] << " e x = " << x << endl;
	
	int mid = (l+r) >> 1;
	
	if ( x <= mid ) L[clone] = update(L[clone], l, mid, x);
	else R[clone] = update(R[clone], mid+1, r, x);
	
	return clone;
}

int query (int l, int r, int nol, int nor, int x) {
	if (l == r) return l;
	
	int mid = (l+r) >> 1;
	
	int dif = tr[L[nor]] - tr[L[nol]];
	
	if (dif > x)
		return query(l, mid, L[nol], L[nor], x);
	else
		return query(mid+1, r, R[nol], R[nor], x-dif);	
	
}

int main () {
	map<int, int> mapa;
	map<int, int> rev;
	int n, m;
	int a[N], b[N];
	scanf("%d %d", &n, &m);
	root[0] = nc;
	build(root[0], 1, n);
	
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		b[i] = a[i];
	}	
	sort(a+1, a+n+1);
	int idx = 1;
	for (int i=1;i<=n;i++) {
		if (mapa.count(a[i]) == 0) {
			mapa[a[i]] = idx;
			rev[idx] = a[i];
			idx++;
		}
	}
	for (int i=1; i<=n;i++) {
		root[i] = update(root[i-1], 1, n, mapa[b[i]]);
	}
	for (int i=0;i<m;i++) {
		int a, b, k;
		scanf("%d %d %d", &a, &b, &k);
		printf("%d\n",rev[query(1, n, root[a-1], root[b], k-1)]);
	}
}
