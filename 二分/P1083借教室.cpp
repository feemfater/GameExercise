#include<bits/stdc++.h>
using namespace std;

const int N = 1.e6+10;
long long  n;//����
long long m;//��������
long long a[N][4];//��¼����,���������迪ʼ��������
long long day[N];//ÿ������Ľ�������
long long cha[N];//�������,S[i]-S[i-1]=cha[i]
long long S[N];//��¼ÿ����Ҫ�Ľ�����

bool check(long long  mid) {
	//���ʵ�ֵ��Ƕ�һ�����������ֵ�ļӼ�,
	// �����S����i--j�����ֵ��+2
	//ʵ�����޸ĺ� S[i+1]-S[i]=(S[i+1]+2)-(S[i]+2)=cha[i+1]
	//cha[i+1]��û���޸�,������Ԫ�صĲ��ǲ����
	//ʵ���ϱ仯���� S[i]+2 -S[i-1]= cha[i]+2
	// S[j+1] - (S[j]+2) = cha[j+1] - 2

	//�˴���cha��ֵ��Ϊ0����Ϊ������������Ĳ�ֵ����0
	memset(cha, 0, sizeof(cha));
	memset(S, 0, sizeof(S));

	for (int i = 1; i <= mid; i++) {
		cha[a[i][2]] += a[i][1];
		cha[a[i][3] + 1] -= a[i][1];
	}

	for (int i = 1; i <= n; i++) {
		S[i] = S[i - 1] + cha[i];
		if (S[i] > day[i]) {
			return false;
		}
	}


	return true;
}


int main() {
	ios::sync_with_stdio(false);                         //����Ϊ��Щ������cin��ô��
	cin.tie(0);                                          //����Ҫ�ص�ͬ����
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> day[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	

	long long  L = 0;
	long long  R = m+1;

	while (L + 1 < R) {
		long long mid = (L + R) / 2;
		if (check(mid))L = mid;
		else {
			R = mid;
		}
	}

	if (L==m) {
		cout << "0" << endl;
	}
	else {
		cout << "-1" << endl;
		cout << L+1 << endl;
	}
	return 0;
}
