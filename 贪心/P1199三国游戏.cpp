#include<bits/stdc++.h>
using namespace std;

const int N = 600;
int n;//�佫����
int a[N][N];//�佫Ĭ����
int b[N];//�佫ѡ�����飬���佫��ѡ������1������Ϊ0
int ans;//��¼���
int computer;//��¼�����˽��

int main() {
	cin >> n;
	ans = 0;
	computer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cin >> a[i][j];
			a[j][i] = a[i][j];
		}
	}

	//ÿ��ѡ��Ĭ��ֵ�ڶ�����佫����һ���Ĭ�ϻᱻ����ѡ��
	//ѡ���佫��������̶��Ĺ������,С��һ��Ӯ
	//���л�ʤ������У�С������ѡ�����佫��ϵ����Ĭ��ֵ���������еĴδ�ֵ�����

	for (int i = 1; i <= n; i++) {
		sort(a[i] + 1, a[i] + n + 1);
		ans = a[i][n - 1] > ans ? a[i][n - 1] : ans;
	}
	cout << 1 << endl;
	cout << ans << endl;
}