#include<bits/stdc++.h>
using namespace std;


class hole {
public:
	int x;
	int y;
	int z;
};

const int N = 1.e3 + 10;
int T;//数据组数
int n;//空洞数量
int h;//奶酪高度
int r;//空洞半径

int vis[N];//空洞是否访问
hole hs[N];//记录洞
bool finded = false;//是否找到


double dis(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
}

bool cmp(hole a, hole b) {
	return a.z < b.z;
}

void dfs(int index) {

	if ((hs[index].z + r) >= h) {
		finded = true;
		return;
	}
	vis[index] = true;

	for (int i = 1; i <= n; i++) {
		if (finded) {
			return;
		}
		if (!vis[i] && dis(hs[index].x, hs[index].y, hs[index].z, hs[i].x, hs[i].y, hs[i].z) <= 2 * r) {
			dfs(i);
		}
	}
}



int main() {

	cin >> T;

	for (int i = 1; i <= T; i++) {
		memset(hs, 0, sizeof(hs));
		memset(vis, 0, sizeof(vis));
		finded = false;
		cin >> n >> h >> r;
		for (int j = 1; j <= n; j++) {
			cin >> hs[j].x >> hs[j].y >> hs[j].z;
		}
		sort(hs + 1, hs + 1 + n, cmp);
		for (int i = 1; i <= n; i++) {
			if ((hs[i].z - r) <= 0) {
				dfs(i);
			}
		}
		if (finded)cout << "Yes" << endl;
		else cout << "No" << endl;


	}

	return 0;

}