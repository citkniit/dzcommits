#include <iostream>
#include <vector>
using namespace std;
void otm(vector<int> a[100], bool fl[100], int x) {
	int m = x;
	for (int i : a[m]) {//������ �� �������
		fl[i] = true;//������� ��� ������
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	int n, m;
	cout << "������� ����� ������";
	cin >> n;
	cout << "������� ����� ����";
	cin >> m;
	vector<int> ar[100];
	for (int i = 0; i < m; i++) {//������ ���������
		int u, v;
		cin >> u >> v;
		ar[u].push_back(v);
	}
	for (int i = 0; i < n; i++) {//����� ������ ���������
		cout << i << ":";
		for (int j : ar[i]) {
			cout << j << " ";
		}
		cout << endl;
	}
	int a, b;
	cout << "������� ���� A � B";
	cin >> a >> b;
	bool visited[100] = { false };
	otm(ar, visited, a);//����� � �������
	if (!visited[b]) {//���� ����� ���
		ar[a].push_back(b);
	}
	for (int i = 0; i < n; i++) {//����� ������
		cout << i << ":";
		for (int j : ar[i]) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}