#include <bits/stdc++.h>

using namespace std;

int main () {
	
	string s, t;
	getline(cin, s);
	getline(cin, t);
	int cnt[30], c=0;
	memset(cnt, 0, sizeof cnt);
	for (int i=0;i<s;i++) {
		if (s[i] == '?') c++;
		else cnt[s[i] - 'a']++;
	}
	
}
