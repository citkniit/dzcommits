#include <iostream>
#include <cmath>
using namespace std;
int H(int n,int x) {
	if (n == 0)
		return 1;
	if (n == 1)
		return 2*x;
	if (n > 1)
		return 2 * x * H(n-1, x) - 2 * (n-1) * H(n - 2, x);//�� �������,��� ��� �� ������� ���� n+1 � ��� n �� ������ n �� n-1
}
int main() {
	int n,x;
	cin >> n >> x;
	cout << H(n,x);//�����
	system("pause");
	return 0;
}