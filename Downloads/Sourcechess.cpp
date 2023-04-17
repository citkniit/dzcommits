#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Cell {// ��������� ��� �������� ���������� � ������ �� ��������� �����
	int x, y; // ���������� ������
	int rasst; // ���������� �� ��������� ������ �� �������
	vector<Cell> way; // ���� �� ��������� ������ �� �������
};
struct Queue {//�������
	Cell inf;
	Queue* next;
};
void push(Queue*& front, Queue*& rear, Cell value) {//������� �������� � �����
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
Cell pop(Queue*& front, Queue*& rear) {//�������� � ������
	Cell value = front->inf;
	Queue* temp = front;
	front = front->next;
	if (front == NULL) {
		rear = NULL;
	}
	delete temp;//�������� � ������
	return value;//���������� �������� �������
}
bool proverka(int x, int y) {// ���������, ��������� �� ������ �� ��������� �����
	return x >= 0 && x <= 7 && y >= 0 && y <= 7;
}
vector<Cell> result(Cell start, Cell finish) {// ������� ��� ������ ����������� ���� ����� ����� �������� �� ��������� �����
	bool visited[8][8] = { false };// ������ ��� �������� ���������� � ���������� �������
	// ������� ��� ������ ���� �������� ������
	Queue* h = NULL;
	Queue* t = NULL;;
	push(h,t,start);// �������� ��������� ������ � �������
	visited[start.x][start.y] = true;
	while (h != NULL && t != NULL) {// ���� ������� �� �����
		Cell a = pop(h, t);// ��������� ������ ������ �� �������
		// ���� �� �������� �������� ������, ���������� �� ����
		if (a.x == finish.x && a.y == finish.y) {
			a.way.push_back(a);
			return a.way;
		}
		// ����� ���� �������� ������
		//������� ��� ��������� �����
		int dx[] = { -1, -1, 1, 1, -2, -2, 2, 2 };
		int dy[] = { -2, 2, -2, 2, -1, 1, -1, 1 };
		for (int i = 0; i < 8; i++) {
			//���� ������������� ����� ����
			int x = a.x + dx[i];
			int y = a.y + dy[i];
			if (proverka(x, y) && !visited[x][y]) {//���� ������������� �� �� ������� ����� � ������ �� ���� ��������
				visited[x][y] = true;//�������� � ����������
				Cell next = { x, y, a.rasst + 1, a.way };//��������� ������
				next.way.push_back(a);
				push(h,t, next);//����������� ��������� ������� � �������
			}
		}
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	char startbukva, finishbukva;//����� ��������� � �������� �����
	int startX, startY, finishX, finishY;//����� �������� � ��������� �����
	cout << "������� ���������� ��������� ������ ";
	cin >> startbukva >> startY;//���� ��������� �����
	startX = startbukva - 'A';//����������� char � int
	startY--;//��������� �� 1 �.� � ������� �� 0 �� 7
	cout << "������� ���������� �������� ������ ";
	cin >> finishbukva >> finishY;//���� �������� �����
	finishX = finishbukva - 'A';//����������� char � int
	finishY--;
	Cell start = { startX, startY, 0, vector<Cell>() };// ������� ������� ��� ��������� � �������� ������
	Cell finish = { finishX, finishY, 0, vector<Cell>() };
	vector<Cell> p = result(start, finish);// ���� ���������� ���� ����� ��������� � �������� ��������
		for (const auto& cell : p) {//������ �� ��������� �������
			cout << char(cell.x + 'A') << cell.y + 1 << " ";//����� ����������
		}
	return 0;
}