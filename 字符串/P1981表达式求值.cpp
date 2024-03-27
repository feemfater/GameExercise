#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	string temp;
	int ans = 0;
	getline(cin, s);
	stack<long long>nums;
	stack<char>chars;
	bool needDo = false;

	for (int i = 0; i <= s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			temp += s[i];
		}
		else {
			long long  need = 0;
			for (int i = 0; i < temp.length(); i++) {
				need = need * 10 + int(temp[i] - '0');
			}
			temp = "";
			nums.push(need%10000);

			if (needDo) {
				long long right = nums.top();
				nums.pop();
				long long left = nums.top();
				nums.pop();
				nums.push((right * left)%10000);
				needDo = false;
			}

			if (s[i] == '*') {
				needDo = true;
			}
			else if (s[i] == '+') {
				chars.push(s[i]);
			}
		}
		
	}


	while (!nums.empty()&&!chars.empty()) {

		char flag = chars.top();
		chars.pop();

		if (flag == '+') {
			long long right = nums.top();
			nums.pop();
			long long left = nums.top();
			nums.pop();
			nums.push((right + left)%10000);
		}
		if (chars.empty())break;
	}

	cout << nums.top() << endl;

	return 0;
}