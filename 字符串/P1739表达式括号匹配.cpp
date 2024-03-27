#include<bits/stdc++.h>
using namespace std;


int main() {
	string s;
	getline(cin, s);
	int left = 0;
	int right = 0;
	bool flag = true;
	for (int i = 0; i < s.length(); i++) {
		if (right > left) { flag = false; break; }
		if (s[i] == '(')left++;
		if (s[i] == ')')right++;
	}
	if (left != right)flag = false;
	if (flag == false)cout << "NO" << endl;
	else {
		cout << "YES" << endl;
	}
}