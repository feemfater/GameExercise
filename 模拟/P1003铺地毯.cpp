#include<bits/stdc++.h>
using namespace std;

const int N = 1.e4 + 10;
int a[N][5];//记录毯子的位置与大小;
int n;
int A;//地面点
int B;
int nums;

int main() {
	nums = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
		
	}
	cin >> A >> B;
	for (int i = 1; i <= n; i++) {
		if ((A >= a[i][1] && A <= (a[i][1] + a[i][3])) &&
			(B >= a[i][2] && B <= (a[i][2] + a[i][4]))) {
			nums = i;
		}
	}

	if (nums == 0)cout << -1 << endl;
	else {
		cout << nums << endl;
	}

	return 0;
}