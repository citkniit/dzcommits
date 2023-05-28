#include <iostream>
#include <vector>
using namespace std;
struct stack {
	int inf;
	stack* next;
};
void push(stack*& h, int x) {//����������
	stack* r = new stack;
	r->inf = x;
	r->next = h;
	h = r;
}
int pop(stack*& h) { //��������
	int i = h->inf;
	stack* r = h;
	h = h->next;
	delete r;
	return i;

}

// ������� ��� ���������� �������������� ����������
void top(vector<int> a[100], bool fl[100], int x, stack*& res) {
    fl[x] = true;//�������� ����������
    for (int i : a[x]) {//������ �� �������
        if (!fl[i]) {//���� �� ���������
            top(a, fl, i,res);//���������� ��������
        }
    }
	push(res, x);
}

int main(){
	setlocale(LC_ALL, "rus");
	int n, m;
	cout << "������� ����� ������";
	cin >> n;
	cout << "������� ����� ����";
	cin >> m;
	vector<int> ar[100];
	for (int i = 0; i < m; i++) {//������ ���������
		int u, v;
		cin >> u >> v;
		ar[u].push_back(v);
	}
	bool visited[100] = { false };
	stack* res = NULL;
   top(ar, visited, 0, res);//����� � �������
   while (res != NULL) {
	   cout << pop(res) << " ";
   }
    return 0;
}