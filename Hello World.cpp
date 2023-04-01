#include <iostream>
using namespace std;
int fib(int n)
{
    if (n == 1) {
        return 0;
 }
    if (n == 2) {
        return 1;
    }
    int n0 = 0;
    int n1 = 1;
    for (int i = 3; i <= n; i++) {
        int n2 = n0 + n1;
        n0 = n1;
        n1 = n2;
    }
    return n1;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << fib(i) << endl;
    }
    return 0;
}

