#include<bits/stdc++.h>
using namespace std;

const int N = 1.e3 + 10;
int t[N];//采药时间
int v[N];//药材价值
int dp[N];//dp[i]表示总时间i下的价值最大值
int T;//总共可以采药的时间
int M;//药材的数目

//只有两种状态，在时间给定j的情况下第i个草药采或者不采,dp[j]=max(dp[j-t[i]]+v[i],dp[])
int main() {
	cin >> T >> M;
	for (int i = 1; i <= M; i++) {
		cin >> t[i] >> v[i];
	}

	for (int i = 1; i <= M; i++) {
		for (int j = T; j>=t[i]; j--) {
			dp[j] = max(dp[j - t[i]] + v[i], dp[j]);
		}
	}
	cout << dp[T] << endl;
}