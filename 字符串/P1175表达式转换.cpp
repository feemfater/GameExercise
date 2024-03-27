#include<bits/stdc++.h>
using namespace std;

stack<char>s1;//后缀表达式栈
stack<char>s2;//临时的符号栈

int getIndex(char i) {
	switch (i) {
		case '(':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;

	}
}

int main() {
	string s;//记录中缀表达式
	string temp;//记录后缀表达式
	string temp2;//记录计算顺序
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			s1.push(s[i]);
		}
		else {
			if (s[i] == '(') {
				s2.push(s[i]);
			}
			else if (s[i] == ')') {
				while (s2.top() != '(') {
					s1.push(s2.top());
					s2.pop();
				}
				s2.pop();
			}
			else if (s[i] == '^') {
				s2.push(s[i]);
			}
			else {
				while (!s2.empty()) {

					if (getIndex(s[i]) > getIndex(s2.top())) {
						break;
					}
					else {
						s1.push(s2.top());
						s2.pop();
					}
				}
				s2.push(s[i]);
			}
		}
	}

	while (!s2.empty()) {
		s1.push(s2.top());
		s2.pop();
	}

	while (!s1.empty()) {
		char need = s1.top();
		temp+=need;
		temp += ' ';
		s1.pop();
	}
	reverse(temp.begin(),temp.end());
	temp.erase(temp.begin(),temp.begin()+1);
	
	stack<int>s3;

	for (int i = 0; i < temp.length(); i++) {
		if (temp[i] <= '9' && temp[i] >= '0') {
			temp2 += temp[i];
			s3.push(temp[i] - '0');
		}
		else if (temp[i] == ' ') {
			temp2 += temp[i];
		}
		else {
			cout << temp2 + temp.substr(i) << endl;

			int right = s3.top();
			s3.pop();
			int left = s3.top();
			s3.pop();
			int ans = 0;

			if (temp[i] == '+') {
				ans = (left + right);
			}
			else if (temp[i] == '-') {
				ans = (left - right);
			}
			else if (temp[i] == '*') {
				ans = (left * right);
			}
			else if (temp[i] == '/') {
				ans = (left / right);
			}
			else if (temp[i] == '^') {
				ans = pow(left, right);
			}

			s3.push(ans);
			string r = to_string(right);
			string l = to_string(left);
			string a = to_string(ans);
			temp2.erase(temp2.end()-(r.length()+l.length()+2), temp2.end());
			if(ans!=0)temp2 += a;
		}
	}
	cout << s3.top() << endl;



	return 0;
	

}