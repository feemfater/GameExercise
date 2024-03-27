#include<bits/stdc++.h>
using namespace std;

//前缀和剪枝+dfs搜索

const int N = 1.e3 + 10;
int a[N];//砝码的重量
long long  sum[N];//前缀和
int n;//砝码的数量
int c;//天枰最大称重
long long ans;//所以组合的最大重量


void dfs(long long  weight,int index) {
	//weigth:当前重量,num:第几个砝码
	if (weight + sum[index] <= ans)return;//剩下的全加上都没有更大则剪掉
	if (weight > c)return;
	ans = max(ans, weight);

	if (index ==0)return;

	dfs(weight + a[index], index - 1);
	dfs(weight, index - 1);
}


int main() {
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}

	dfs(0, n);
	cout << ans << endl;
	return 0;
}
