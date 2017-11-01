#include <bits/stdc++.h>

using namespace std;

int sky[105][105];
int tree[105][105][11];
int n, m;

void update(int row, int col, int val, int t) {
	int delta = val - sky[row][col];
	//sky[row][col] = val;
	printf("upd [%d,%d]",row, col);
	for (int i = row; i <= m; i += i & (-i)) {
        for (int j = col; j <= n; j += j & (-j)) {
                tree[i][j][t] = tree[i][j][t-1] + delta;
		}
	}
	
}
int sum(int row, int col, int t) {
	int sum = 0;
	for (int i = row; i > 0; i -= i & (-i)) {
		for (int j = col; j > 0; j -= j & (-j)) {
			sum += tree[i][j][t];
		}
	}
	printf("sum[%d,%d] = %d\n",row, col, sum);
	return sum;
}

int sumR(int row1, int col1, int row2, int col2, int t) {
	return sum(row2, col2, t) + sum(row1-1, col1-1 ,t) - sum(row1-1, col2,t) - sum(row2, col1-1,t);
}



int main () {
	
	int n, q, c;
	scanf("%d %d %d",&n,&q,&c);
	m = n;
	memset(sky, -1, sizeof sky);
	
	for (int i=0;i<n;i++) {
		int x, y, s;
		scanf("%d %d %d",&x,&y,&s);
		sky[x][y] = max(sky[x][y], s);		
	}
	
	for (int i=0;i<105;i++) {
		for (int j=0;j<105;j++) {
			if (sky[i][j] != -1) 
				update(i, j, sky[i][j], 0);
			else
				update(i, j, 0, 0);
		}
	}
	cout << "ok" << endl;
	for (int t=1;t<=10;t++) {
		for (int i=1;i<=100;i++) {
			for (int j=1;j<=100;j++) {
				if (sky[i][j] != -1) {
					printf("update em [%d,%d] de %d no tempo %d\n",i, j, (sky[i][j] + t)%(c+1), t);
					update(i, j, (sky[i][j] + t)%(c+1), t);
				}
			}
		}
	}
	
	for (int i=0;i<q;i++) {
		int t, x1, y1, x2, y2;
		scanf("%d %d %d %d %d",&t, &x1, &y1, &x2, &y2);
		printf("%d\n",sumR(x1, y1, x2, y2, t%(c+1)));
	}

}
