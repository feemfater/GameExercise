#include<bits/stdc++.h>
using namespace std;

int a[5][5] = { {0,0,1,1,0},//������ʯͷ�����������ˣ�˹����
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
		int chooseA = NA[i % Na];//�׵�ѡ��
		int chooseB = NB[i % Nb];//�ҵ�ѡ��
		sumA += a[chooseA][chooseB];//�׶����ҵĽ��
		sumB += a[chooseB][chooseA];//�Ҷ��ڼ׵Ľ��
	}
	cout << sumA << " " << sumB << endl;
}


