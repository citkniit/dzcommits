#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, m, x;
	cin >> x;
	cin >> n;
	cin >> m;
	int** a = new int* [2*n];//��������� ��� ������
	for (int i = 0; i < 2*n; i++) {
		a[i] = new int[m];//��������� ��� �������
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];//����
		}
	}
	for (int i = 0; i < n;) {
		bool f = true;
		for (int j = 0; j < m; j++) {
			if (a[i][j] <= 0) {
				f = false;//�������� �������������
				break;
			}
		}
			if (f == true) {
				for (int k = n; k > i + 1; k--) {
					for (int r = 0; r < m; r++) {
						a[k][r] = a[k - 1][r];//����� �����
					}
				}
				for (int t = 0; t < m; t++)
					a[i + 1][t] = x;//���� ������
				n++;
				i += 2;
			}
			else i++;
	}
		for (int i = 0; i < n; i++,cout << endl) {
			for (int j = 0; j < m; j++) {
				cout << a[i][j] << " ";//�����
			}
		}
	system ("pause");
	return 0;
}
