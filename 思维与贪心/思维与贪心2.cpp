#include <iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 31;
int n;
int m;
int ans;
int a[N];
int sum[N];

//问题是会出现小数,为避免小数被省略，可以先把目标重量和每个瓜的重量*2
void dfs(int x, int weight, int nums) {
    //X表示第几个瓜，weight表示重量,nums表示劈瓜的数量
    if (x<0 || x>n)return;
    if (nums > n)return;
    if (weight > m || (m-weight)>sum[x])return;
    if (weight == m) {
        ans = min(ans, nums);
        return;
    }
    dfs(x + 1, weight + a[x], nums);
    dfs(x + 1, weight + a[x] / 2, nums + 1);
    dfs(x + 1, weight, nums);

}

int main() {
    ans = 50;
    cin >> n >> m;
    m *= 2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= 2;
    }
    sort(a, a+ n);//first->第一个元素,last->最后一个元素的下一位
    for (int i = n - 1; i >= 0; i--) {
        sum[i] = sum[i + 1] + a[i];
    }

    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
    
}
