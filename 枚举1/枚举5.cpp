//2019-省赛B-数的分解

#include<bits/stdc++.h>
using namespace std;

//检查数字的每一位，如果有2或者4则返回false
bool check(int x) {
	int b = 0;
	while (x) {
		b = x % 10;
		if (b == 2 || b == 4)return false;
		x /= 10;
	}
	return true;
}

//求2019拆解成不同的三个（不包含2或者4的）正整数有多少种方法
int main() {
	int goal = 2019;
	int count = 0;
	for (int i = 1; i < goal; i++) {
		if (!check(i))continue;
		for (int j = 1; j < goal-i; j++) { //最大到i=2018，此时j!<1,直接结束循环，避免了出现i+j>=2019的情况
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