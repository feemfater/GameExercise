#include<bits/stdc++.h>
using namespace std;

const int N = 100+10;
int a[N];
//¿ìËÙÃÝ
int qpow(int a, int n) {
	if (n == 0)return 1;
	else if (n % 2 != 0) {
		return qpow(a, n - 1) * a;
	}
	else {
		int temp = qpow(a, n / 2);
		return temp * temp;
	}
}

int main() {
	int n;
	cin >> n;
	string s;
	for (int i = n; i>=0; i--) {
		cin >> a[i];
	}
	for (int i = n; i >= 0; i--) {
		if (a[i] == 0)continue;
		if (i == 0)s.append((a[i]>0?('+'+to_string(a[i])) : to_string(a[i])));
		else if (i == 1) {
			if (a[i] > 0) {
				if (a[i] != 1) {
					s += ('+' + to_string(a[i]) + "x");
				}
				else {
					s += ("+x");
				}
			}
			else {
				if (a[i] != -1) {
					s += (to_string(a[i]) + "x");
				}
				else {
					s += ("-x");
				}
			}
		}
		else {
			
			if (a[i] > 0) {
				if (a[i] != 1) {
					s += ('+' + to_string(a[i]) + "x^" + to_string(i));
				}
				else {
					s += ("+x^"+ to_string(i));
				}
			}
			else {
				if (a[i] != -1) {
					s += (to_string(a[i]) + "x^" + to_string(i));
				}
				else {
					s += ("-x^" + to_string(i));
				}
			}
		}
		
	}

	while (s[0] == '0'||s[0]=='+') {
		if(s[0]=='0')s.erase(0, 4);
		if (s[0] == '+')s.erase(0, 1);
	}
	cout << s << endl;
	return 0;
}