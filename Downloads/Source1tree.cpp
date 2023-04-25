#include <iostream>
using namespace std;
struct tree {
	int inf;
	tree* right;
	tree* left;
	tree* parent;
};
tree* node(int x) {//��������� ����
 tree * n = new tree;
 n -> inf = x;
 n -> left = n-> right = NULL;
 n -> parent = NULL;
return n;
}
void insert(tree*& tr, int x) {//�������
tree * n = node(x);
if (!tr) tr = n; //���� ������ ������ - ������
else {
tree * y = tr;
while (y) { //���� ���� ���������
if (n-> inf > y-> inf) //������ �����
if (y-> right)
 y = y-> right;
else {
 n-> parent = y; //���� ���������� ������ ��������
 y-> right = n;
 break;
			}
else if (n-> inf < y->inf)//����� �����
if (y-> left)
 y = y-> left;
else {
n-> parent = y;//���� ���������� ����� ��������
 y-> left = n;
 break;
			}
		}
	}
}
void Delete(tree *&tr) {//�������� ���� ������
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
void inorder(tree* tr) {//������������ �����
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
	for (int i = 0; i < n; i++) {//��������� ������
	cout << i << ": ";
	cin >> x;
	insert(tr, x);
	}
	inorder(tr);//������������ ������� �������
	cout << endl;
	Delete(tr);//������� ��� ������
	inorder(tr);//������������ ������� ������� ���������
	return 0;
}