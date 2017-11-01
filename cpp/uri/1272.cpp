#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	getchar();
	for (int i=0;i<n;i++) {
		string ip;
		getline(cin, ip);
		
		stringstream ss;
		ss << ip;
		
		string ax;
		string ans;
		while (ss >> ax) ans+=ax[0];
		cout << ans << endl;
	}
}
