#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int n;//��¼��������
int node[N][3];//��¼����������
double r[N];//��¼������Ƿ�ʹ��,��ʹ�ü�¼�뾶
bool isUse[N];//��¼������Ƿ����ʹ��
double dis[N][N];//��¼��������֮��ľ���,Ԥ����
int maxX;
int minX;
int maxY;
int minY;

double ans;



void dfs(int index,double size) {
	
	if (index > n) {//��������㶼����
		ans = max(ans, size);
		return;
	}

	for (int i = 1; i <= n; i++) {

		if (!isUse[i]) {//δʹ�õ������,�����͵λ��߿�ͣ��
			r[i] = min(
				min(maxX - node[index][1], node[index][1] - minX),
				min(maxY - node[index][2], node[index][2] - minY)
			);

			for (int j = 1; j <= n; j++) {
				//�����͵�ͣ��(�˴��Ƚ����������͵�)
				if (isUse[j]) {
					r[i] = min(r[i], dis[i][j] - r[j]);
				}
			}
			isUse[i] = true;
			if (r[i] < 0) {
				r[i] = 0;
			}

			dfs(index + 1, size + r[i] * r[i] * 3.1415926535);
			isUse[i] = false;
		}
	}
}


int main() {
	cin >> n;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	maxX = max(a, c);
	minX = min(a, c);
	maxY = max(b, d);
	minY = min(b, d);

	for (int i = 1; i <= n; i++) {
		cin >> node[i][1] >> node[i][2];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			dis[i][j] = hypot(node[i][1] - node[j][1], node[i][2] - node[j][2]);
			dis[j][i] = dis[i][j];
		}
	}
	double size = (maxX - minX) * (maxY - minY);
	ans = 0;
	dfs(1, 0.0);
	cout << round(size - ans) << endl;

	return 0;
}