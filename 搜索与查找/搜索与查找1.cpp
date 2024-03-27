
//2017-省赛C-九宫幻方-dfs

#include<bits/stdc++.h>
using namespace std;

//全排列，列出所有的排列情况，然后不断匹配，找到需要的结果

int a[3][3];
int b[3][3];//记录待补充矩阵
pair<int, int>p[10];//记录空余位置
int k[10];//记录该数字是否被使用
int nums;//记录空闲的位置数量
int counts;//记录匹配的矩阵数量

bool check() {
    //判断对角线值是否相等
    if ((b[0][0] + b[2][2]) != (b[0][2] + b[2][0]))return false;
    //判断每一列是否相等
    if ((b[0][0] + b[1][0] + b[2][0]) != (b[0][1] + b[1][1] + b[2][1]))return false;
    if ((b[0][0] + b[1][0] + b[2][0]) != (b[0][2] + b[1][2] + b[2][2]))return false;
    //判断每一行是否相等
    if ((b[0][0] + b[0][1] + b[0][2]) != (b[1][0] + b[1][1] + b[1][2]))return false;
    if ((b[0][0] + b[0][1] + b[0][2]) != (b[2][0] + b[2][1] + b[2][2]))return false;

    return true;
}

//深度优先搜索，先把能填的填完,若不匹配，则回退，选择其它数填入
void dfs(int n) {
    if (n > nums) {
        //判断填充完的矩阵是否匹配
        if (check()) {
            counts++;
            //记录匹配矩阵
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    a[i][j] = b[i][j];
                }
            }
        }
        return;
    }

    int x = p[n].first;
    int y = p[n].second;
    for (int i = 1; i <= 9; i++) {
        if (k[i])continue;//如果i以及存在则不可使用
        b[x][y] = i;
        k[i] = 1;//使用后要标记
        dfs(n + 1);
        //回溯
        b[x][y] = 0;
        k[i] = 0;
    }

}



int main()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> b[i][j];//读入数据
            if (!b[i][j])p[++nums] = make_pair(i, j);
            k[b[i][j]] = 1;
        }
    }

    dfs(1);

    if (counts == 1) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << a[i][j] << (j == 2 ? "\n" : " ");
                //可以简写成
                cout << a[i][j] << " \n"[j == 2];//当j==2时索引值=1，输出\n，否则索引为0，输出" "
            }
        }
    }
    else {
        cout << "Too Many\n";
    }

    return 0;

}

