#include<bits/stdc++.h>
using namespace std;

const int N = 500;
int n;//石头个数
int a[N];//石头高低
long long ans;//结果，即目前消耗的最大体力

bool cmp(int x, int y) {
	return x > y;
}

//贪心，每次选择高低差最大的石头跳
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	
	ans += pow(a[1], 2);

	int L = 1;
	int R = n;
	while (L < R) {
		ans += pow(a[L] - a[R], 2);
		L++;
		ans += pow(a[R] - a[L], 2);
		R--;
	}
	cout << ans << endl;

}
