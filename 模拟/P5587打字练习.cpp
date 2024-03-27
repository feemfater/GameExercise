#include<bits/stdc++.h>
using namespace std;

const int N = 1.e4+1;
string a[N];
string b[N];

int main() {
	int flag = 0;
	string s;
	getline(cin, s);
	while (s != "EOF") {
		flag++;
		int c = s.find('<');
		while(c != string::npos) {
			if (c == 0)s = s.substr(1);
			else {
				s.erase(c-1, 2);
			}
			c = s.find('<');
		}


		a[flag] = s;
		getline(cin, s);
	}

	int flag2 = 0;
	string s2;
	getline(cin, s2);
	while (s2 != "EOF") {
		flag2++;
		int c = s2.find('<');
		while (c != string::npos) {
			if (c == 0)s2 = s2.substr(1);
			else {
				s2.erase(c - 1, 2);
			}
			c = s2.find('<');
		}
		b[flag2] = s2;
		getline(cin, s2);
	}

	int time = 0;
	cin >> time;

	int nums = 0;
	for (int i = 1; i <= flag; i++) {
		for (int j = 0; j < min(a[i].size(),b[i].size()); j++) {
			if (a[i][j] == b[i][j])nums++;
		}
	}
	if (time == 0)cout << 0 << endl;
	else {
		cout << round(nums * 60.0 / (time+0.0)) << endl;
	}
	return 0;
}