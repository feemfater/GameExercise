#include<bits/stdc++.h>
using namespace std;

//01��������
const int N = 3*1.e4 + 10;
int n;//��Ǯ��
int m;//ϣ���������Ʒ��
int v[N];//�۸�
int w[N];//��Ҫ��(��ֵ=�۸�*��Ҫ��)
int dp[N];//dp[i]������Ǯ��Ϊi������¼�ֵ���ֵ


int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> v[i] >> w[i];
		w[i] = w[i] * v[i];//��ֵ
	}

	
	for (int i = 1; i <= m; i++) {
		for (int j = n; j >= v[i]; j--) {
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
		}
	}
	cout << dp[n] << endl;	
	
	
	return 0;
	
	
}