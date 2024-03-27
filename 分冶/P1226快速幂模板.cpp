#include<bits/stdc++.h>
using namespace std;

//快速幂模板，a^b mod p,多次取模结果相乘和一次取模结果相同，多次取模可以避免溢出
long long a, b, p, ans;

long long calucate(long long x, long long y) {
	if (y == 0)return 1;
	if (y % 2 != 0)return calucate(x, y - 1) * x %p;
	else {
		long long temp = calucate(x, y / 2)%p;
		return temp * temp%p;
	}
}

int main() {

	cin >> a >> b >> p;
	ans = calucate(a, b);
	cout << a << "^" << b << " mod " << p << "=" << ans;
	return 0;
}
