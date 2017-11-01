#include <bits/stdc++.h>

using namespace std;

int main () {
	
	int n;
	cin >> n;
	unordered_set<int> s;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int ax; cin >> ax;
		if(s.count(ax) || ax > n) {
			ans++;
		}
		s.insert(ax);
	}
	cout << ans << endl;
}
