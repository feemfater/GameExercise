//2020-ʡ��A-��������

#include<bits/stdc++.h>
using namespace std;

//�������ڵ�ÿһλ
int flag = 0;
int data[8];
int months[13] = {1,31,28,31,30,31,30,31,31,30,31,30,31};

//������ڵ�ÿһλ
void check(int num) {
	for (int i = 7; i >= 0; i--) {
		int m = num % 10;
		::data[i] = m;
		num /= 10;
	}
}

int main() {

	for (int i = 0; i < 8; i++) {
		::data[i] = 1;
	}
	int input = 20200202;
	//���ÿһ������
	check(input);
	int year = ::data[0] * 1000 + ::data[1] * 100 + ::data[2] * 10 + ::data[3] * 1;
	int month = ::data[4] * 10 + ::data[5] * 1;
	int day = ::data[6] * 10 + ::data[7] * 1;
	
	for (int i = year; ; i++) {
		if (i % 400 == 0 || i % 4 == 0 && i % 100 != 0) {
			months[2] = 28;
		}
		else {
			months[2] = 29;
		}

		int j = 0;
		if (i == year) {
			j = month;
		}
		else {
			j = 1;
		}

		for (; j <= 12; j++) {

			int k = 0;
			if (i == year && j == month) {
				k = day+1;
			}
			else {
				k = 1;
			}

			for (; k < months[j]; k++) {
				//�õ�ö������
				int result = i * 10000 + j * 100 + k * 1;
				check(result);

				//�ж��Ƿ�Ϊ��������
				if (::data[0] == ::data[7] &&
					::data[1] == ::data[6] &&
					::data[2] == ::data[5] &&
					::data[3] == ::data[4]) {
					
					
					//�ж��Ƿ�ABABBABA��
					if (::data[0] == ::data[2] && ::data[1] == ::data[3]) {
						cout << result << endl;
						return 0;
					}

					if (flag == 0) {
						cout << result << endl;
						flag++;
					}
					continue;
				}
				
			}
		}
	}

}