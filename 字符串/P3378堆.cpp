#include<bits/stdc++.h>
using namespace std;


struct node{
	int value;
	bool operator < (node b)const {
		return this->value > b.value;//����true˵���������ȼ���
		//����˵��valueֵԽ��Խ�����
	}
};

int N;

int main() {
	//priority:����
	priority_queue<node> q;
	cin >> N;

	int op = 0;
	int x = 0;
	for (int i = 1; i <= N; i++) {
		cin >> op;
		if (op == 1) {
			cin >> x;
			q.push(node{ x });
		}
		if (op == 2) {
			cout << q.top().value << endl;
		}
		if (op == 3) {
			if(!q.empty()){ q.pop(); }
		}
	}

	return 0;
}