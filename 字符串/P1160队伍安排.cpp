#include<bits/stdc++.h>
using namespace std;

const int N = 1.e5 + 10;
int L[N];//left[i]=j,��ʾ��i��ͬѧ������ǵ�jͬѧ
int R[N];//right[i]=j,��ʾ��i��ͬѧ���ұ��ǵ�jͬѧ
int n;//n��ͬѧ
int m;//ȥ����ͬѧ����

int main() {
	cin >> n;

	int node = 0;
	int left = 0;

	R[0] = 1;
	for (int i = 2; i <= n; i++) {
		cin >> node >> left;
		int temp = 0;
		//��iͬѧ����nodeͬѧ�����
		if (left == 0) {
			R[i] = node;
			temp = L[node];
			L[i] = temp;
			L[node] = i;
			R[temp] = i;
		
		}
		//��iͬѧ����nodeͬѧ���ұ�
		else {
			L[i] = node;
			temp = R[node];
			R[i] = temp;
			R[node] = i;
			L[temp] = i;

		}
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> node;
		int l = L[node];
		int r = R[node];
		if (l == -1 && r == -1) {
			n++;
			continue;
		}
		L[node] = -1;
		R[node] = -1;
		R[l] = r;
		L[r] = l;
	}

	m = n - m;
	node = 0;
	while (m > 0) {
		cout << R[node]<<" "[m==1];
		node = R[node];
		m--;
	}


	return 0;

}