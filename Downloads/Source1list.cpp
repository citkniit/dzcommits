#include <iostream>
using namespace std;
struct list {//�������������
	int inf;
	list* next;
	list* prev;
};
void print(list* h, list* t) {//������� ������
	list* p = h;
	while (p) {
		cout << p->inf << " ";
		p = p->next;
	}
}
void push(list*& h, list*& t, int x) { //������� �������� � ����� ������
	list* r = new list; //������� ����� �������
	r->inf = x;
	r->next = NULL; //������ ���������
	if (!h && !t) { //���� ������ ����
		r->prev = NULL; //������ �������
		h = r; //��� ������
	}
	else {
		t->next = r; //r - ��������� ��� ������
		r->prev = t; //����� - ���������� ��� r
	}
	t = r; //r ������ �����
}

void del_n(list*& h, list*& t, list* r) {//�������� ��������
	if (r == h && r == t)
		h = t = NULL;
	else if (r == h) {
		h = h->next;
		h->prev = NULL;
	}
	else if (r == t) {
		t = t->prev;
		t->next = NULL;
	}
	else {
		r->next->prev = r->prev;
		r->prev->next = r->next;
	}
	delete r;
}
void del_list(list*& h, list*& t) {
	while (h) {
		list* p = h;
		h = h->next;
		h->prev = NULL;
		delete p;
	}
}
void result(list*& h, list*& t, int max, int kol_max) {
	list* p = h;
	int i = 1;//�������
	while (p) {
		if (p->inf == max) {
			if (i == 1 || i == kol_max) {
				list* temp = p;//���������� ��� �������� ������
				p = p->next;
				del_n(h, t, temp);
			}
			else {
				p = p->next;
			}
			i++;
		}
		p = p->next;
	}
}
int main() {
	list* h = NULL;
	list* t = NULL;
	int n;
	cin >> n;
	int x;
	int max = -9999;
	int kol_max = 0;
	for (int i = 0; i < n; i++) {//���������� �����
		cin >> x;
		push(h, t, x);
		if (x > max) {//����� ������������� � ������� ������� ��
			max = x;
			kol_max = 1;
		}
		else if (x == max) {
			kol_max++;
		}
	}
	result(h, t, max, kol_max);
	print(h, t);
	return 0;
}
