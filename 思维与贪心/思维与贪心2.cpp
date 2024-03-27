#include <iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 31;
int n;
int m;
int ans;
int a[N];
int sum[N];

//�����ǻ����С��,Ϊ����С����ʡ�ԣ������Ȱ�Ŀ��������ÿ���ϵ�����*2
void dfs(int x, int weight, int nums) {
    //X��ʾ�ڼ����ϣ�weight��ʾ����,nums��ʾ���ϵ�����
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
    sort(a, a+ n);//first->��һ��Ԫ��,last->���һ��Ԫ�ص���һλ
    for (int i = n - 1; i >= 0; i--) {
        sum[i] = sum[i + 1] + a[i];
    }

    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
    
}
