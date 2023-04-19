#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, m, x;
	cin >> n;
	cin >> m;
	int** a = new int* [n];//выделяем под строки
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];//выделяем  под столбцы
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];//ввод
		}
	}
	for (int j = 0; j < m;) {
		bool f = true;
		for (int i = 0; i < n; i++) {
			if (a[i][j] % 2 == 1) {// поиск чётного
				f = false;
				break;
			}
		}
		if (f == true) {
			for (int k = j; k < n-1; k++) {
				for (int r = 0; r < n; r++) {
					a[r][k] = a[r][k + 1];// смещаем влево
				}
			}
			m--;
		}
		else j++;
	}
	for (int i = 0; i < n; i++, cout << endl) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";//вывод
		}
	}
	system("pause");
	return 0;
}
