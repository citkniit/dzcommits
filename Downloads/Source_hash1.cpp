#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
struct worker {
    string surname;
    string profession;  //должность
    string BirthDate;
    int experience;
    int salary;         //зарплата
};

struct list_elements {
    list_elements* prev = nullptr;       //первый элемент всегда указывает на nullptr
    worker val;
    list_elements* next = nullptr;       //последний элемент всегда указывает на nullptr
};

struct list {
    list_elements* head = nullptr;
    int size = 0;
    list_elements* tail = nullptr;
};

void push(list*& l, worker& num) {
    list_elements* r = new list_elements;//создаем новый элемент
    r->val = num;
    if (!l->head && !l->tail) {
        l->head = r;
        l->tail = r;
    }                                    //если лист пуст, то новый элемент и голова, и хвост
    else {
        r->prev = l->tail;		         //предыдущий элемент - бывший хвост
        l->tail->next = r;
        l->tail = r;
    }                                    //теперь r - хвост
    l->size++;                           //размер листа
}

void print(list*& l) {
    list_elements* p = l->head;			 //указатель на голову
    while (p) { 			                 //пока не дошли до конца списка
        cout << p->val.surname << " ";
        p = p->next; 		             //переход к следующему элементу
    }
}

void del(list*& l, string s, const int mod, int h) {
    list_elements* a = l->head;
    while (a) {                              //пока не дошли до конца списка
        if (a->val.surname == s && a->val.salary == h) {
            break;
        }
        a = a->next;                    //переход к следующему элементу
    }
    if (l->head == a && l->tail == a) {   //если список из одного элемента
        l->head = nullptr;
        l->tail = nullptr;
    }
    else if (!a->prev) {                 //если элемент первый в списке
        l->head = a->next;
        l->head->prev = nullptr;
    }
    else if (!a->next) {                 //если элемент последний в списке
        l->tail = a->prev;
        l->tail->next = nullptr;
    }
    else {                              //если элемент внутри списка
        a->next->prev = a->prev;
        a->prev->next = a->next;
    }
    delete a;
    l->size--;
}

void find(list*& l, string s, const int mod, int h) {
        bool f = false;
        list_elements* p = l->head;      //указатель на голову
        while (p) {                              //пока не дошли до конца списка
            if (p->val.surname == s && p->val.salary == h) {
                f = true;
                cout << left << setw(16) << p->val.surname << setw(16) << p->val.profession
                    << setw(16) << p->val.BirthDate << setw(8) << p->val.experience << p->val.salary << '\n';
                break;
            }
            p = p->next;                    //переход к следующему элементу
        }
        if (!f) cout << "Не найден\n";
    }

void del_list(list*& l) {
    list_elements* p = l->head;
    while (p != l->tail) {               //пока не дошли до последнего элемента
        p = p->next;
        delete p->prev;
    }
    delete p; l->head = nullptr;
    l->tail = nullptr; l->size = 0;
}

int main() {
    setlocale(LC_ALL, "rus");
    const int mod = 7;			//хэширую по остатку от деления на 7
    vector <list*> v(mod); worker x;
    ifstream in("input.txt");           //создаём поток для считывания
    for (int i = 0; i < mod; ++i) {
        list* l = new list;
        v[i] = l;
    }
    while (in.peek() != EOF) {
        in >> x.surname >> x.profession >> x.BirthDate >> x.experience >> x.salary;
        push(v[x.salary % mod], x);
    }
    in.close();     //закрываем файл
    for (int i = 0; i < mod; ++i, cout << '\n') {
        cout << i << " : ";
        print(v[i]);
    }
    string s; int h;
    cin >> s;
    cin >> h;
    find(v[h%mod], s, mod, h);
    del(v[h%mod], s, mod, h);
    cout << "После удаления:\n";
    for (int i = 0; i < mod; ++i, cout << '\n') {
        cout << i << " : ";
        print(v[i]);
    }
    for (int i = 0; i < mod; ++i) del_list(v[i]);    //очищаем память
    return 0;
}