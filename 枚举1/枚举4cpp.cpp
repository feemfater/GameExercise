//2020-ʡ��A-��Լ����
#include<bits/stdc++.h>
using namespace std;


//ŷ������㷨�����Լ��
//�������������Լ���������н�С���Ǹ���������������������Լ��
//gcd(a,b)=gcd(b,a mod b)
int calucate(int x,int y) {
	int first = (x > y) ? x : y;//����
	int Second = (x < y) ? x : y;//С��
	int r = 0;//����
	while (Second) {
		r = first % Second;
		first = Second;
		Second = r;
	}
	return first;//��b=0ʱ��a�������Լ��
}

int main() {
	int count = 0;//ͳ�Ƽ�Լ����
	//���ӷ�ĸ�����Լ��Ϊ1��Ϊ��Լ����
	for (int i = 1; i <= 2020; i++) {
		for (int j = 1; j <= 2020; j++) {
			if (i == 1 || j == 1)count++;
			else {
				if (calucate(i, j) == 1)count++;
			}
		}
	}
	cout << "result=" << count << endl;
	return 0;
}