#include <bits/stdc++.h>

using namespace std;

//long long memo[10050][10050];

long long range_sum (int a, int b) {
	double p_ans = ((double)(a-b+1)/2.0) * (a+b);
	
	return (long long)p_ans;
}


//~ long long bananas(int x, int y) {
	//~ if (memo[x][y] != -1) return memo[x][y];
	//~ long long ans;
	
	//~ if (x == 0 && y == 0) {
		//~ ans = 0;
	//~ } else if (x == 0) {
		//~ ans = y + bananas(0, y-1);
	//~ } else if (y == 0) {
		//~ ans = x + bananas(x-1, 0);
	//~ } else {
		//~ ans = x + y + bananas(x-1, y) + bananas(x,y-1) - bananas(x-1, y-1);
	//~ }
	
	//~ memo[x][y] = ans;
	
	//~ return ans;
	
//~ }

long long bananas (int x, int y) {
	int st = x + y;
	int end = y;
	
	long long sm = 0;
	
	while (end >= 0) {
		sm += range_sum(st, end);
		st--;
		end--;
	}
	
	return sm;
}

int main () {
	int m, b;
	cin >> m >> b;
	long long mx = -1;
	//memset(memo, -1, sizeof memo);
	for (int k = b; k >= 0; --k) {
		int x = (-1)*m*(k-b); //retangulo (k,x)
		mx = max(bananas(x, k), mx);
	}
	cout << mx << endl;
	
	//cout << range_sum(4,0) << endl;
}
