#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, m, x;
	cin >> n;
	cin >> m;
	int** a = new int* [n];//�������� ��� ������
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];//�������� ��� �������
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];//����
		}
	}
	int min = 30000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] < min) min = a[i][j];//����� ���
		}
	}
	for (int i = 0; i < n;) {
		bool f = false;
		for (int j = 0; j < m; j++) {
			if (a[i][j] == min) {
				f = true;
				break;
			}
		}
		if (f == true) {
			for (int k = i; k < n-1; k++) {
				for (int r = 0; r < m; r++) {
					a[k][r] = a[k + 1][r];//�������� �����
				}
			}
			n--;
		}
		else i++;
	}
	for (int i = 0; i < n; i++, cout << endl) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";//�����
		}
	}
	system("pause");
	return 0;
}
