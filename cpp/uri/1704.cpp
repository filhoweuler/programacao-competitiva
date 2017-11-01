#include <bits/stdc++.h>

using namespace std;

bool cmp (const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first == b.first) 
		return a.second > b.second;
	
	return a.first < b.first;
}


int main () {

	vector<pair<int, int> > data;

	int n, h;
	while (cin >> n >> h) {
		data.clear();
		for (int i=0;i<n; i++) {
			int lucro, t;
			cin >> lucro >> t;
			data.push_back(make_pair(t, lucro));		
		}
			
		sort (data.begin(), data.end(), cmp);
		
		int time = 0;
		int loss = 0;
		for (int i=0;i<n;i++) {
			if (data[i].first > time && h > 0) {			
				time++;
				h--;
			} else {
				loss+=data[i].second;
			}
			
			cout << data[i].first << " " << data[i].second << endl;
		}
		
		cout << loss << endl;
	}
}
