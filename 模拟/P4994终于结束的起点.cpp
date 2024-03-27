#include <bits/stdc++.h>
using namespace std;
long long n, k, ans = 0, s[10000000];
int main() {
	cin >> n;
	s[1] = 1;
	s[2] = 2;
	for (int i = 2; i <= 10000000; i++) {
		s[i] = s[i - 1] + s[i - 2];
		s[i] %= n;
		if (s[i] == 1) {
			if (s[i - 1] == 0) {
				cout << i - 1;
				return 0;
			}
		}
	}


	return 0;
}