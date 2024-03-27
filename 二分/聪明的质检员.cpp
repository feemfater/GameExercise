#include<bits/stdc++.h>
using namespace std;

//����+ǰ׺��

const int N = 1.e6;
int n;//��ʯ����
int m;//�������
int s;//��־ֵ
int rock[N][3];//��¼ʯͷ
int itval[N][3];//��¼����
long long p[N];//��¼ǰ׺
long long Q[N];//��¼ǰ׺
int ans;
long long need;//��ÿ�εĽ��



bool check(int w) {
	long long sums = 0;
	for (int i = 1; i <= n; i++) {
		if (rock[i][1] >= w) {
			{
				p[i] = 1 + p[i - 1];
				Q[i] = rock[i][2] + Q[i - 1];
			}
		}
		else {
			p[i] = p[i - 1];
			Q[i] = Q[i - 1];
		}
	}
	for (int i = 1; i <= m; i++) {

		int left = itval[i][1] - 1;
		int right = itval[i][2];

		sums += (p[right] - p[left]) * (Q[right] - Q[left]);

	}
	need = llabs(s - sums);
	if (sums > s)return true;
	return false;
}

int main() {
	cin >> n >> m >> s;
	ans = 1.e6;
	int maxM = 0;
	int minM = 1.e6;
	for (int i = 1; i <= n; i++) {
		cin >> rock[i][1] >> rock[i][2];
		if (rock[i][1] > maxM)maxM = rock[i][1];
		if (rock[i][1] < minM)minM = rock[i][1];

	}
	for (int i = 1; i <= m; i++) {
		cin >> itval[i][1] >> itval[i][2];
	}

	int L = minM - 1;
	int R = maxM + 1;
	while (L + 1 < R) {
		int mid = (L + R) / 2;
		if (check(mid))L = mid;
		else {
			R = mid;
		}
		ans = need < ans ? need : ans;
	}
	cout << ans << endl;
}