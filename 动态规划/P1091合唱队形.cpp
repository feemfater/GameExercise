#include<bits/stdc++.h>
using namespace std;

const int N = 1.e3;
int n;//n��ͬѧ
int a[N];//n��ͬѧ�����
int b[N];//a�ĵ���
int dp[N];//��i����Ϊ��β������������еĳ���
int pd[N];//��i����Ϊ��β����½������еĳ���
int ans;//������Ҫͬѧ��


bool cmp(int a, int b) {
	return a > b;
}

//ans=n-max(��i��β������������� + ��i��β����½�������-1)
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = 1;
		pd[i] = 1;
	}

	//�����������
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (a[i] > a[j]) {
				
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	//��½������о��ǰ�����ת�ã��������������
	for (int i = 1; i <= n; i++) {
		b[i] = a[n - i+1];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (b[i] > b[j]) {

				pd[i] = max(pd[i], pd[j] + 1);
			}
		}
	}

	ans = 0;
	for (int i = 1; i <= n; i++) {

		ans = max(ans, dp[i] + pd[n - i + 1] - 1);
	}


	
	cout << n - ans << endl;

	return 0;

	
}