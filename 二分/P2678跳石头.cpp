#include<bits/stdc++.h>
using namespace std;

const int n = 1.e6;
int L, N, M;
int a[n];

bool check(int x) {

	int s = 0;//��¼����ʯͷ��ľ���
	int num = 0;//����ʯͷ�Ŀ���
	//�������м��<x��ʯͷ
	for (int i = 1; i <= N; i++) {
		if (a[i] - s < x)num++;//�
		else {
			s = a[i];
		}
	}
	if (L - s < x)num++;
	if (num > M)return false;
	return true;
}

int main() {
	cin >> L >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	int l = 1;
	int r = L;
	while (l+1 < r) {
		int mid = (l + r) / 2;
		if (check(mid))l = mid;
		else r = mid;
	}
	if (M==0&&N==0)cout << L << endl;
	else {
		cout << l << endl;
	}
	return 0;
}