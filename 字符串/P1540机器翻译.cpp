#include<bits/stdc++.h>
using namespace std;

const int maxs = 1.e3+10;
int M;//�ڴ�����
int N;//���³���

int b[maxs];//��¼�������
int ans;
int main() {
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		cin >> b[i];

	}

	set<int>a;
	queue<int>q;


	for (int i = 1; i <= N; i++) {

		if (a.find(b[i])==a.end()) {
			ans++;
			if (q.size() >= M) {
				a.erase(q.front());
				q.pop();
			}
			else {
				
			}
			q.push(b[i]);
			a.insert(b[i]);
		}
	}

	cout << ans << endl;
	return 0;
}