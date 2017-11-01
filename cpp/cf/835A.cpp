#include <bits/stdc++.h>

using namespace std;

int main () {
	int s, v1, v2, t1, t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	
	long long ms1, ms2;
	ms1 = s*v1 + 2*t1;
	ms2 = s*v2 + 2*t2;
	
	if (ms1 < ms2) cout << "First";
	else if (ms2 < ms1) cout << "Second";
	else cout << "Friendship";
}
