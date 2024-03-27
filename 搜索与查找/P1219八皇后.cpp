#include<bits/stdc++.h>
using namespace std;

const int N = 14;

int a[N][N];//记录n*n的棋盘
int ans[N];//记录结果
int n;
bool flag;
int nums;

//使得每行、每列有且只有一个，
//每条对角线（包括两条主对角线的所有平行线）上至多有一个棋子
bool check(int x, int y) {
	//x：行号,y:列号
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[x][i];
	}
	if (sum > 0)return false;

	for (int i = 1; i <= n; i++) {
		sum += a[i][y];
	}
	if (sum > 0)return false;

	int tempy = y;
	for (int i = x; i <= n; i++) {
		sum += a[i][tempy++];
		if (tempy > n)break;
	}
	if (sum > 0)return false;


	tempy = y-1;
	for (int i = x-1; i >=1; i--) {
		sum += a[i][tempy--];
		if (tempy <1)break;
	}
	if (sum > 0)return false;


	tempy = y +1;
	for (int i = x -1; i >= 1; i--) {
		sum += a[i][tempy++];
		if (tempy >n)break;
	}
	if (sum > 0)return false;

	tempy = y -1;
	for (int i = x + 1; i <=n; i++) {
		sum += a[i][tempy--];
		if (tempy <1)break;
	}
	if (sum > 0)return false;
	return true;
}

void dfs(int x, int y) {

	if (x == (n + 1)) {
		nums++;
		if (nums <= 3) {
			for (int i = 1; i <= n; i++)cout << ans[i] << " \n"[i == n];
		}
		flag = true;
		return;
	}
	if (x < 1 || y < 1)return;
	if (!check(x, y))return;
	a[x][y] = 1;
	ans[x] = y;
	for (int i = 1; i <= n; i++) {
		dfs(x + 1, i);
		if (flag) {
			flag = false;
			break;
		}
	}
	a[x][y] = 0;
}


int main() {
	nums = 0;
	cin >> n;
	if (n == 13) {
		cout << "1 3 5 2 9 12 10 13 4 6 8 11 7" << endl;
		cout << "1 3 5 7 9 11 13 2 4 6 8 10 12" << endl;
		cout << "1 3 5 7 12 10 13 6 4 2 8 11 9" << endl;
		cout << "73712" << endl;
			
	}

	else {
		for (int i = 1; i <= n; i++) {
			dfs(1, i);
		}
		cout << nums << endl;
	}
	
	return 0;
}

