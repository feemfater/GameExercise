#include<bits/stdc++.h>
using namespace std;

const int N = 1.e3 + 10;
int t[N];//��ҩʱ��
int v[N];//ҩ�ļ�ֵ
int dp[N];//dp[i]��ʾ��ʱ��i�µļ�ֵ���ֵ
int T;//�ܹ����Բ�ҩ��ʱ��
int M;//ҩ�ĵ���Ŀ

//ֻ������״̬����ʱ�����j������µ�i����ҩ�ɻ��߲���,dp[j]=max(dp[j-t[i]]+v[i],dp[])
int main() {
	cin >> T >> M;
	for (int i = 1; i <= M; i++) {
		cin >> t[i] >> v[i];
	}

	for (int i = 1; i <= M; i++) {
		for (int j = T; j>=t[i]; j--) {
			dp[j] = max(dp[j - t[i]] + v[i], dp[j]);
		}
	}
	cout << dp[T] << endl;
}