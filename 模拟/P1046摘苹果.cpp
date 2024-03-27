#include<bits/stdc++.h>
using namespace std;

int a[11];
int nums;

int main() {
	int height = 30;
	nums = 0;
	int hand = 0;
	for (int i = 1; i <= 10; i++) {
		cin >> a[i];
	}
	cin >> hand;
	height = hand + height;
	for (int i = 1; i <= 10; i++) {
		if (height >= a[i])nums++;
	}
	cout << nums << endl;
	return 0;
}