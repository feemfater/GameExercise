#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int x;
	string s;
	cin >> n>>x;
	for (int i = 1; i <= n; i++) {
		s += to_string(i);
	}
	cout << count(s.begin(),s.end(),x+'0');
}