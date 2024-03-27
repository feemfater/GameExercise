#include<bits/stdc++.h>
using namespace std;


//二维数组的差分

const int N = 1.e3 + !0;
int a[N][5];//记录地毯
int b[N][N];//差分数组
int ans[N][N];//结果数组
int n;//n*n的格子
int m;//m个地毯

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];

		for (int j = a[i][1]; j <= a[i][3]; j++) {
			b[j][a[i][2]] += 1;
			b[j][a[i][4] + 1] -= 1;
		}

	}
	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans[i][j] = b[i][j] + ans[i][j - 1];
			cout << ans[i][j] << " \n"[j == n];
		}
	}

	return 0;
}
