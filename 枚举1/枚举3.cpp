//2016-国赛C-赢球票

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

	
	//有n种开始取卡的方式
	for (int i = 0; i < n; i++) {

		//初始化,未取出，flag标志为1
		for (int i = 0; i < n; i++) {
			flag[i] = 1;
		}

		int count = 1;
		int result = 0;
		//开始枚举
		for (int j = i;; j=(j+1)%n) {

			//如果count和卡片数字匹配就卡牌标志位置0
			if (flag[j] == 1) {
				if (count == nums[j]) {
					flag[j] = 0;
					result += nums[j];
					count = 0;
				}
				count++;
			}

			//所有卡牌都取出，则退出
			int cards = 0;
			for (int k = 0; k < n; k++) {
				cards += flag[k];
			}
			if (cards == 0) {
				break;
				
			}

			//count大于剩余卡牌的最大值则退出
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