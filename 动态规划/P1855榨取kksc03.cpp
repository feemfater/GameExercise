#include<bits/stdc++.h>
using namespace std;

const int N = 1.e3;
int n;//n个愿望
int M;//m元
int T;//T分钟
int v[N];
int t[N];
int dp[N][N];//dp[i][j]表示给定i元和j分钟下可以实现愿望的最大数

int main() {
	cin >> n >> M >> T;
	
	for (int i = 1; i <= n; i++) {
		cin >> v[i] >> t[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = M; j >= v[i]; j--) {
			for (int k = T; k >= t[i]; k--) {
				dp[j][k] = max(dp[j][k], dp[j - v[i]][k - t[i]] + 1);
			}
		}
	}

	cout << dp[M][T] << endl;
	return 0;

}