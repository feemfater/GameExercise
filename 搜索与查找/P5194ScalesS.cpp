#include<bits/stdc++.h>
using namespace std;

//ǰ׺�ͼ�֦+dfs����

const int N = 1.e3 + 10;
int a[N];//���������
long long  sum[N];//ǰ׺��
int n;//���������
int c;//����������
long long ans;//������ϵ��������


void dfs(long long  weight,int index) {
	//weigth:��ǰ����,num:�ڼ�������
	if (weight + sum[index] <= ans)return;//ʣ�µ�ȫ���϶�û�и��������
	if (weight > c)return;
	ans = max(ans, weight);

	if (index ==0)return;

	dfs(weight + a[index], index - 1);
	dfs(weight, index - 1);
}


int main() {
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}

	dfs(0, n);
	cout << ans << endl;
	return 0;
}
