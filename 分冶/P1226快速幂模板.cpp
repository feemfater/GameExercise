#include<bits/stdc++.h>
using namespace std;

//������ģ�壬a^b mod p,���ȡģ�����˺�һ��ȡģ�����ͬ�����ȡģ���Ա������
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
