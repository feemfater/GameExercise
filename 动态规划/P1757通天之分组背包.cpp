#include<bits/stdc++.h>
using namespace std;

const int N = 1.e3 + 11;
int w[N];//��������
int v[N];//��������ü�ֵ
int c[N];//������������
int dp[N][N];//dp[i][j]Ϊǰi�����������Ϊj����ļ�ֵ���ֵ
int k;//������
int n;//n����Ʒ
int m;//����

int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i] >> c[i];
		k = max(c[i], k);
	}

	for (int i = 1; i <= k; i++) {
		for (int j = m; j >= 0; j--) {
			dp[i][j] = dp[i - 1][j];
			for (int k = 1; k <= n; k++) {
				if (c[k] != i)continue;
				if (w[k] > j)continue;
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[k]] + v[k]);
			}
		}
		
		
	}

	cout << dp[k][m] << endl;

	return 0;

	
}