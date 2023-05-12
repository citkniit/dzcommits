#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<int> a[100], bool fl[100], int x) {//����� � �������
	fl[x] = true;//�������� ����������
	for (int i : a[x]) {//������ �� �������
		if (!fl[i]) {//���� �� ���������
			dfs(a, fl, i);//���������� ��������
		}
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
	bool visited[100] = { false };
	int a;
	cout << "������� ������ ";
	cin >> a;
	 dfs(ar, visited, a);//����� � �������
	 for (int i = 0; i < n; i++) {
		 if (!visited[i]) cout << i << " ";//����� ������
	}
	return 0;
}