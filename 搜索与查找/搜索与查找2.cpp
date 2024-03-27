//2015-ʡ��A-��Խ����

#include<bits/stdc++.h>
using namespace std;



const int N = 100;//�������ֵ 
int a[N][N];//�����������
int n;//����ʵ�ʴ�С
int ans;//��̲���
int vis[N][N];//����λ�����ò���

//��¼A,B��λ��
pair<int, int>A;
pair<int, int>B;

void dfs(int x, int y, int cnt) {
	//(x,y)��ʾ��ǰ����,cnt��ʾ���õ�Ĳ���
	if (cnt > ans)return;//�����ǰ����������̲������˳�
	if (cnt > vis[x][y])return;//�����ǰ��������֮ǰ����λ�õĲ������˳�
	if (x >= n || x < 0 || y >= n || y < 0)return;//�����ǰλ�ó����˱߽����˳�
	if (x == B.first && y == B.second) {
		//��ǰλ��ΪB��ʱ�����
		ans = cnt;
		return;
	}

	//����dfs����
	//ÿ�ζ�����ȥ�෴��������
	vis[x][y] = cnt;

	int dx = x - 1;
	int dy = y;
	if (a[x][y] != a[dx][dy])dfs(dx, dy, cnt+1);

	dx = x + 1;
	dy = y;
	if (a[x][y] != a[dx][dy])dfs(dx, dy, cnt + 1);

	dx = x;
	dy = y - 1;
	if (a[x][y] != a[dx][dy])dfs(dx, dy, cnt + 1);

	dx = x;
	dy = y + 1;
	if (a[x][y] != a[dx][dy])dfs(dx, dy, cnt + 1);

}

int main() {
	cin >> n;
	ans = 0x3f3f3f3f;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			vis[i][j] = ans;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char x;
			cin >> x;
			if (x == 'A') {
				A.first = i;
				A.second = j;
				a[i][j] = -1;
			}
			if (x == 'B') {
				B.first = i;
				B.second = j;
				a[i][j] = -1;
			}
			if (x == '+') {
				a[i][j] = 1;
			}
			if (x == '-') {
				a[i][j] = 0;
			}
		}
	}

	dfs(A.first,A.second,0);

	cout << ans << endl;
	return 0;
}
