#include <bits/stdc++.h>
 
using namespace std;
 
string s;
int pd[100005];
 
int seek (int k) {
	if (k >= (int)s.size()) return 1e9;
	if (k == 0) return 0;
	if(pd[k] != -1) return pd[k];
	
	int dig = s[k];
	int bf = -1;
	for (int i=0;i<(int)s.size() && i < k;i++) {
		if (s[i] == dig) { bf = i; break; }
	}
	int ans = 1 + seek(k-1);
	if (bf != -1) ans = min(1 + seek(bf), ans);
	//ans = min(ans, 1 + seek(k+1));
	
	pd[k] = ans;
	
	return ans;
}
 
int main () {
	cin >> s;
	memset(pd, -1,sizeof pd);	
	
	cout << seek(s.size() - 1) << endl;
 
}
