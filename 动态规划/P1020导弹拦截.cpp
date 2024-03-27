#include<bits/stdc++.h>
using namespace std;

//线性动态规划
const int N = 1.e5+ 10;
int a[N];//记录导弹的高度
int b[N];
int dp[N];//以i为结尾的最长递减子序列长度
int c[N];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int x=0;
	int n=0;
	while (cin >> x) {
		a[++n] = x;
		dp[n] = 1;
	}


	//（相等也要包含进去）
	//求最长递减子序列,就是数组倒置的求最长递增子序列
	for (int i = 1; i <= n; i++) {
		b[i] = a[n - i + 1];
	}

	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (b[i]>=b[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	sort(dp + 1, dp + 1 + n, cmp);
	cout << dp[1];


	for (int i = 1; i <= n; i++) {

		for (int i = 1; i <= n; i++) {
			if (c[i] == 0)c[i] = a[i];
			if (a[i] > c[i])continue;
			c[i] = a[i];
			break;
		}
	}
	cout << a[1];
	return 0;


}