#include <iostream>
#include <vector>
using namespace std;
int otm(vector<int> a[100], bool fl[100], int x) {
	int c = 0;
	for (int i : a[x]) {//������ �� �������
		c++;
	}
	return c;
}
int main() {
	setlocale(LC_ALL, "rus");
	int n, m, v;
	cout << "������� ���������� ������";
	cin >> n;
	cout << "������� ���������� ����";
	cin >> m;
	vector <int> a[100];
	for (int i = 0; i < m; i++) {//������ ���������
		int u, v;
		cout << "������� ������� �������";
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		for (int j : a[i]) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << "������� �������";
	cin >> v;
	bool visited[100] = { false };
	int c = otm(a, visited, v);
	cout << c << endl;
	return 0;
}