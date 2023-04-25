#include <iostream>
#include <cmath>
using namespace std;
struct tree {//��������� ������
	int inf;
	tree* right;
	tree* left;
};
tree* node(int x) {//��������� �� ������
	tree* n = new tree;
	n->inf = x;
	n->left = n->right = NULL;
	return n;
}
void create(tree*& tr, int n) {//�������� ���
	int x;
	if (n > 0) {
		cin >> x;//���� ���������
		tr = node(x);
		int nl = n / 2;
		int nr = n - nl - 1;
		create(tr->left, nl);
		create(tr->right, nr);
	}
}
void preorder(tree* tr) {//������ �����
	if (tr) {
		cout << tr->inf << " ";//������� ������
		preorder(tr->left);//����� �������
		preorder(tr->right);//������ �������
	}
}
void uzl(tree* tr, int k) {//����� ����� �-��� ������
	if (tr == NULL) {
		return;
	}
	if (k == 0) {
		cout << tr->inf << " ";
		return;
	}
	uzl(tr->left, k - 1);
	uzl(tr->right, k - 1);
}
int main() {
	setlocale(LC_ALL, "rus");
	tree* tr = NULL;
	int n,k;
	cin >> n;
	create(tr, n);
	preorder(tr);
	cout << endl;
	cout << "������� k ";
	cin >> k;
	uzl(tr,k);
	return 0;
}