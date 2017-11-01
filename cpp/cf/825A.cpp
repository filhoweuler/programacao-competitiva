#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	getchar();
	string s, ans;
	getline(cin, s);
	int k = 0, cnt = 0;
	while (k < s.size()) {
		while (k < s.size() && s[k] == '1') {
			cnt++;
			k++;
		}
		k++;
		ans.push_back(cnt + '0');
		cnt=0;
	}
	if (s[k-1] == '0') ans += '0';
	cout << ans << endl;
}
