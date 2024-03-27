#include<bits/stdc++.h>
using namespace std;

const int N = 1.e5;
int father[N];//father[i]=j,i号战舰在j号战舰后面
int dis[N];//dis[i]=j :记录i号战舰距离所在列头的距离
int nums[N];//记录第i列有多少战舰
long long T;//指令数量


//带权并查集

int find(int x) {
	if (x == father[x])return x;
	else {
		int fah=father[x];
		father[x] = find(father[x]);
		dis[x] += dis[fah];
		nums[x] = nums[father[x]];
		return father[x];
	}
	
}

void megre(int x, int y) {
	int father1 = find(x);
	int father2 = find(y);
	if (father1 != father2) {
		father[father1] = father2;
		dis[father1] = dis[father2] + nums[father2];
		nums[father2] += nums[father1];
		nums[father1] = nums[father2];
	}
}


int betweens(int x, int y) {
	
	int r1 = find(x);
	int r2 = find(y);
	if (r1 != r2) {
		return -1;
	}
	return abs(dis[x] - dis[y]) - 1;
}




int main() {


	cin >> T;
	char s;
	int x;
	int y;

	for (int i = 1; i <= 3 * 1.e4; i++) {
		father[i] = i;
		nums[i] = 1;
		dis[i] = 0;
	}

	for (int i = 1; i <= T; i++) {
		cin >> s >> x >> y;
		if (s == 'M') {
			megre(x, y);
		}
		else {
			cout << betweens(x, y) << endl;
		}
	}
}