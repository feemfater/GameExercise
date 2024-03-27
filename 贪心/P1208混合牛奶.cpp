
#include<bits/stdc++.h>
using namespace std;

const int N = 1.e6;

long long n;//所需牛奶总数
long long m;//奶农数
long long ans;//结果

struct MilkMan {
    long long p;//单价
    long long a;//总量
};

bool cmp(MilkMan x, MilkMan y) {
    if (x.p == y.p)return x.a > y.a;
    else {
        return x.p < y.p;
    }
}

MilkMan milk[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> milk[i].p >> milk[i].a;
    }
    sort(milk + 1, milk + 1 + m, cmp);
    for (int i = 1; i <= m; i++) {
        if (n >= milk[i].a) {
            n -= milk[i].a;
            ans += milk[i].a * milk[i].p;
        }
        else {
            ans += milk[i].p * n;
            n = 0;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}

