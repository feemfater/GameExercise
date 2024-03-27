#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int x;
	int y;
	int time;
	int gps;
};

const int N = 60;
int n;
int m;
int a[N][N];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int GPS;
int resultX;
int resultY;
int ans;


void bfs(int x, int y) {

	queue<node>p;

	node first = node{x,y,0,GPS};
	p.push(first);

	while (!p.empty())
	{
		int A = p.front().x;
		int B = p.front().y;
		int time = p.front().time;
		GPS = p.front().gps;


		for (int i = 1; i <= 5; i++) {

			int	C = A;
			int D = B;
			int gps = GPS;

			if (i <= 3) {
				for (int j = 1; j <= i; j++) {
					C += dir[gps][1];
					D += dir[gps][0];

					if (a[C][D] == 1)break;
				}
			}
			if (i == 4) {
				gps = (gps + 1) % 4;
			}
			if (i == 5) {
				gps = (gps - 1) % 4;
				gps = gps < 0 ? (gps + 4) : gps;
			}

			if (a[C][D] == 1)continue;
			if (C == A && D == B && GPS == gps)continue;
			p.push(node{ C,D,time + 1,gps });

			if (C == resultX && D == resultY) {
				ans = time + 1;
				return;
			}
		}
		p.pop();

	}
	ans = -1;


}


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0 || i == n || j == m) {
				a[i][j] = 1;
			}
			else {
				if (a[i][j] == 1) {
					a[i][j - 1] = 1;
					a[i - 1][j] = 1;
					a[i - 1][j - 1] = 1;
				}
			}
		}
	}

	int x, y;
	char s;
	cin >> x >> y >> resultX >> resultY >> s;

	if (s == 'E')GPS = 0;
	if (s == 'N')GPS = 1;
	if (s == 'W')GPS = 2;
	if (s == 'S')GPS = 3;

	cout << endl;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			cout << a[i][j] << " \n"[j == m];
		}
	}

	bfs(x, y);

	cout << ans << endl;
}