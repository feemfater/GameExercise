#include<bits/stdc++.h>
using namespace std;


//��ά����Ĳ��

const int N = 1.e3 + !0;
int a[N][5];//��¼��̺
int b[N][N];//�������
int ans[N][N];//�������
int n;//n*n�ĸ���
int m;//m����̺

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];

		for (int j = a[i][1]; j <= a[i][3]; j++) {
			b[j][a[i][2]] += 1;
			b[j][a[i][4] + 1] -= 1;
		}

	}
	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans[i][j] = b[i][j] + ans[i][j - 1];
			cout << ans[i][j] << " \n"[j == n];
		}
	}

	return 0;
}
