#include<bits/stdc++.h>
using namespace std;

const int N = 1.e6;
struct node {
	double x;
	double y;
};
long long  n;
double ans;
node a[N];


bool cmp(node L, node R) {
	if (L.x == R.x)return L.y < R.y;
	else {
		return L.x < R.y;
	}
}

int main() {
	ans = 0x3f3f3f3f3f3f;
	cin >> n;
	//输入图的多节点
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	//竖向区分多节点的x，y坐标
	sort(a + 1, a + 1 + n, cmp);

	long long counts = n < 10 ? n : 10;
	for (int i = 1; i < counts; i++) {
		for (int j = 1 + i; j <= counts; j++) {
			double temp = hypot(a[i].x - a[j].x, a[i].y - a[j].y);
			ans = temp < ans ? temp : ans;
		}
	}
	cout << setiosflags(ios::fixed);
	cout << setprecision(4) << ans << endl;
	return 0;

}
