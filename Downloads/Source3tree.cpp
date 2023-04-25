#include <iostream>
#include <cmath>
using namespace std;
struct tree {//структура дерева
 int inf;
tree * right;
tree * left;
};
tree * node(int x) {//указатель на корень
 tree * n = new tree;
 n-> inf = x;
 n-> left = n-> right = NULL;
 return n;
}
void create(tree * &tr, int n) {//создание ИСД
 int x;
if (n > 0) {
 cin >> x;//ввод элементов
tr = node(x);
 int nl = n / 2;
 int nr = n - nl - 1;
 create(tr-> left, nl);
 create(tr-> right, nr);
	}
}
void preorder(tree * tr) {//прямой обход
	if (tr) {
cout << tr-> inf << " ";//сначала корень
preorder(tr-> left);//левый потомок
preorder(tr-> right);//правый потомок
	}
}
void lists(tree* tr) {//вывод листьев
	if (tr == NULL) {
		return;
	}
		if (tr->left == NULL && tr->right == NULL) {//если нет ни левого, ни правого потомка
			cout << tr->inf << " ";
			return;
		}
		lists(tr->left);
		lists(tr->right);
	}
int main() {
	tree* tr = NULL;
	int n;
	cin >> n;
	create(tr, n);
	preorder(tr);
	cout << endl;
	lists(tr);
	return 0;
}