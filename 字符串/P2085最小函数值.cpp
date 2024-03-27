#include<bits/stdc++.h>
using namespace std;

struct node {
	int value;
	int i;
	int funct;
	bool operator < (node b)const {
		return this->value > b.value;
	}
};

const int N = 1.e4+10;
int A[N];
int B[N];
int C[N];


int n;//n个函数
int m;//m个最小函数值

int main() {
	priority_queue<node>q;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> A[i] >> B[i] >> C[i];
		q.push(node{ A[i] + B[i] + C[i],1,i });
	}

	for (int j = 1; j <= m; j++) {
		node temp = q.top();
		int i = temp.i+1;
		int k = temp.funct;
		q.push(node{ A[k] * i * i + B[k] * i + C[k],i,k });
		q.pop();
		cout << temp.value << " "[j == m];
	}



	return 0;
}