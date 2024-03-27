#include<bits/stdc++.h>
using namespace std;

const int N = 1.e5 + 10;
int L[N];//left[i]=j,表示第i个同学的左边是第j同学
int R[N];//right[i]=j,表示第i个同学的右边是第j同学
int n;//n个同学
int m;//去掉的同学个数

int main() {
	cin >> n;

	int node = 0;
	int left = 0;

	R[0] = 1;
	for (int i = 2; i <= n; i++) {
		cin >> node >> left;
		int temp = 0;
		//把i同学插入node同学的左边
		if (left == 0) {
			R[i] = node;
			temp = L[node];
			L[i] = temp;
			L[node] = i;
			R[temp] = i;
		
		}
		//把i同学插入node同学的右边
		else {
			L[i] = node;
			temp = R[node];
			R[i] = temp;
			R[node] = i;
			L[temp] = i;

		}
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> node;
		int l = L[node];
		int r = R[node];
		if (l == -1 && r == -1) {
			n++;
			continue;
		}
		L[node] = -1;
		R[node] = -1;
		R[l] = r;
		L[r] = l;
	}

	m = n - m;
	node = 0;
	while (m > 0) {
		cout << R[node]<<" "[m==1];
		node = R[node];
		m--;
	}


	return 0;

}