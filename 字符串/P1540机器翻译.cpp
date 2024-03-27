#include<bits/stdc++.h>
using namespace std;

const int maxs = 1.e3+10;
int M;//内存容量
int N;//文章长度

int b[maxs];//记录输入次序
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