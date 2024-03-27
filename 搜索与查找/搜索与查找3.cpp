//2017-省赛C-小朋友崇拜圈
#include<bits/stdc++.h>
using namespace std;

const int N = 100000;
int n;//记录参与游戏的人数
int a[N];//用来储存崇拜关系
int b[N];//用来记录该节点的环编号,若不在环中则置0
int c[N];//记录该点在环中的位置
int maxs;//满足条件的最大圈的人数


void dfs(int x,int nums,int id) {
	//x是当前节点，nums是当前边数,id是环的编号

	if (b[x]&&b[x]!=id)return;//若该点已经在其它环中则退出
	if (b[x]) {//找到环边
		maxs = max(maxs, nums - c[x]);
		return;
	}
	b[x] = id;
	c[x] = nums;
	dfs(a[x], nums + 1, id);

}


//DFS找环问题
int main() {
	maxs =0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, 0, i+1);
	}
	cout << maxs << endl;
	return 0;

}