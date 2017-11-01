#include <bits/stdc++.h>

using namespace std;

#define M 1000000007

map<string, int> notas;
int pre[10050];

void build_pre(const vector<int> &T, const vector<int> &P) {
	
	int m = P.size();
	int k = 0;
	pre[0] = 0;
	for (int p=1; p < m; p++) {
		while (k > 0 && P[p] != P[k]) k = pre[k];
		if (P[p] == P[k]) k++;
		pre[p] = k;
	}	
}

int kmp (const vector<int> &T, const vector<int> &P) {
	//build_pre(T, P);
	int n = T.size();
	int ans = 0;
	int p = 0;
	for (int i=0;i<n;i++) {
		while (p > 0 && P[p] != T[i]) p = pre[p];
		if (P[p] == T[i]) ++p;
		if (p == (int)P.size()) {
			ans++;
			p = pre[p-1];
		}
	}
	
	return ans;
}

int main() {
		ios::sync_with_stdio(false);
		notas["A"] = 1;
		notas["A#"] = 2;
		notas["Bb"] = 2;
		notas["B"] = 3;
		notas["Cb"] = 3;
		notas["C"] = 4;
		notas["B#"] = 4;
		notas["C#"] = 5;
		notas["Db"] = 5;
		notas["D"] = 6;
		notas["D#"] = 7;
		notas["Eb"] = 7;
		notas["E"] = 8;
		notas["Fb"] = 8;
		notas["E#"] = 9;
		notas["F"] = 9;
		notas["F#"] = 10;
		notas["Gb"] = 10;
		notas["G"] = 11;
		notas["G#"] = 12;
		notas["Ab"] = 12;
		
		int m, t;
		
		while (cin >> m >> t) {
			if (m == 0 && t == 0) break;
			
			string ant;
			cin >> ant;
			vector<int> mus1, cop;
			
			for (int i=1;i<m; i++) {
				string at;
				cin >> at;
				int mx = max(notas[at], notas[ant]);
				int mn = min(notas[at], notas[ant]);
				
				mus1.push_back(min(mx - mn, 12 - mx + mn));
				ant = at;
			}
			
			cin >> ant;
			
			for (int i=1;i<t; i++) {
				string at;
				cin >> at;
				int mx = max(notas[at], notas[ant]);
				int mn = min(notas[at], notas[ant]);
				
				cop.push_back(min(mx - mn, 12 - mx + mn));
				ant = at;
			}
			int tt = mus1.size();
			int t2 = cop.size();
			
			//cout << tt << " " << t2 << endl;
			//bool flag = false;
			
			if (tt < t2) { cout << 'N' << endl; continue; }
			int rs = kmp(mus1, cop);
			if (rs > 0) cout << 'S' << endl;
			else cout << 'N' << endl;
			
	}
}
