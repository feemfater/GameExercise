//2019-ʡ��B-���ķֽ�

#include<bits/stdc++.h>
using namespace std;

//������ֵ�ÿһλ�������2����4�򷵻�false
bool check(int x) {
	int b = 0;
	while (x) {
		b = x % 10;
		if (b == 2 || b == 4)return false;
		x /= 10;
	}
	return true;
}

//��2019���ɲ�ͬ��������������2����4�ģ��������ж����ַ���
int main() {
	int goal = 2019;
	int count = 0;
	for (int i = 1; i < goal; i++) {
		if (!check(i))continue;
		for (int j = 1; j < goal-i; j++) { //���i=2018����ʱj!<1,ֱ�ӽ���ѭ���������˳���i+j>=2019�����
			int k = 2019 - i - j;
			if (i == j || i == k || j == k)continue;
			if (!check(j)|| !check(k))continue;
			count++;
		}
	}
	count /= 6;
	cout << "result=" << count << endl;
	return 0;
}