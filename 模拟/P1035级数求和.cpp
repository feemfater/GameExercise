#include<bits/stdc++.h>
using namespace std;

int k;
double sum;
int main() {
	sum = 0;
	int flag = 0;
	cin >> k;
	while (sum <= k) {
		flag++;
		sum = sum + (1.0 / flag);
		
	}
	cout << flag << endl;
}