#include <iostream>
#include <cmath>
using namespace std;
int H(int n,int x) {
	if (n == 0)
		return 1;
	if (n == 1)
		return 2*x;
	if (n > 1)
		return 2 * x * H(n-1, x) - 2 * (n-1) * H(n - 2, x);//по формуле,так как по формуле ищем n+1 а тут n то меняем n на n-1
}
int main() {
	int n,x;
	cin >> n >> x;
	cout << H(n,x);//вывод
	system("pause");
	return 0;
}