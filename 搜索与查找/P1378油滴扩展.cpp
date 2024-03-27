#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int n;//记录相异点个数
int node[N][3];//记录相异点的坐标
double r[N];//记录相异点是否使用,若使用记录半径
bool isUse[N];//记录相异点是否可以使用
double dis[N][N];//记录任意两点之间的距离,预处理
int maxX;
int minX;
int maxY;
int minY;

double ans;



void dfs(int index,double size) {
	
	if (index > n) {//所有特异点都用完
		ans = max(ans, size);
		return;
	}

	for (int i = 1; i <= n; i++) {

		if (!isUse[i]) {//未使用的特异点,遇到油滴或者框停下
			r[i] = min(
				min(maxX - node[index][1], node[index][1] - minX),
				min(maxY - node[index][2], node[index][2] - minY)
			);

			for (int j = 1; j <= n; j++) {
				//遇到油滴停下(此处比较先遇框还是油滴)
				if (isUse[j]) {
					r[i] = min(r[i], dis[i][j] - r[j]);
				}
			}
			isUse[i] = true;
			if (r[i] < 0) {
				r[i] = 0;
			}

			dfs(index + 1, size + r[i] * r[i] * 3.1415926535);
			isUse[i] = false;
		}
	}
}


int main() {
	cin >> n;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	maxX = max(a, c);
	minX = min(a, c);
	maxY = max(b, d);
	minY = min(b, d);

	for (int i = 1; i <= n; i++) {
		cin >> node[i][1] >> node[i][2];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			dis[i][j] = hypot(node[i][1] - node[j][1], node[i][2] - node[j][2]);
			dis[j][i] = dis[i][j];
		}
	}
	double size = (maxX - minX) * (maxY - minY);
	ans = 0;
	dfs(1, 0.0);
	cout << round(size - ans) << endl;

	return 0;
}