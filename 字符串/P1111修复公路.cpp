#include<bits/stdc++.h>
using namespace std;

class road {
public:
	int x;
	int y;
	int time;
};

bool cmp(road first, road second) {
	return first.time < second.time;
}

const int N = 1.e3 + 10;
int father[N];
int n;//村庄数
int m;//公路数
int ans;
int nums;//链接的集合数量



//找根
int find(int x) {
	if (father[x] == x) {
		return x;
	}
	else {
		father[x] = find(father[x]);
		return father[x];
	}
}

//合并子集
void merge(int v, int u) {
	int father1 = find(v);
	int father2 = find(u);
	if (father1 != father2) {
		father[father2] = father1;
		nums++;
	}
}

int main() {
	cin >> n >> m;
	vector<road>r;
	ans = 0;
	nums = 1;

	for (int i = 1; i <= n; i++) {
		father[i] = i;
	}



	road need;
	for (int i = 0; i < m; i++) {
		cin >> need.x >> need.y >> need.time;
		r.push_back(need);
	}
	sort(r.begin(), r.end(), cmp);

	for (auto i : r) {
		merge(i.x, i.y);
		if (nums == n) {
			ans = i.time;
			break;
		}
	}

	if (nums < n ) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
	
	return 0;

	
}