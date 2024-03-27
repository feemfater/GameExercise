#include<bits/stdc++.h>
using namespace std;

int a[13];
int sum;
int remain;

int main() {
	
	int mom = 300;
	for (int i = 1; i <= 12; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= 12; i++) {
		int temp= remain + mom-a[i];
		if (temp < 0) {
			cout << -1 * i << endl;
			return 0;
		}
		remain = temp % 100;
		sum += (temp - remain);
		
	}
	cout << sum * 1.2+remain << endl;
	return 0;
}