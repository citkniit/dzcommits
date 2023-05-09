#include <iostream>
using namespace std;
int fib(n){
if (n == 1 || n == 2) return 1;
if (n == 1) return 0;
else if (n == 2) return 1;
else return fib(n-1) + fib(n-2);
} 
int main(){
int n;
cin >> n;
cout << fib(n);
return 0;
}
