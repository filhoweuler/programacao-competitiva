#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	set<string> ss;
	string ax;
	for (int i=0; i<n;i++) {
		cin >> ax;
		ss.insert(ax);
	}
	printf("Falta(m) %d pomekon(s).\n",(int)(151 - ss.size()));
}
