#include<bits/stdc++.h>
using namespace std;

const int n = 1.e6;
int L, N, M;
int a[n];

bool check(int x) {

	int s = 0;//记录两块石头间的距离
	int num = 0;//移走石头的块数
	//移走所有间距<x的石头
	for (int i = 1; i <= N; i++) {
		if (a[i] - s < x)num++;//妙啊
		else {
			s = a[i];
		}
	}
	if (L - s < x)num++;
	if (num > M)return false;
	return true;
}

int main() {
	cin >> L >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	int l = 1;
	int r = L;
	while (l+1 < r) {
		int mid = (l + r) / 2;
		if (check(mid))l = mid;
		else r = mid;
	}
	if (M==0&&N==0)cout << L << endl;
	else {
		cout << l << endl;
	}
	return 0;
}