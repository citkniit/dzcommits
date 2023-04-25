#include <iostream>
using namespace std;
struct tree {
	int inf;
	tree* right;
	tree* left;
	tree* parent;
};
tree* node(int x) {//��������� ����
	tree* n = new tree;
	n->inf = x;
	n->left = n->right = NULL;
	n->parent = NULL;
	return n;
}
void insert(tree*& tr, int x) {//�������
	tree* n = node(x);
	if (!tr) tr = n; //���� ������ ������ - ������
	else {
		tree* y = tr;
		while (y) { //���� ���� ���������
			if (n->inf > y->inf) //������ �����
				if (y->right)
					y = y->right;
				else {
					n->parent = y; //���� ���������� ������ ��������
					y->right = n;
					break;
				}
			else if (n->inf < y->inf)//����� �����
				if (y->left)
					y = y->left;
				else {
					n->parent = y;//���� ���������� ����� ��������
					y->left = n;
					break;
				}
		}
	}
}
void way(tree* tr, int x) {//������� ������ ����
	if (tr == NULL) {
		return;
	}
	cout << tr->inf << " ";
	if (tr->inf == x) {
		return;
	}
	if (x < tr->inf) {
		way(tr->left, x);
	}
	else way(tr->right, x);
}
void inorder(tree* tr) {//������������ �����
	if (tr) {
		inorder(tr->left);
		cout << tr->inf << " ";
		inorder(tr->right);
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	int n, x;
	cin >> n;
	tree* tr = NULL;
	for (int i = 0; i < n; i++) {//��������� ������
		cout << i << ": ";
		cin >> x;
		insert(tr, x);
	}
	inorder(tr);//������������ ������� �������
	cout << "������� x ";
	cin >> x;
	way(tr, x);
	return 0;
}
