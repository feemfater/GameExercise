#include<bits/stdc++.h>
using namespace std;

const int N = 3 * 1.e3 + 10;
const long long mod = 1.e8;
int n;//nͷ��ţ
int f;//��������(�����������������f�ı���)
int r[N];//��ţ������
long long dp[N][N];//dp[i][j]:������%FΪj�����ǰiͷţѡ�����󷽰���
int ans;


/*
void dfs(int y, int x) {
	//x����ţ�±꣬y�������������
	if (x > n)return;
	if (x == n) {
		if (y!=0 && y % f == 0) {
			ans++;
			ans %= mod;
		}
		return;
	}
	dfs(y, x + 1);
	dfs(y + r[x + 1], x + 1);
}
	
*/


int main() {
	cin >> n >> f;
	for (int i = 1; i <= n; i++) {
		cin >> r[i];
		r[i] %= f;
		dp[i][r[i]] = 1;
	}
	
	//01�����ⷨ
	for (int i = 1; i <= n; i++) {
		for (int j = f - 1; j >= 0; j--) {

			dp[i][j] = ((dp[i][j]+ dp[i - 1][j]) % mod + (dp[i - 1][(j - r[i] + f) % f])) % mod;
		}
	}



	cout << dp[n][0] << endl;
}