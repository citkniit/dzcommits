#include <iostream>
using namespace std;
struct list {//инициализация
	int inf;
	list* next;
	list* prev;
};
void print(list* h, list* t) {//функция вывода
	list* p = h;
	while (p) {
		cout << p->inf << " ";
		p = p->next;
	}
}
void push(list*& h, list*& t, int x) { //вставка элемента в конец списка
	list* r = new list; //создаем новый элемент
	r->inf = x;
	r->next = NULL; //всегда последний
	if (!h && !t) { //если список пуст
		r->prev = NULL; //первый элемент
		h = r; //это голова
	}
	else {
		t->next = r; //r - следующий для хвоста
		r->prev = t; //хвост - предыдущий для r
	}
	t = r; //r теперь хвост
}

void del_n(list*& h, list*& t, list* r) {//удаление элемента
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
	int i = 1;//счётчик
	while (p) {
		if (p->inf == max) {
			if (i == 1 || i == kol_max) {
				list* temp = p;//переменная для хранения ссылки
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
	for (int i = 0; i < n; i++) {//заполнение стека
		cin >> x;
		push(h, t, x);
		if (x > max) {//поиск максимального и счётчик сколько их
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
