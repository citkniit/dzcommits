#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, m, x;
	cin >> x;
	cin >> n;
	cin >> m;
	int** a = new int* [n];//�������� ��� ������
	for (int i = 0; i < n; i++) {
		a[i] = new int[2*m];//��������  ��� �������
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];//����
		}
	}
	for (int j = 0; j < m;) {
		bool f = true;
		for (int i = 0; i < n; i++) {
			if (a[i][j] % 2 == 0) {// ����� �������
				f = false;
				break;
			}
		}
		if (f == true) {
			for (int k = m; k > j; k--) {
				for (int r = 0; r < n; r++) {
					a[r][k] = a[r][k-1];// ������� �����
				}
			}
			for (int t = 0; t < n; t++)
				a[t][j] = x;//��������� �������
			m++;
			j += 2;
		}
		else j++;
	}
	for (int i = 0; i < n; i++, cout << endl) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";//�����
		}
	}
	system("pause");
	return 0;
}
