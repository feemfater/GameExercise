#include<bits/stdc++.h>
using namespace std;

const int N = 1.e6;
long long n;//����Ʒ�ܼ���
long long w;//ÿ�����Ʒ�۸�֮�͵�����
int a[N];//ÿ����Ʒ�ļ۸�
int ans;


int main() {

	cin >> w;
	cin >> n;
	ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);//��С��������
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