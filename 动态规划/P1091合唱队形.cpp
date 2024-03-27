#include<bits/stdc++.h>
using namespace std;

const int N = 1.e3;
int n;//n个同学
int a[N];//n个同学的身高
int b[N];//a的倒置
int dp[N];//第i个人为结尾的最长上升子序列的长度
int pd[N];//第i个人为结尾的最长下降子序列的长度
int ans;//最少需要同学数


bool cmp(int a, int b) {
	return a > b;
}

//ans=n-max(以i结尾的最长上升子序列 + 以i结尾的最长下降子序列-1)
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = 1;
		pd[i] = 1;
	}

	//最长上升子序列
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (a[i] > a[j]) {
				
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	//最长下降子序列就是把数组转置，求最长上升子序列
	for (int i = 1; i <= n; i++) {
		b[i] = a[n - i+1];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (b[i] > b[j]) {

				pd[i] = max(pd[i], pd[j] + 1);
			}
		}
	}

	ans = 0;
	for (int i = 1; i <= n; i++) {

		ans = max(ans, dp[i] + pd[n - i + 1] - 1);
	}


	
	cout << n - ans << endl;

	return 0;

	
}