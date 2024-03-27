#include<bits/stdc++.h>
using namespace std;

const int N = 1.e+3+10;
int n;//n个人
int m;//每个人应该做m套题
int k;//一共有k天

int a[N][N];//教练记录每天一共有哪种试卷，一天最多考m套

int main() {
	cin >> n >> m >> k;
	int temp=0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> temp;
			if (a[temp][j]==0)a[temp][j] = 1;//多个人一天考同一张卷子，安排为同一场考试
		}
	}
	
	for (int i = 1; i <= k; i++) {
		temp = 0;
		for (auto x : a[i]) {
			temp += x;
		}
		cout << temp << " \n"[i == k];
	}
	return 0;
}

