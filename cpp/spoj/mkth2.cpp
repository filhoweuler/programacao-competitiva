#include <bits/stdc++.h>

using namespace std;
#define MAXN 100010

int st[10101010];
int versao[MAXN];
int L[10101010];
int R[10101010];
int cnt = 0;

void build(int no, int l, int r){
	st[no] = 0;
	if(l==r) return;
	L[no] = cnt++;
	R[no] = cnt++;
	int mid = (l+r)/2;
	build(L[no], l, mid);
	build(R[no], mid+1, r);
}

int update(int no, int l, int r, int pos){
	int nw = cnt++;
	st[nw] = st[no];
	st[nw]++;
	if(l==r) return nw;
	L[nw] = L[no];
	R[nw] = R[no];
	
	int mid = (l+r)/2;
	if(pos <= mid)
		L[nw] = update(L[nw], l, mid, pos);
	else 
		R[nw] = update(R[nw], mid+1, r, pos);
	
	
	return nw;
}

int query(int esq, int dir, int l, int r, int k){
	if(l==r) return r;
	int soma = st[L[dir]] - st[L[esq]];
	int mid = (l+r)/2;
	if(soma <= k) return query(R[esq], R[dir], mid+1, r, k-soma);
	return query(L[esq], L[dir], l, mid, k);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	//mapear
	int qtdElem, qtdQuery;
	cin >> qtdElem >> qtdQuery;
	versao[0] = cnt;
	build(cnt, 1, qtdElem);
	
	int x;
	map<int, int> mapa;
	map<int, int> rev;
	vector<int> v;
	vector<int> v2;
	for (int i = 1; i <= qtdElem; i++)
	{
		cin >> x;
		v.push_back(x);
		v2.push_back(x);
	}
	
	sort(v.begin(), v.end());
	int idx = 1;
	
	for (int i = 0; i < v.size(); i++)
	{
		if(mapa.count(v[i])==0){
			mapa[v[i]] = idx;
			rev[idx++] = v[i];
		}
	}
	
	
	for (int i = 1; i <= qtdElem; i++)
	{
		
		versao[i] = update(versao[i-1], 1, qtdElem, mapa[v2[i-1]]);
	}
	
	
	int l, r, k;
	while (qtdQuery--)
	{
		cin >> l >> r >> k;
		cout << rev[query(versao[l-1], versao[r], 1, qtdElem, k-1)] << "\n";
	}
	
	
	
	return 0;
}
