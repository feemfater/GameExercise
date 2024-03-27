#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    //getline(cin, s);//»áÊäÈë¿Õ¸ñ
    string p;
    //getline(cin, p);
    cin >> p;
    string ans;
    reverse(s.begin(), s.end());
    reverse(p.begin(), p.end());

    int ss = s.size();
    int ps = p.size();
    int n = max(ss, ps);
    int temp = 0;
    int flag = 0;
    for (int i = 0; i <= (n - ss); i++) {
        s.append("0");
    }
    for (int i = 0; i <= (n - ps); i++) {
        p.append("0");
    }

    for (int i = 0; i < n; i++) {
        temp = (s[i] - '0') - (p[i] - '0') - flag;
        flag = 0;
        if (temp < 0) {
            temp += 10;
            flag = 1;
        }
        ans.append(to_string((temp)));
    }

    if (flag) {
        flag = 0;
        for (int i = 0; i < n; i++) {
            temp = (p[i] - '0') - (s[i] - '0') - flag;
            flag = 0;
            if (temp < 0) {
                temp += 10;
                flag = 1;
            }
            ans[i] = temp+'0';
        }
        ans = ans + "-";
    }
    reverse(ans.begin(), ans.end());
    n = ans.find('0');
    while (n == 0) {
        ans.erase(0, 1);
        n = ans.find('0');
    }

    if (ans == "") {
        cout << 0 << endl;
    }
    else {
        cout << ans << endl;
    }

}