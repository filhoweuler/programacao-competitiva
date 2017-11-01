#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int a[100505];
	double tsm=0, sm;
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		tsm+=a[i];
	}
	tsm /= 2.0;
	set<double> seen;
	seen.insert(a[0]);
	sm=a[0];
	for (int i=1;i<n;i++) {
		seen.insert(a[i]);
		sm+=a[i];
		int tt = sm - tsm;
		if (seen.find(tt) != seen.end()) {
			cout << tt << " 1 " << a[i] << endl;
			cout << "YES" << endl;
			exit(0);
		}
	}
	reverse(a, a+n);
	sm = a[0];
	seen.clear();
	seen.insert(a[0]);
	for (int i=1;i<n;i++) {
		seen.insert(a[i]);
		sm+=a[i];
		int tt = sm - tsm;
		if (seen.find(tt) != seen.end()) {
			cout << tt << " 2 " << a[i] << endl;
			cout << "YES" << endl;
			exit(0);
		}
	}
	cout << "NO" << endl;
}
