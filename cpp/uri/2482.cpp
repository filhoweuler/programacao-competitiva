#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	getchar();
	map<string, string> dic;
	for (int i=0;i<n;i++) {
		string lingua, trad;
		getline(cin, lingua);
		getline(cin, trad);
		//cout << lingua << " " << trad << endl;
		dic[lingua] = trad;
	}
	cin >> n;
	getchar();
	for (int i=0;i<n;i++) {
		string 	crianca, lingua;
		getline(cin, crianca);
		getline(cin, lingua);
		cout << crianca << endl;
		cout << dic[lingua] << endl;
		cout << endl;
	}
}
