#include<bits/stdc++.h>
using namespace std;

const int N = 600;
int n;//武将个数
int a[N][N];//武将默契表
int b[N];//武将选择数组，若武将被选择则置1，否则为0
int ans;//记录结果
int computer;//记录机器人结果

int main() {
	cin >> n;
	ans = 0;
	computer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cin >> a[i][j];
			a[j][i] = a[i][j];
		}
	}

	//每次选择默契值第二大的武将，第一大的默认会被电脑选走
	//选择武将按照上面固定的规则进行,小涵一定赢
	//所有获胜的情况中，小涵最终选出的武将组合的最大默契值就是所有行的次大值的最大

	for (int i = 1; i <= n; i++) {
		sort(a[i] + 1, a[i] + n + 1);
		ans = a[i][n - 1] > ans ? a[i][n - 1] : ans;
	}
	cout << 1 << endl;
	cout << ans << endl;
}