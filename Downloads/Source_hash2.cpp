#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct worker {
    string surname;
    string profession;  //должность
    string BirthDate;
    int experience;
    int salary;         //зарплата
};

void find(worker* mas, string s, int h, const int M, const int N) {
    int t = h % M, i = 0;
    bool f = false;
    while (t < N) {
        if (mas[t].surname == s && mas[t].experience == h) {
            cout << left << setw(16) << mas[t].surname << setw(16) << mas[t].profession
                << setw(16) << mas[t].BirthDate << setw(8) << mas[t].experience << mas[t].salary << '\n';
            f = true;
            break;
        }
        ++i;
        t = h % M + i * (1 + h % (M - 1));
    }
    if (!f) cout << "Не найден\n";
}

int main() {
    const int M = 7, N = 30; int t;
    worker x = { "0", "0", "0", 0, 0 };
    worker mas[N];
    for (int i = 0; i < N; i++)
        mas[i] = x;                     //заполняем нулевыми элементами
    ifstream in("input.txt");           //создаём поток для считывания
    while (in.peek() != EOF) {
        in >> x.surname >> x.profession >> x.BirthDate >> x.experience >> x.salary;
        int i = 0;
        while (true) {
            t = x.experience % M + i * (1 + x.experience % (M - 1));
            if (mas[t].surname == "0") {    //если свободно
                mas[t] = x;
                break;
            }
            ++i;
        }
    }
    in.close();     //закрываем файл
    for (int i = 0; i < N; i++) {
        if (mas[i].surname == "0") cout << setw(2) << i << " : " << "NULL\n";
        else cout << setw(2) << i << " : " << mas[i].surname << ' ' << mas[i].experience << '\n';
    }
    string s; int k;
    cin >> s >> k;
    find(mas, s, k, M, N);
    return 0;
}