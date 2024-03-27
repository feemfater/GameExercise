#include<bits/stdc++.h>
using namespace std;


int main() {
	string s;
	string sr=" \n";
	int nums=0;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (count(sr.begin(), sr.end(), s[i]) == 0) {
			nums++;
			sr += s[i];
		}
	}
	cout << nums << endl;
}