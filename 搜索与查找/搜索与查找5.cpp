//2019-ʡ��C-ɨ�ػ�����
#include<bits/stdc++.h>
using namespace std;

//̰��
const int N = 1e5 + 10;
int n;//n������,1-n
int k;//k̨������
int a[N];//��¼k̨�����˵ĳ�ʼλ��

//����������������ÿ̨����������������߿飬�����������������ұ�(���ṩ��ʱ���ڣ�
// ����ߵĻ�����һ��Ҫ��������ߵ��������Ҫ�ұ߻����˴�ɨ��϶���ʱ����)
bool check(int time) {
	int pos = 0;//pos��ʾ1--pos�����Ѿ�����ɨ,pos+1--n����δ��ɨ
	//����n̨������
	for (int i = 1; i <= k; i++) {
		int t = time;
		//������ߵ�,��ʱ�䲻�����˳�
		if (pos < a[i])t -= (a[i] - pos - 1) * 2;
		if (t < 0)return false;
		//��������������ұ�
		pos = a[i] + t / 2;
	}
	//���Ҳû����������������
	if (pos < n)return false;

	//��������������
	return true;
}

int main() {
	cin >> n >> k;//��������ͻ���������
	//���������λ��
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + k);//��С��������
	int time = 2 * n;
	for (int i = 1; i <= 4*n; i++) {
		if (!check(i))continue;
		time = i;
		break;
	}
	cout << time << endl;

}

