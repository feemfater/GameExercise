
#include<bits/stdc++.h>
using namespace std;

double a;
double b;
double c;
double d;
int flag;
double calucate(double x) {
	return a * pow(x, 3) + b * pow(x, 2) + c * pow(x, 1) + d;
}

void mid(double l, double r) {
	double A = calucate(l);
	double B = calucate(r);

	if (A == 0) {
		cout << fixed << setprecision(2) << l << " \n"[flag == 3];
	}
	if (A * B < 0) {
		while (fabs(l-r) >= 1.e-3) {
			double m = (l + r) / 2;
			if (calucate(m) * B <= 0) {
				l = m;
			}
			else {
				r = m;
			}
		}
		flag++;
		cout << fixed << setprecision(2) << r << " \n"[flag == 3];
		return;
	}
	return;

}

int main()
{
	flag = 0;
	cin >> a >> b >> c >> d;
	for (double i = -100; i <= 100.0; i++) {
		if (flag == 3)break;
		mid(i, i + 1);
	}

	return 0;
}
