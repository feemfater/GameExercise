//2017-ʡ��C-С���ѳ��Ȧ
#include<bits/stdc++.h>
using namespace std;

const int N = 100000;
int n;//��¼������Ϸ������
int a[N];//���������ݹ�ϵ
int b[N];//������¼�ýڵ�Ļ����,�����ڻ�������0
int c[N];//��¼�õ��ڻ��е�λ��
int maxs;//�������������Ȧ������


void dfs(int x,int nums,int id) {
	//x�ǵ�ǰ�ڵ㣬nums�ǵ�ǰ����,id�ǻ��ı��

	if (b[x]&&b[x]!=id)return;//���õ��Ѿ��������������˳�
	if (b[x]) {//�ҵ�����
		maxs = max(maxs, nums - c[x]);
		return;
	}
	b[x] = id;
	c[x] = nums;
	dfs(a[x], nums + 1, id);

}


//DFS�һ�����
int main() {
	maxs =0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, 0, i+1);
	}
	cout << maxs << endl;
	return 0;

}