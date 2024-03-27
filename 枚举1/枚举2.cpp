//2020-省赛A-回文日期

#include<bits/stdc++.h>
using namespace std;

//储存日期的每一位
int flag = 0;
int data[8];
int months[13] = {1,31,28,31,30,31,30,31,31,30,31,30,31};

//拆分日期的每一位
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
	//拆分每一个数字
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
				//得到枚举日期
				int result = i * 10000 + j * 100 + k * 1;
				check(result);

				//判断是否为回文日期
				if (::data[0] == ::data[7] &&
					::data[1] == ::data[6] &&
					::data[2] == ::data[5] &&
					::data[3] == ::data[4]) {
					
					
					//判断是否ABABBABA型
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