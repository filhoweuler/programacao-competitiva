#include <bits/stdc++.h>

using namespace std;

int main () {
	
	int n, m;
	int wr[55],wc[55],br[55],bc[55];
	memset(wr, 0, sizeof wr);
	memset(wc, 0, sizeof wc);
	memset(br, 0, sizeof br);
	memset(bc, 0, sizeof bc);
	int ax;
	cin >> n >> m;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			cin >> ax;
			if (ax == 1) {
				wr[i]++;
				wc[j]++;
			} else {
				br[i]++;
				bc[j]++;
			}
		}
	}
	
	int ans = 0;
	for (int i=0;i<n;i++) {
		//~ printf("wr[%d] = %d\n",i,wr[i]);
		//~ printf("br[%d] = %d\n",i,br[i]);
		ans += (wr[i]*(wr[i] + 1))/2;
		ans += (br[i]*(br[i] + 1))/2;
	}
	//~ cout << ans << endl;
	for (int j=0;j<n;j++) {
		//~ printf("wc[%d] = %d\n",j,wc[j]);
		//~ printf("bc[%d] = %d\n",j,bc[j]);
		ans += (wc[j]*(wc[j] + 1))/2;
		ans += (bc[j]*(bc[j] + 1))/2;
	}
	//~ cout << ans << endl;
	
	ans -= (n*m);
	
	cout << ans << endl;
}
