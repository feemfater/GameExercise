//2018-����C-�Թ�������
#include<bits/stdc++.h>
using namespace std;

//BFS���·��
const int N = 1001;//�Թ�������С
int n;//�Թ���ʵ�ʴ�С
int k;//�����޵в���
struct node{
	int x, y;//(x,y)��ʾ�ƶ�����λ��
	int cnt;//�ƶ�����λ�õĲ���
	int state;//�޵�״̬������=0ʱΪ����״̬
};
int direction[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };//�ƶ����ĸ�����
int a[N][N];//�����Թ�
int vis[N][N];//��¼�����Ƿ����
int s[N][N];//��¼�����ø��ӵ�����޵�״̬��

bool check(int x,int y,int state) {

	//���ɳ����߽�
	if (x<1 || y<1 || x>n || y>n)return false;
	//���ɾ���ǽ��
	if (a[x][y] == 3)return false;
	//���޵в��ɾ�������
	if (state < 1 && a[x][y] == 2)return false;

	return true;
}

//����Ȩͼ����BFS����Ȩ��A*
//BFS����������������㷨֮�����ܹ��ҵ����·��������Ϊ�����������Ա�֤�˴���ʼ�ڵ㵽��Ŀ��ڵ��·���ǰ��ղ��������ӵ�˳����������ġ�
//��BFS�У�����̽����������ʼ�ڵ�ֱ�����ڵĽڵ㣬Ȼ�������չ������ζ�ŵ��״δ���ʼ�ڵ㵽��Ŀ��ڵ�ʱ������·���ĳ��ȱض�����̵ģ���ΪBFS��������Ŀ��ڵ�ʱ��ֹͣ��
int bfs() {
	queue<node>que;
	que.push(node{1,1,0,0});
	vis[1][1] = 1;
	while (!que.empty()) {
		node q = que.front();
		que.pop();
		if (q.x == n && q.y == n)return q.cnt;
		for (int i = 0; i <= 3; i++) {
			int dx = q.x + direction[i][0];
			int dy = q.y + direction[i][1];
			
			if (!check(dx, dy, q.state))continue;
			int nstate = q.state >= 1 ? (q.state - 1) : 0;//״ֻ̬��=0��>=1

			//�����޵п�,����޵�״̬
			if (a[dx][dy] == 1) {
				a[dx][dy] = 0;//�������޵п�����ͨ��
				vis[dx][dy] = 1;//��������Ϊ1
				s[dx][dy] = k;
				que.push(node{ dx,dy,q.cnt + 1,k });
			}
			//������ͨ��
			else {
				//δ��������ͨ��
				if (!vis[dx][dy]) {
					vis[dx][dy] = 1;
					s[dx][dy] = nstate;
					que.push(node{ dx,dy,q.cnt + 1,nstate });
				}
				//�ٴξ���ͬһ��
				else {
					//���޵�״̬������ͬ���ٴξ���
					if (nstate > s[dx][dy]) {
						s[dx][dy] = nstate;
						que.push(node{ dx,dy,q.cnt + 1,nstate });
					}
					else {
						continue;
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			if (c == '.')a[i][j] = 0;
			else if (c == '%')a[i][j] = 1;
			else if (c == 'X')a[i][j] = 2;
			else if (c == '#')a[i][j] = 3;
		}
	}
	cout << bfs() << endl;
}


