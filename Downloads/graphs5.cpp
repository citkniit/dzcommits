#include <iostream>
#include <vector>
using namespace std;
struct Queue {//�������
	int inf;
	Queue* next;
};
void push(Queue*& front, Queue*& rear, int value) {//������� �������� � �����
	Queue* newNode = new Queue;
	newNode->inf = value;//��������� � �����
	newNode->next = NULL;
	if (front == NULL && rear == NULL) {//���� ������� ������
		front = rear = newNode;
		return;
	}
	rear->next = newNode;
	rear = newNode;
}
int pop(Queue*& front, Queue*& rear) {//�������� � ������
	if (front == NULL) {//���� ������� ������
		cout << "Queue is empty\n";
		return -1;
	}
	int value = front->inf;
	Queue* temp = front;
	front = front->next;
	if (front == NULL) {
		rear = NULL;
	}
	delete temp;//�������� � ������
	return value;//���������� �������� �������
}
void bfs(vector<int> a[100], bool visited[100], int x, int y) {//����� � ������
	Queue* h = NULL;//������������� �������
	Queue* t = NULL;
	visited[x] = true;
	push(h, t, x);//�������� ��������� ������� ����� � ����� �������
	int dist[100] = { -1 };
	int parent[100];
	parent[x] = -1;
	dist[x] = 0;
	while (h != NULL && t != NULL) {//���� ������� �� ������
		int m = pop(h, t);//��������� ������� �� ������ �������
		for (int i : a[m]) {//������ �� ������ ��������
			if(!visited[i]) {
				push(h, t, i);
					visited[i] = true;
					dist[i] = dist[m] + 1;
					parent[i] = m;   //���������� ���������� �������
			}
		}
	}
	vector<int> path;
	int cur = y;         //������� ������� ����
	path.push_back(cur);
	while (parent[cur] != -1) {   //���� ���������� ���������� �������
		cur = parent[cur];        //��������� � ��
		path.push_back(cur);    //� ���������� � ����
	}
	reverse(path.begin(), path.end());
	for (int v : path) {
		cout << v  << " ";
	}
	cout << endl;
	cout << dist[y];
}
int main() {
	setlocale(LC_ALL, "rus");
	int n, m, v;
	cout << "������� ���������� ������";
	cin >> n;
	cout << "������� ���������� ����";
	cin >> m;
	vector <int> ar[100];
	for (int i = 0; i < m; i++) {//������ ���������
		int u, v;
		cout << "������� ������� �������";
		cin >> u >> v;
		ar[u].push_back(v);
		ar[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		for (int j : ar[i]) {
			cout << j << " ";
		}
		cout << endl;
	}
	int a, b;
	cout << "������� ������� ";
	cin >> a >> b;
	bool visited[100] = { false };
	 bfs(ar, visited, a, b);
	return 0;
}