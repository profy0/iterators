#include "List.h"
#include <iostream>
#include <time.h>
#include <windows.h>
#include <vector>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(0));
    unsigned capacity, count;
    cout << "Введите объём стека: ";
    cin >> capacity;
    List list(capacity);
    cout << "Введите количество элементов для заполнения стека: ";
    cin >> count;
    for (auto i = 0; i < count; i++) {
        int x = rand() % 5;
        if (list.append(x))
            cout << x << " ";
    }
    cout << endl;
    ListIteratorStep l(list, 3);
    unsigned cnt = 0;
    while (--l) {cnt++;cerr << (*l) << " ";}
    cerr << endl;
    cout << cnt << endl;
    ListIteratorValue r(list, 4);
    cnt = 0;
    while (--r) {cnt++;cerr << (*r) << " ";}
    cerr << endl;
    cout << cnt << endl;
    ListIteratorPredicate p(list, (void*) 5);
    cnt = 0;
    while (--p) {cnt++; cerr << (*p) << " ";}
    cerr << endl;
    cout << cnt << endl;

}

