#include <bits/stdc++.h>

using namespace std;

int main () {
	
	int n;
	
	while (cin >> n) {
		vector<string> in;
		string aux;
		for (int i=0;i<n;i++) {
			cin >> aux;
			in.push_back(aux);
		}
		sort(in.begin(), in.end());
		int ans = 0;
		for (int i=1;i<n;i++) {
			int k = 0;
			while (in[i][k] == in[i-1][k]) {
				k++;
				ans++;
			}
		}
		cout << ans << endl;
	}

}
