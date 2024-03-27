#include<bits/stdc++.h>
using namespace std;

const int N = 1.e3 + 1;
int a[N][N];//记录金字塔
int n;

//线性动态规划(线性动态规划，即具有线性阶段划分的动态规划。)
//求整个金字塔的路径最大值，可以简化为求小金字塔的路径最大值

int main() {

	//输入金字塔的层数
	cin >> n;

	//输入金字塔
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}

	//从顶向上
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
		}
	}

	cout << a[1][1] << endl;

	return 0;



}
