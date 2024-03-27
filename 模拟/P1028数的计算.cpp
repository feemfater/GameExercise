#include<bits/stdc++.h>
using namespace std;

int nums;
const int N = 1.e3 + 10;
int n;
int a[N];
//µÝ¹é
void check(int x) {
	nums++;
	for (int i = 1; i <= x / 2; i++) {
		check(i);

	}
	return;
}

//µÝÍÆ
void check2(int x) {
	if (x % 2 == 0) {
		a[x] = a[x / 2] + a[x - 1];
	}
	else {
		a[x] = a[x - 1];
	}
}

int main() {
	nums = 0;
	/*
	int x;
	cin >> x;
	check(x);
	*/
	cin >> n;
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i <= n; i++) {
		check2(i);
	}

	cout << a[n] << endl;
	return 0;
}