#include<bits/stdc++.h>
using namespace std;


int M;//ħ���ĳ�ֵ
int S;//��ʼλ���뵺�ĳ��ھ���
int T;//����û��ʱ��

//��������ʣ�µ�ʱ�������ߵ���Զ����
//ͨ�����㣬���Ų���Ϊ
// ħ���㹻��ֱ��˲�ƣ���������
//ʣ��ħ��->����ħʱ��+�˶�ʱ�䣩
//(0,1)->(5+2)=7
//(2,3,4,5)->(2+1)=3
//(6,7,8,9)->(1+1)=2
///��ʣ��ʱ��<����ʱ��ʱ��ѡ���ܲ�.

//̰��
int main() {
	cin >> M >> S >> T;

	int t = T;
	int s = S;

	while (S >= 0) {
		if (M >= 10) {
			M -= 10;
			S -= 60;
			T--;
		}
		else {

			if ((M == 0 || M == 1) && (T >= 7 && S >= 120)) {
				S -= 120;
				T -= 7;
			}
			else if (M >= 2 && M <= 5 && T >= 3 && S >= 60) {
				S -= 60;
				T -= 3;
				M -= 2;
			}
			else if (M >= 6 && M <= 9 && T >= 2 && S >= 60) {

				S -= 60;
				T -= 2;
				M -= 6;
			}
			else {
				while (T) {
					T--;
					S -= 17;
					if (S <= 0)break;
				}
			}

		}
		if (T <= 0)break;
	}

	if (T == 0) {
		if (S <=0) {
			cout << "Yes" << endl;
			cout << t << endl;
		}
		if (S > 0) {
			cout << "No" << endl;
			cout << s-S << endl;
		}
	}
	else if (T < 0) {
		cout << "No" << endl;
		cout << s - S << endl;
	}
	else {
		cout << "Yes" << endl;
		cout << t - T << endl;
	}

	return 0;

}