#include <iostream>
#include <cmath>
using namespace std;
int fact(int i) {
	if (i < 0)
		return 0;
	if (i == 0)
		return 1;
	if (i > 0)
		return fact(i - 1) * i;//по формуле факториала
}
int main() {
	int i;
	cin >> i;
	cout << fact(i);//вывод
	system("pause");
	return 0;
}