#include<bits/stdc++.h>
using namespace std;

long long N;

void show(long long n) {

	

	while (n) {
		// x^y+z
		int x = 0;
		int y = 0;

		x = 1;
		while (x * 2 <= n) {
			y++;
			x *= 2;
		}
		
		if (y != 0 && y != 1) {
			n = (n - x);
			cout << "2(";
			show(y);
			cout << ")";
		}
		
		if (y == 0) {
			cout << "2(0)";
			n -= 1;
		}
		else if (y == 1) {
			cout << 2;
			n -= 2;
		}
		if (n > 0) {
			cout << "+";
		}
	}

}

int main() {
	cin >> N;
	show(N);

}