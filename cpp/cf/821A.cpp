#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int a[55][55];
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			cin >> a[i][j];
		}
	}
	int canbe = 1;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (a[i][j] == 1) continue;
			int cc = 0;
			for (int s=0;s<n;s++) {
				for (int t=0;t<n;t++) {
					if (a[i][s] + a[t][j] == a[i][j]) cc = 1;
				}
			}
			if (cc == 0) canbe = 0;
		}		
	}
	
	if (canbe) cout << "Yes\n";
	else cout << "No\n";
}
