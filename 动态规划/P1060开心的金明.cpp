#include<bits/stdc++.h>
using namespace std;

//01背包问题
const int N = 3*1.e4 + 10;
int n;//总钱数
int m;//希望购买的物品数
int v[N];//价格
int w[N];//重要度(价值=价格*重要度)
int dp[N];//dp[i]给定总钱数为i的情况下价值最大值


int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> v[i] >> w[i];
		w[i] = w[i] * v[i];//价值
	}

	
	for (int i = 1; i <= m; i++) {
		for (int j = n; j >= v[i]; j--) {
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
		}
	}
	cout << dp[n] << endl;	
	
	
	return 0;
	
	
}