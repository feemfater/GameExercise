#include<bits/stdc++.h>
using namespace std;

const int N = 1.e2+10;
int n, m;
int a[N];
bool used[N];

int main() {
	cin >> n >> m;
	int counts = 0;
	int flag = 0;
	while (flag != n) {
		for (int i = 1; i <= n; i++) {
			if (used[i])continue;
			counts++;
			if (counts == m) {
				counts = 0;
				used[i] = true;
				flag++;
				cout << i << " "[flag == n];
			}
		}
	}
	return 0;
	
}