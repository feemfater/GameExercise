#include<bits/stdc++.h>
using namespace std;

const int N = 1.e6+10;
long long  n;//天数
long long m;//订单数量
long long a[N][4];//记录订单,租借数，租借开始，租借结束
long long day[N];//每天可租借的教室数量
long long cha[N];//差分数组,S[i]-S[i-1]=cha[i]
long long S[N];//记录每天需要的教室数

bool check(long long  mid) {
	//拆分实现的是对一个数组区间的值的加减,
	// 比如对S数组i--j区间的值都+2
	//实际上修改后 S[i+1]-S[i]=(S[i+1]+2)-(S[i]+2)=cha[i+1]
	//cha[i+1]并没有修改,区间内元素的差是不变的
	//实践上变化的是 S[i]+2 -S[i-1]= cha[i]+2
	// S[j+1] - (S[j]+2) = cha[j+1] - 2

	//此处的cha初值都为0，因为单个订单区间的差值都是0
	memset(cha, 0, sizeof(cha));
	memset(S, 0, sizeof(S));

	for (int i = 1; i <= mid; i++) {
		cha[a[i][2]] += a[i][1];
		cha[a[i][3] + 1] -= a[i][1];
	}

	for (int i = 1; i <= n; i++) {
		S[i] = S[i - 1] + cha[i];
		if (S[i] > day[i]) {
			return false;
		}
	}


	return true;
}


int main() {
	ios::sync_with_stdio(false);                         //就因为这些东西害cin那么慢
	cin.tie(0);                                          //所以要关掉同步流
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> day[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	

	long long  L = 0;
	long long  R = m+1;

	while (L + 1 < R) {
		long long mid = (L + R) / 2;
		if (check(mid))L = mid;
		else {
			R = mid;
		}
	}

	if (L==m) {
		cout << "0" << endl;
	}
	else {
		cout << "-1" << endl;
		cout << L+1 << endl;
	}
	return 0;
}
