#include <bits/stdc++.h>

using namespace std;

vector<string> mat;

int dfs (int i, int j, int vi, int vj) {
	if (i < 0 || i >= 10 || j < 0 || j >= 10) return 0;
	if (mat[i][j] == 'X') return 1 + dfs(i + vi, j + vj, vi, vj);
	else return 0;
}

int main () {
	
	string s;
	
	for (int i=0;i<10;i++) {
		getline(cin, s);
		mat.push_back(s);
	}
	int can = false;
	for (int i=0;i<10;i++) {
		for (int j=0;j<10;j++) {
			if (mat[i][j] == '.') {
				for (int k=-1; k<=1; k++) {
					for (int l=-1; l<=1; l++) {
						int d1 = dfs(i + k, j + l, k, l);
						int d2 = dfs(i - k, j - l, -k, -l);
						//~ printf("Calling at [%d][%d] = %d and [%d][%d] = %d\n",i+k, j+l, d1, i-k, j-l, d2);
						if (d1 + d2 >= 4) can = true;
					}
				}
			}
		}
	}
	
	if (can) cout << "YES" << endl;
	else cout << "NO" << endl;
}
