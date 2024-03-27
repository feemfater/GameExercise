#include<bits/stdc++.h>
using namespace std;


struct datas {
	int happy;
	int day;
};

bool cmp(datas x, datas y) {
	return x.happy > y.happy;
}

datas times[8];

int main() {
	int a = 0;
	int b = 0;
	for (int i = 1; i <= 7; i++) {
		cin >> a >> b;
		int happy = ((a + b) - 8) >= 0 ? ((a + b) - 8) : 0;
		times[i] = datas{ happy ,i };
	}
	sort(times + 1, times + 8, cmp);
	if (times[1].happy == 0) {
		cout << 0 << endl;
	}
	else {
		cout << times[1].day << endl;
	}
	return 0;
}