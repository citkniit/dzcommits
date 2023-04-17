#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Cell {// Структура для хранения информации о клетке на шахматной доске
	int x, y; // Координаты клетки
	int rasst; // Расстояние от начальной клетки до текущей
	vector<Cell> way; // Путь от начальной клетки до текущей
};
struct Queue {//очередь
	Cell inf;
	Queue* next;
};
void push(Queue*& front, Queue*& rear, Cell value) {//вставка элемента в конец
	Queue* newNode = new Queue;
	newNode->inf = value;//добавляем в хвост
	newNode->next = NULL;
	if (front == NULL && rear == NULL) {//если очередь пустая
		front = rear = newNode;
		return;
	}
	rear->next = newNode;
	rear = newNode;
}
Cell pop(Queue*& front, Queue*& rear) {//удаление с начала
	Cell value = front->inf;
	Queue* temp = front;
	front = front->next;
	if (front == NULL) {
		rear = NULL;
	}
	delete temp;//удаление с начала
	return value;//возвращает удалённый элемент
}
bool proverka(int x, int y) {// Проверяем, находится ли клетка на шахматной доске
	return x >= 0 && x <= 7 && y >= 0 && y <= 7;
}
vector<Cell> result(Cell start, Cell finish) {// Функция для поиска кратчайшего пути между двумя клетками на шахматной доске
	bool visited[8][8] = { false };// Массив для хранения информации о посещенных клетках
	// Очередь для обхода всех соседних клеток
	Queue* h = NULL;
	Queue* t = NULL;;
	push(h,t,start);// Помещаем начальную клетку в очередь
	visited[start.x][start.y] = true;
	while (h != NULL && t != NULL) {// Пока очередь не пуста
		Cell a = pop(h, t);// Извлекаем первую клетку из очереди
		// Если мы достигли конечной клетки, возвращаем ее путь
		if (a.x == finish.x && a.y == finish.y) {
			a.way.push_back(a);
			return a.way;
		}
		// Иначе ищем соседние клетки
		//массивы для возможных ходов
		int dx[] = { -1, -1, 1, 1, -2, -2, 2, 2 };
		int dy[] = { -2, 2, -2, 2, -1, 1, -1, 1 };
		for (int i = 0; i < 8; i++) {
			//куда переместишься после хода
			int x = a.x + dx[i];
			int y = a.y + dy[i];
			if (proverka(x, y) && !visited[x][y]) {//если переместишься не за пределы доски и клетка не была посещена
				visited[x][y] = true;//отмечаем её посещенной
				Cell next = { x, y, a.rasst + 1, a.way };//следующая клетка
				next.way.push_back(a);
				push(h,t, next);//закладываем следующую клеетку в очередь
			}
		}
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	char startbukva, finishbukva;//буквы начальной и конечной точек
	int startX, startY, finishX, finishY;//цифры конечной и начальной точек
	cout << "Введите координаты начальной клетки ";
	cin >> startbukva >> startY;//ввод начальной точки
	startX = startbukva - 'A';//преобразуем char в int
	startY--;//уменьшаем на 1 т.к в функции от 0 до 7
	cout << "Введите координаты конечной клетки ";
	cin >> finishbukva >> finishY;//ввод конечной точки
	finishX = finishbukva - 'A';//преобразуем char в int
	finishY--;
	Cell start = { startX, startY, 0, vector<Cell>() };// Создаем объекты для начальной и конечной клеток
	Cell finish = { finishX, finishY, 0, vector<Cell>() };
	vector<Cell> p = result(start, finish);// Ищем наименьший путь между начальной и конечной клетками
		for (const auto& cell : p) {//проход по элементам вектора
			cout << char(cell.x + 'A') << cell.y + 1 << " ";//вывод результата
		}
	return 0;
}