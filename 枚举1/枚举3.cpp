//2016-����C-Ӯ��Ʊ

#include<bits/stdc++.h>
using namespace std;


int nums[100];
int flag[100];

int main() {
	int n = 0;
	int maxResult = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	
	//��n�ֿ�ʼȡ���ķ�ʽ
	for (int i = 0; i < n; i++) {

		//��ʼ��,δȡ����flag��־Ϊ1
		for (int i = 0; i < n; i++) {
			flag[i] = 1;
		}

		int count = 1;
		int result = 0;
		//��ʼö��
		for (int j = i;; j=(j+1)%n) {

			//���count�Ϳ�Ƭ����ƥ��Ϳ��Ʊ�־λ��0
			if (flag[j] == 1) {
				if (count == nums[j]) {
					flag[j] = 0;
					result += nums[j];
					count = 0;
				}
				count++;
			}

			//���п��ƶ�ȡ�������˳�
			int cards = 0;
			for (int k = 0; k < n; k++) {
				cards += flag[k];
			}
			if (cards == 0) {
				break;
				
			}

			//count����ʣ�࿨�Ƶ����ֵ���˳�
			int max = 0;
			for (int k = 0; k < n; k++) {
				if (flag[k] == 1) {
					if (max < nums[k])max = nums[k];
				}
			}
			if (count > max) {
				break;
				
			}
	
		}
		if (maxResult <= result)maxResult = result;
	}

	cout << maxResult << endl;

}