
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int a[10];
int nums;

bool check(int x) {
    int k = 0;
    while (x) {
        int b = x % 10;
        a[k++] = b;
        x = x / 10;
    }
    if (k % 2 != 0)return false;
    int left = 0;
    int right = 0;
    for (int i = 0; i < (k / 2); i++) {
        left += a[i];
    }
    for (int i = k / 2; i < k; i++) {
        right += a[i];
    }

    if (left == right) {
        return true;
    }
    return false;
}

int main()
{
    for (int i = 11; i <= 99999999; i++) {
        if (check(i))nums++;
    }
    cout << nums << endl;

    return 0;
}