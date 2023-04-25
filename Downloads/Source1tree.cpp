#include <iostream>
using namespace std;
struct tree {
	int inf;
	tree* right;
	tree* left;
	tree* parent;
};
tree* node(int x) {//начальный узел
 tree * n = new tree;
 n -> inf = x;
 n -> left = n-> right = NULL;
 n -> parent = NULL;
return n;
}
void insert(tree*& tr, int x) {//вставка
tree * n = node(x);
if (!tr) tr = n; //если дерево пустое - корень
else {
tree * y = tr;
while (y) { //ищем куда вставлять
if (n-> inf > y-> inf) //правая ветка
if (y-> right)
 y = y-> right;
else {
 n-> parent = y; //узел становится правым ребенком
 y-> right = n;
 break;
			}
else if (n-> inf < y->inf)//левая ветка
if (y-> left)
 y = y-> left;
else {
n-> parent = y;//узел становится левым ребенком
 y-> left = n;
 break;
			}
		}
	}
}
void Delete(tree *&tr) {//удаление всех чётных
	if (tr) {
		Delete(tr->left);
		Delete(tr->right);
		if (tr->inf % 2 == 0) {
			tree* temp = tr;
			if (tr->left == NULL) tr = tr->right;
			else if (tr->right == NULL) tr = tr->left;
			else {
				tree* min = tr->right;
				while (min->left != NULL) min = min->left;
				tr->inf = min->inf;
				Delete(tr->right);
			}
			delete temp;
		}
	}
}
void inorder(tree* tr) {//симметричный обход
	if (tr) {
		inorder(tr-> left);
		cout << tr-> inf << " ";
		inorder(tr-> right);
	}
}
int main() {
	int n, x;
	cin >> n;
	tree* tr = NULL;
	for (int i = 0; i < n; i++) {//заполняем дерево
	cout << i << ": ";
	cin >> x;
	insert(tr, x);
	}
	inorder(tr);//симметричным обходом выводим
	cout << endl;
	Delete(tr);//удаляем все чётные
	inorder(tr);//симметричным обходом выводим результат
	return 0;
}