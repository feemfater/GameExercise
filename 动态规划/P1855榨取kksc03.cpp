#include<bits/stdc++.h>
using namespace std;

const int N = 1.e3;
int n;//n��Ը��
int M;//mԪ
int T;//T����
int v[N];
int t[N];
int dp[N][N];//dp[i][j]��ʾ����iԪ��j�����¿���ʵ��Ը���������

int main() {
	cin >> n >> M >> T;
	
	for (int i = 1; i <= n; i++) {
		cin >> v[i] >> t[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = M; j >= v[i]; j--) {
			for (int k = T; k >= t[i]; k--) {
				dp[j][k] = max(dp[j][k], dp[j - v[i]][k - t[i]] + 1);
			}
		}
	}

	cout << dp[M][T] << endl;
	return 0;

}