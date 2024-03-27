// 排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//STL
#include<bits/stdc++.h>
using namespace std;
const int N = 1.e5 + 10;
int a[N];
int b[N];

int cmp(int x, int y) {
    return x < y;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n,cmp);

    int temp = a[1];
    int nums = 1;
    b[1] = temp;
    for (int i = 2; i <= n; i++) {
        if (a[i] == temp)continue;
        else {
            temp = a[i];
            nums++;
            b[nums] = a[i];
        }
    }
    cout<<nums<<endl;
    for (int i = 1; i <= nums; i++) {
        cout << b[i] << " \n"[i == nums];
    }
    return 0;
}
