#include<bits/stdc++.h>
using namespace std;

const int N = 40;
int a[N][N];
bool used[N][N];
int dire[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int n;


void bfs(int x,int y) {
	queue<pair<int ,int >> q;
	pair<int, int >p;
	p.first = x;
	p.second = y;
	used[x][y] = true;
	q.push(p);


	while (!q.empty()) {
		p=q.front();
		int A = p.first;
		int B = p.second;
		a[A][B] = 0;

		for (int i = 0; i <= 3; i++) {

			int C = A + dire[i][0];
			int D = B + dire[i][1];

			if (a[C][D] == 2 && !used[C][D]) {
				q.push(make_pair(C, D));
			}
		}
		q.pop();
	}

}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i <= n+1; i++) {
		for (int j = 0; j <= n+1; j++) {
			if (a[i][j] == 0)a[i][j] = 2;
		}
	}


	bfs(0, 0);
	cout << endl;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << " \n"[j == n];
		}
	}

	return 0;

}
