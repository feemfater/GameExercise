#include<bits/stdc++.h>
using namespace std;

const int N = 5001;
int n, m;//n个目标，m*m的正方形攻击范围
//int  a[N][N];//目标价值
int sum[N+10][N+10];//前缀和
int ans;

//二维前缀和,记录数组左上面积
int main() {
	cin >> n >> m;
	ans = 0;
	//从(1,1)开始
	for (int i = 1; i <= n; i++) {
		int x;
		int y;
		int v;
		cin >> x >> y >> v;
		sum[x+1][y+1] += v;//坐标可能重合
	}



	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1]+sum[i][j];
		}
	}

	

	for (int i = m; i <= N; i++) {
		for (int j = m; j <= N; j++) {
		int temp = sum[i][j] - sum[i - m][j] - sum[i][j - m] + sum[i - m][j - m];
			ans = max(ans, temp);
		}
	}

	cout << ans << endl;
	return 0;
}
