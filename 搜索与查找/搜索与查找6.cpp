//2021-国赛A-123
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;//最大行数
int T;//实际行数
int a[N][2];//储存输入

//num1=n1*(1+n1)/2 +k1
int calucate(int num1, int num2) {
	int x = num1;
	int y = num2;
	int n1, n2, k1, k2;
	int sum = 0;

	if (num1 == 1) {
		n1 = 0;
		k1 = 1;
	}
	if (num2 == 1) {
		n1 = 0;
		k1 = 1;
	}
	
	if (x == y && x == 1) {
		sum += 1;
		return sum;
	}

	for (int i = 2; i <= x; i++) {
	
		k1 = (x - (i * (1 + i) / 2)) % i;
		if (k1<i) {
			n1 = i;
			break;
		}
	}
	for (int i = 2; i <= y; i++) {
		k2 = (y - (i * (1 + i) / 2)) % i;
		if (k2 < i) {
			n2 = i;
			break;
		}
	}

	

	if (n1 == n2) {
		for (int i = k1; i <= k2; i++) {
			sum += i;
		}
	}
	if (n2 > n1) {
		for (int i = n1 + 1; i <= n2; i++) {
			sum += i * (i + 1) / 2;
		}
		sum -= k1 * (1 + k1) / 2;
		sum += k2 * (1 + k2) / 2;
	}
	return sum;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	for (int i = 0; i < T; i++) {
		cout << calucate(a[i][0], a[i][1]) << endl;
	}

}