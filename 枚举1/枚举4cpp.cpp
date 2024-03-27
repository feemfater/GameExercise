//2020-省赛A-即约分数
#include<bits/stdc++.h>
using namespace std;


//欧几里得算法求最大公约数
//两个整数的最大公约数等于其中较小的那个数和两数相除余数的最大公约数
//gcd(a,b)=gcd(b,a mod b)
int calucate(int x,int y) {
	int first = (x > y) ? x : y;//大数
	int Second = (x < y) ? x : y;//小数
	int r = 0;//余数
	while (Second) {
		r = first % Second;
		first = Second;
		Second = r;
	}
	return first;//当b=0时，a就是最大公约数
}

int main() {
	int count = 0;//统计既约分数
	//分子分母的最大公约数为1则为既约分数
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