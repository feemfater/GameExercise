#include<bits/stdc++.h>
using namespace std;

const int N = 500;
int n;//��
int m;//��
int x;//��ʼλ��
int y;//��ʼλ��
int a[N][N];//��¼����
int dir[8][2] = { {1,2},{2,1},{2,-1},{1,-2},
					{-1,-2},{-2,-1},{-2,1},{-1,2} };

//��ÿ���ƶ����Ǻ���һ����������ĶԽ���
void bfs(int x, int y) {

	queue<pair<int, int >>q;
	q.push(make_pair(x, y));
	a[x][y] = 0;


	while (!q.empty()) {

		int A = q.front().first;
		int B = q.front().second;
		

		//ѡ����һ��

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