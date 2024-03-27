#include<bits/stdc++.h>
using namespace std;

const int N = 500;
int n;//行
int m;//列
int x;//初始位置
int y;//初始位置
int a[N][N];//记录棋盘
int dir[8][2] = { {1,2},{2,1},{2,-1},{1,-2},
					{-1,-2},{-2,-1},{-2,1},{-1,2} };

//马每次移动都是横着一格，竖着两格的对角线
void bfs(int x, int y) {

	queue<pair<int, int >>q;
	q.push(make_pair(x, y));
	a[x][y] = 0;


	while (!q.empty()) {

		int A = q.front().first;
		int B = q.front().second;
		

		//选择下一步

		for (int i = 0; i <= 7; i++) {

			int C = A + dir[i][0];
			int D = B + dir[i][1];
			if (C > n || D > m || C < 1 || D < 1)continue;


			if (a[A][B] + 1 < a[C][D]) {

				q.push(make_pair(C,D));
				a[C][D] = a[A][B] + 1;
			}

		}

		q.pop();
	}
	

}

int main() {

	cin >> n >> m >> x >> y;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] = 0x3f3f3f3;
		}
	}

	bfs(x, y);


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 0x3f3f3f3)cout << -1 << " \n"[j == m];
			else cout << a[i][j] << " \n"[j == m];
		}
	}

	return 0;

}