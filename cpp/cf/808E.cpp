#include <bits/stdc++.h>

using namespace std;

int main () {
	
	int n, m;
	cin >> n >> m;
	vector<int> c[4];
	
	for (int i=0;i<n;i++) {
		int ci, w;
		cin >> w >> ci;
		c[w].push_back(ci);
	}
	
	for (int i=1; i<=3;i++) {
		while (c[i].size() < m + 3) c[i].push_back(0);
	}
	
	for (int i=1; i<=3;i++)
		sort(c[i].rbegin(), c[i].rend());
		
	long long dp[m+1];
	dp[0] = 0;
	int w2=0, w1=0;
	
	for (int i=2; i<=m; i++) {
		if (c[2][w2] >= c[1][w1] + c[1][w1+1]) {
			dp[i] = dp[i-2] + c[2][w2];
			w2++;
		} else {
			dp[i] = dp[i-2] + c[1][w1] + c[1][w1+1];
			w1+=2;
		}
	}
	
	dp[1] = c[1][0];
	w2=0;
	w1=1;
	
	for (int i=3; i<=m; i++) {
		if (c[2][w2] >= c[1][w1] + c[1][w1+1]) {
			dp[i] = dp[i-2] + c[2][w2];
			w2++;
		} else {
			dp[i] = dp[i-2] + c[1][w1] + c[1][w1+1];
			w1+=2;
		}
	}
	
	long long tt=0, ans=0;
	
	for (int i=0;i <= c[3].size() && 3*i <= m; i++) {
		ans = max(ans, tt + dp[m-3*i]);
		if (i < c[3].size()) tt+=c[3][i];
	}
	
	cout << ans << endl; 

}
