#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	string temp;
	stack<int> p;
	getline(cin,s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '@')break;
		if (s[i] >= '0' && s[i] <= '9') {
			temp += s[i];
		}
		else if (s[i] == '.') {
			int nums = 0;
			for (int j =0; j < temp.length(); j++) {
				nums = 10 * nums + int(temp[j] - '0');
			}
			temp = "";
			p.push(nums);
		}
		else if (s[i] == '+') {
			int right = p.top();
			p.pop();
			int left = p.top();
			p.pop();
			p.push(left + right);
		}
		else if(s[i]=='-'){
			int right = p.top();
			p.pop();
			int left = p.top();
			p.pop();
			p.push(left - right);
		}
		else if (s[i] == '*') {
			int right = p.top();
			p.pop();
			int left = p.top();
			p.pop();
			p.push(left * right);
		}
		else if (s[i] == '/') {
			int right = p.top();
			p.pop();
			int left = p.top();
			p.pop();
			p.push(left / right);
		}
	}
	int ans = p.top();
	cout << ans << endl;
	return 0;
}