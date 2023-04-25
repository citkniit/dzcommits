#include <iostream>
#include <cmath>
using namespace std;
struct tree {//��������� ������
 int inf;
tree * right;
tree * left;
};
tree * node(int x) {//��������� �� ������
 tree * n = new tree;
 n-> inf = x;
 n-> left = n-> right = NULL;
 return n;
}
void create(tree * &tr, int n) {//�������� ���
 int x;
if (n > 0) {
 cin >> x;//���� ���������
tr = node(x);
 int nl = n / 2;
 int nr = n - nl - 1;
 create(tr-> left, nl);
 create(tr-> right, nr);
	}
}
void preorder(tree * tr) {//������ �����
	if (tr) {
cout << tr-> inf << " ";//������� ������
preorder(tr-> left);//����� �������
preorder(tr-> right);//������ �������
	}
}
void lists(tree* tr) {//����� �������
	if (tr == NULL) {
		return;
	}
		if (tr->left == NULL && tr->right == NULL) {//���� ��� �� ������, �� ������� �������
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