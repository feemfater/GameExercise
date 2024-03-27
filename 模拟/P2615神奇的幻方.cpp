#include<bits/stdc++.h>
using namespace std;

const int N = 40;
int a[N][N];

int lx;
int ly;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n * n; i++) {
		if (i == 1) {
			lx = 1;
			ly = (n + 1) / 2;	
		}
		else if (lx == 1 && ly < n) {
			lx = n;
			ly = ly + 1;
			
		}
		else if (lx != 1 && ly == n) {
			lx = lx - 1;
			ly = 1;
		}
		else if (lx==1&&ly==n) {
			lx = lx + 1;
			//ly = ly;
		}
		else {
			if (lx != 1 && ly != n && a[lx - 1][ly + 1] == 0) {
				lx = lx - 1;
				ly = ly + 1;
			}
			else {
				lx = lx + 1;
				// ly=ly;
			}
		}
		a[lx][ly] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << " \n"[j == n];
		}
	}
	return 0;
}