#include<bits/stdc++.h>
using namespace std;

const int N = 500;
int n;//ʯͷ����
int a[N];//ʯͷ�ߵ�
long long ans;//�������Ŀǰ���ĵ��������

bool cmp(int x, int y) {
	return x > y;
}

//̰�ģ�ÿ��ѡ��ߵͲ�����ʯͷ��
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
