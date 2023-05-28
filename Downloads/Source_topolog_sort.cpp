#include <iostream>
#include <vector>
using namespace std;
struct stack {
	int inf;
	stack* next;
};
void push(stack*& h, int x) {//добавление
	stack* r = new stack;
	r->inf = x;
	r->next = h;
	h = r;
}
int pop(stack*& h) { //удаление
	int i = h->inf;
	stack* r = h;
	h = h->next;
	delete r;
	return i;

}

// ‘ункци€ дл€ выполнени€ топологической сортировки
void top(vector<int> a[100], bool fl[100], int x, stack*& res) {
    fl[x] = true;//помечаем пройденной
    for (int i : a[x]) {//проход по смежным
        if (!fl[i]) {//если не проходили
            top(a, fl, i,res);//рекурсивно вызываем
        }
    }
	push(res, x);
}

int main(){
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
	bool visited[100] = { false };
	stack* res = NULL;
   top(ar, visited, 0, res);//обход в глубину
   while (res != NULL) {
	   cout << pop(res) << " ";
   }
    return 0;
}