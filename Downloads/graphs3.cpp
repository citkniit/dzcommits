#include <iostream>
#include <vector>
using namespace std;
void otm(vector<int> a[100], bool fl[100], int n) {
	int c = 0;
	for (int i = 0; i < n;i++) {//проход по элементам
		for (int j : a[i]) {
			c++;
		}
		cout << i << ": " << c << endl;;
		c = 0;
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	int n, m;
	cout << "Введите колво вершин";
	cin >> n;
	cout << "Введите колво рёбер";
	cin >> m;
	vector<int> ar[100];
	for (int i = 0; i < m; i++) {//список смежности
		int u, v;
		cin >> u >> v;
		ar[u].push_back(v);
	}
	for (int i = 0; i < n; i++) {//вывод списка смежности
		cout << i << ":";
		for (int j : ar[i]) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;
	bool visited[100] = { false };
	otm(ar, visited, n);
	return 0;
}
