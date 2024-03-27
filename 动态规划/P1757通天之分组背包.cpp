#include<bits/stdc++.h>
using namespace std;

const int N = 1.e3 + 11;
int w[N];//物体重量
int v[N];//物体的利用价值
int c[N];//物体所属组数
int dp[N][N];//dp[i][j]为前i组在重量最大为j物体的价值最大值
int k;//分组数
int n;//n件物品
int m;//总重

int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i] >> c[i];
		k = max(c[i], k);
	}

	for (int i = 1; i <= k; i++) {
		for (int j = m; j >= 0; j--) {
			dp[i][j] = dp[i - 1][j];
			for (int k = 1; k <= n; k++) {
				if (c[k] != i)continue;
				if (w[k] > j)continue;
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[k]] + v[k]);
			}
		}
		
		
	}

	cout << dp[k][m] << endl;

	return 0;

	
}