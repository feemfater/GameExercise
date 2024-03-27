#include<bits/stdc++.h>
using namespace std;

int a[5][5] = { {0,0,1,1,0},//剪刀，石头，布，蜥蜴人，斯波克
				{1,0,0,1,0},
				{0,1,0,0,1},
				{0,0,1,0,1},
				{1,1,0,0,0}};

const int num = 200;
int NA[num];
int NB[num];

int main() {
	int N, Na, Nb;
	cin >> N >> Na >> Nb;
	for (int i = 0; i < Na; i++) {
		cin >> NA[i];
	}
	for (int i = 0; i < Nb; i++) {
		cin >> NB[i];
	}
	int sumA = 0;
	int sumB = 0;
	for (int i = 0; i < N; i++) {
		int chooseA = NA[i % Na];//甲的选择
		int chooseB = NB[i % Nb];//乙的选择
		sumA += a[chooseA][chooseB];//甲对于乙的结果
		sumB += a[chooseB][chooseA];//乙对于甲的结果
	}
	cout << sumA << " " << sumB << endl;
}


