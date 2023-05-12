#include <iostream>
#include <vector>
using namespace std;
void otm(vector<int> a[100], bool fl[100], int x) {
	int m = x;
	for (int i : a[m]) {//проход по смежным
		fl[i] = true;//пометка что прошли
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	int n, m;
	cout << "¬ведите колво вершин";
	cin >> n;
	cout << "¬ведите колво рЄбер";
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
	int a, b;
	cout << "¬ведите рЄбра A и B";
	cin >> a >> b;
	bool visited[100] = { false };
	otm(ar, visited, a);//обход в глубину
	if (!visited[b]) {//если ребра нет
		ar[a].push_back(b);
	}
	for (int i = 0; i < n; i++) {//вывод ответа
		cout << i << ":";
		for (int j : ar[i]) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}