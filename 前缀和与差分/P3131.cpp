#include<bits/stdc++.h>
using namespace std;

const int N = 1.e6 + 10;
long long a[N];//记录数组
long long sum[N];//记录前缀和
long long ans;//记录结果
long long n;//记录行数

long long first[N];//0--6的第一次出现
long long last[N];//0---6的最后一次出现

//如果(sum[i]-sum[j]) %7=0,那么sum[i]%7==sum[j]%7
//所以要找到最大区间，
//只要找到余数是0--6的第一次和最后一次出现的区间的最大值

int main() {
	ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = (sum[i - 1] + a[i])%7;
		if (first[sum[i]] == 0) {
			first[sum[i]] = i;
		}
		else {
			last[sum[i]] = i;
		}
	}


	for (int i = 0; i <= 6; i++) {
		long long temp = last[i] - first[i];
		ans = temp > ans ? temp : ans;
	}



	cout << ans << endl;
	

	return 0;
}