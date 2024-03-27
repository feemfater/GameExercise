#include<bits/stdc++.h>
using namespace std;

int a[3][2];
int sum[3];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 3; i++) {


		cin >> a[i][0] >> a[i][1];
		int b = n / a[i][0];
		b = n % a[i][0] == 0 ? b : b + 1;
		sum[i] = b * a[i][1];
	}
	sort(sum, sum + 3);
	cout << sum[0] << endl;
	return 0;
}