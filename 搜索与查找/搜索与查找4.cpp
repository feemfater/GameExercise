//2018-国赛C-迷宫与陷阱
#include<bits/stdc++.h>
using namespace std;

//BFS最短路径
const int N = 1001;//迷宫的最大大小
int n;//迷宫的实际大小
int k;//设置无敌步数
struct node{
	int x, y;//(x,y)表示移动到的位置
	int cnt;//移动到该位置的步数
	int state;//无敌状态步数，=0时为正常状态
};
int direction[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };//移动的四个方向
int a[N][N];//储存迷宫
int vis[N][N];//记录格子是否访问
int s[N][N];//记录经过该格子的最大无敌状态数

bool check(int x,int y,int state) {

	//不可超出边界
	if (x<1 || y<1 || x>n || y>n)return false;
	//不可经过墙壁
	if (a[x][y] == 3)return false;
	//非无敌不可经过陷阱
	if (state < 1 && a[x][y] == 2)return false;

	return true;
}

//在无权图中用BFS，有权用A*
//BFS（广度优先搜索）算法之所以能够找到最短路径，是因为它的搜索策略保证了从起始节点到达目标节点的路径是按照步数逐渐增加的顺序进行搜索的。
//在BFS中，首先探索所有与起始节点直接相邻的节点，然后逐层扩展。这意味着当首次从起始节点到达目标节点时，搜索路径的长度必定是最短的，因为BFS在搜索到目标节点时就停止了
int bfs() {
	queue<node>que;
	que.push(node{1,1,0,0});
	vis[1][1] = 1;
	while (!que.empty()) {
		node q = que.front();
		que.pop();
		if (q.x == n && q.y == n)return q.cnt;
		for (int i = 0; i <= 3; i++) {
			int dx = q.x + direction[i][0];
			int dy = q.y + direction[i][1];
			
			if (!check(dx, dy, q.state))continue;
			int nstate = q.state >= 1 ? (q.state - 1) : 0;//状态只有=0和>=1

			//遇到无敌块,获得无敌状态
			if (a[dx][dy] == 1) {
				a[dx][dy] = 0;//经过的无敌块变成普通块
				vis[dx][dy] = 1;//经过后标记为1
				s[dx][dy] = k;
				que.push(node{ dx,dy,q.cnt + 1,k });
			}
			//遇到普通块
			else {
				//未经过的普通块
				if (!vis[dx][dy]) {
					vis[dx][dy] = 1;
					s[dx][dy] = nstate;
					que.push(node{ dx,dy,q.cnt + 1,nstate });
				}
				//再次经过同一块
				else {
					//若无敌状态增加则同意再次经过
					if (nstate > s[dx][dy]) {
						s[dx][dy] = nstate;
						que.push(node{ dx,dy,q.cnt + 1,nstate });
					}
					else {
						continue;
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			if (c == '.')a[i][j] = 0;
			else if (c == '%')a[i][j] = 1;
			else if (c == 'X')a[i][j] = 2;
			else if (c == '#')a[i][j] = 3;
		}
	}
	cout << bfs() << endl;
}


