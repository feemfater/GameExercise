//2015-省赛A-穿越雷区

#include<bits/stdc++.h>
using namespace std;



const int N = 100;//矩阵最大值 
int a[N][N];//储存输入矩阵
int n;//矩阵实际大小
int ans;//最短步数
int vis[N][N];//到该位置所用步数

//记录A,B的位置
pair<int, int>A;
pair<int, int>B;

void dfs(int x, int y, int cnt) {
	//(x,y)表示当前坐标,cnt表示到该点的步数
	if (cnt > ans)return;//如果当前步数大于最短步数就退出
	if (cnt > vis[x][y])return;//如果当前步数大于之前到该位置的步数则退出
	if (x >= n || x < 0 || y >= n || y < 0)return;//如果当前位置超出了边界则退出
	if (x == B.first && y == B.second) {
		//当前位置为B点时，完成
		ans = cnt;
		return;
	}

	//进行dfs搜索
	//每次都必须去相反的能量处
	vis[x][y] = cnt;

	int dx = x - 1;
	int dy = y;
	if (a[x][y] != a[dx][dy])dfs(dx, dy, cnt+1);

	dx = x + 1;
	dy = y;
	if (a[x][y] != a[dx][dy])dfs(dx, dy, cnt + 1);

	dx = x;
	dy = y - 1;
	if (a[x][y] != a[dx][dy])dfs(dx, dy, cnt + 1);

	dx = x;
	dy = y + 1;
	if (a[x][y] != a[dx][dy])dfs(dx, dy, cnt + 1);

}

int main() {
	cin >> n;
	ans = 0x3f3f3f3f;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			vis[i][j] = ans;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char x;
			cin >> x;
			if (x == 'A') {
				A.first = i;
				A.second = j;
				a[i][j] = -1;
			}
			if (x == 'B') {
				B.first = i;
				B.second = j;
				a[i][j] = -1;
			}
			if (x == '+') {
				a[i][j] = 1;
			}
			if (x == '-') {
				a[i][j] = 0;
			}
		}
	}

	dfs(A.first,A.second,0);

	cout << ans << endl;
	return 0;
}
