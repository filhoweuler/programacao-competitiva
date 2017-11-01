#include <bits/stdc++.h>

using namespace std;

int main () {
	
	std::ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	stack<int> p;
	int nw = 1;
	int rots = 0;
	for (int i=0;i<2*n;i++) {
		string cm;
		cin >> cm;
		if (cm == "add") {		
			int ax;
			cin >> ax;
			p.push(ax);
			//~ cout << cm << " " << ax << endl;
		} else {
			if (p.empty()) {
				nw++;
				continue;
			}
			
			if (p.top() == nw) {
				p.pop();
				nw++;
				continue;
			}
			
			rots++;
			nw++;
			while(!p.empty()) p.pop();
		}
	}
	cout << rots << endl;
}
