#include<bits/stdc++.h>
using namespace std;

const int N = 3 * 1.e3 + 10;
const long long mod = 1.e8;
int n;//n头奶牛
int f;//幸运数字(队伍的总能力必须是f的倍数)
int r[N];//奶牛的能力
long long dp[N][N];//dp[i][j]:能力和%F为j情况下前i头牛选择的最大方案数
int ans;


/*
void dfs(int y, int x) {
	//x：奶牛下标，y：队伍的能力和
	if (x > n)return;
	if (x == n) {
		if (y!=0 && y % f == 0) {
			ans++;
			ans %= mod;
		}
		return;
	}
	dfs(y, x + 1);
	dfs(y + r[x + 1], x + 1);
}
	
*/


int main() {
	cin >> n >> f;
	for (int i = 1; i <= n; i++) {
		cin >> r[i];
		r[i] %= f;
		dp[i][r[i]] = 1;
	}
	
	//01背包解法
	for (int i = 1; i <= n; i++) {
		for (int j = f - 1; j >= 0; j--) {

			dp[i][j] = ((dp[i][j]+ dp[i - 1][j]) % mod + (dp[i - 1][(j - r[i] + f) % f])) % mod;
		}
	}



	cout << dp[n][0] << endl;
}