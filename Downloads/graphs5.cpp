#include <iostream>
#include <vector>
using namespace std;
struct Queue {//очередь
	int inf;
	Queue* next;
};
void push(Queue*& front, Queue*& rear, int value) {//вставка элемента в конец
	Queue* newNode = new Queue;
	newNode->inf = value;//добавл€ем в хвост
	newNode->next = NULL;
	if (front == NULL && rear == NULL) {//если очередь пуста€
		front = rear = newNode;
		return;
	}
	rear->next = newNode;
	rear = newNode;
}
int pop(Queue*& front, Queue*& rear) {//удаление с начала
	if (front == NULL) {//если очередь пуста€
		cout << "Queue is empty\n";
		return -1;
	}
	int value = front->inf;
	Queue* temp = front;
	front = front->next;
	if (front == NULL) {
		rear = NULL;
	}
	delete temp;//удаление с начала
	return value;//возвращает удалЄнный элемент
}
void bfs(vector<int> a[100], bool visited[100], int x, int y) {//обход в ширину
	Queue* h = NULL;//инициализаци€ очереди
	Queue* t = NULL;
	visited[x] = true;
	push(h, t, x);//помещаем начальный элемент графа в конец очереди
	int dist[100] = { -1 };
	int parent[100];
	parent[x] = -1;
	dist[x] = 0;
	while (h != NULL && t != NULL) {//пока очередь не пуста€
		int m = pop(h, t);//извлекаем элемент из начала очереди
		for (int i : a[m]) {//проход по списку межности
			if(!visited[i]) {
				push(h, t, i);
					visited[i] = true;
					dist[i] = dist[m] + 1;
					parent[i] = m;   //сохранение предыдущей вершины
			}
		}
	}
	vector<int> path;
	int cur = y;         //текуща€ вершина пути
	path.push_back(cur);
	while (parent[cur] != -1) {   //пока существует предыдуща€ вершина
		cur = parent[cur];        //переходим в неЄ
		path.push_back(cur);    //и дописываем к пути
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
	cout << "¬ведите количество вершин";
	cin >> n;
	cout << "введите количество рЄбер";
	cin >> m;
	vector <int> ar[100];
	for (int i = 0; i < m; i++) {//список смежности
		int u, v;
		cout << "введите смежные вершины";
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
	cout << "¬ведите вершины ";
	cin >> a >> b;
	bool visited[100] = { false };
	 bfs(ar, visited, a, b);
	return 0;
}