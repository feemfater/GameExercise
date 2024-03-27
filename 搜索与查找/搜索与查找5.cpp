//2019-省赛C-扫地机器人
#include<bits/stdc++.h>
using namespace std;

//贪心
const int N = 1e5 + 10;
int n;//n个区域,1-n
int k;//k台机器人
int a[N];//记录k台机器人的初始位置

//用最优清理方法，即每台机器人优先清理左边块，若左边清理完便清理右边(所提供的时间内，
// 最左边的机器人一定要清理完左边的区域，如果要右边机器人打扫则肯定用时更长)
bool check(int time) {
	int pos = 0;//pos表示1--pos区域已经被打扫,pos+1--n区域未打扫
	//遍历n台机器人
	for (int i = 1; i <= k; i++) {
		int t = time;
		//清理左边的,若时间不够则退出
		if (pos < a[i])t -= (a[i] - pos - 1) * 2;
		if (t < 0)return false;
		//清理完左边清理右边
		pos = a[i] + t / 2;
	}
	//最后也没有清理完所有区域
	if (pos < n)return false;

	//清理完所有区域
	return true;
}

int main() {
	cin >> n >> k;//输入块数和机器人数量
	//输入机器人位置
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + k);//从小到大排序
	int time = 2 * n;
	for (int i = 1; i <= 4*n; i++) {
		if (!check(i))continue;
		time = i;
		break;
	}
	cout << time << endl;

}

