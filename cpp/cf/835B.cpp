#include <bits/stdc++.h>

using namespace std;

int main () {
	
	int k;
	cin >> k;
	string n;
	cin >> n;
	int dsum = 0;
	for (int i=0;i<(int)n.size();i++) {
		dsum += n[i] - '0';
	}	
	if (dsum >= k) cout << "0\n";
	else {
		int ans = 0;
		sort(n.begin(), n.end());
		int pos = 0;
		while (dsum < k) {
			dsum+=(9 - (n[pos] - '0'));
			pos++;
			ans++;
		}
		cout << ans << endl;
	}
}
