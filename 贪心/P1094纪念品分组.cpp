#include<bits/stdc++.h>
using namespace std;

const int N = 1.e6;
long long n;//纪念品总件数
long long w;//每组纪念品价格之和的上限
int a[N];//每件礼品的价格
int ans;


int main() {

	cin >> w;
	cin >> n;
	ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);//从小到大排序
	int L = 1;
	int R = n;
	while (L < R) {
		int temp = a[L] + a[R];
		if (temp <= w) {
			++L;
		}
		--R;
		++ans;
	}
	if (L == R)ans++;
	cout << ans << endl;

}