#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<int> a[100], bool fl[100], int x) {//обход в глубтну
	fl[x] = true;//помечаем пройденной
	for (int i : a[x]) {//проход по смежным
		if (!fl[i]) {//если не проходили
			dfs(a, fl, i);//рекурсивно вызываем
		}
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
	bool visited[100] = { false };
	int a;
	cout << "¬ведите веришу ";
	cin >> a;
	 dfs(ar, visited, a);//обход в глубину
	 for (int i = 0; i < n; i++) {
		 if (!visited[i]) cout << i << " ";//вывод ответа
	}
	return 0;
}