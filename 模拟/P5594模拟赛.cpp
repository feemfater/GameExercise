#include<bits/stdc++.h>
using namespace std;

const int N = 1.e+3+10;
int n;//n����
int m;//ÿ����Ӧ����m����
int k;//һ����k��

int a[N][N];//������¼ÿ��һ���������Ծ�һ����࿼m��

int main() {
	cin >> n >> m >> k;
	int temp=0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> temp;
			if (a[temp][j]==0)a[temp][j] = 1;//�����һ�쿼ͬһ�ž��ӣ�����Ϊͬһ������
		}
	}
	
	for (int i = 1; i <= k; i++) {
		temp = 0;
		for (auto x : a[i]) {
			temp += x;
		}
		cout << temp << " \n"[i == k];
	}
	return 0;
}

