

// 枚举-2021-蓝桥省赛A-卡片
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int card[10];

//拆分枚举数的每一位，并依次扣取对应卡片
bool check(int num) {
    while (num)
    {
        int y = num % 10;

        //如果卡片有缺，则返回false
        if (card[y] >=1) {
            card[y]--;
        }
        else {
            return false;
        }
        num = num / 10;
    }
    return true;
}


int main()
{
    for (int i = 0; i < 10; i++) {
        card[i] = 2021;
    }
    
    //枚举所有数字，将数字的每一位拆开，并扣去对应数字卡片数量
    for (int i = 1;; i++) {
        if (!check(i)) {
            cout<<i-1<<endl;
            break;
        }
    }

    return 0;

}

