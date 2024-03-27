#include<bits/stdc++.h>
using namespace std;

const int n = 1.e6 + 10;
int a[n];
int N;
int M;

bool check(int x) {
	int sum=0;
	for (int i = 1; i <= N; i++) {
		if (a[i] > x) {
			sum += (a[i] - x);
		}
		if(sum>=M)return true;
	}
	return false;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + N + 1);
	int l = 1;
	int r = a[N];
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		if (check(mid))l = mid;
		else {
			r = mid;
		}
	}
	cout << l;
}