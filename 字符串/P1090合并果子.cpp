#include<bits/stdc++.h>
using namespace std;

struct node {
	long long  value;
	bool operator <(node b)const {
		return this->value > b.value;
	}
};

int main() {
	priority_queue<node>q;
	int N=0;
	long long  ans=0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> ans;
		q.push(node{ ans });
	}
	ans = 0;

	for (int i = 1; i < N; i++) {
		long long first = q.top().value;
		q.pop();
		long long second = q.top().value;
		q.pop();
		long long nNode = first + second;
		q.push(node{ nNode });
		ans += nNode;
	}
	

	cout << ans << endl;

}
