#include <iostream>
#include "set.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Set<int> set;
    set.insert(4);
    set.insert(5);
    set.insert(3);
    set.insert(1);
    cout << "Первое множество: " << set << endl;

    set.remove(3);
    set.remove(4);
    cout << "Первое множество: " << set << endl;

    Set<int> sSet;
    sSet.insert(5);
    sSet.insert(7);
    sSet.insert(6);
    cout << "Второе множество: " << sSet << endl;

    cout << "Индекс элемента 7 во втором множестве: " << sSet.indexOf(7) << endl;
    cout << "Индекс элемента 101 во втором множестве: " << sSet.indexOf(101) << endl;
    cout << "Содержит ли второе множество элемент 5: " << (sSet.isExist(5) ? "да" : "нет") << endl;
    cout << "Содержит ли второе множество элемент 201: " << (sSet.isExist(201) ? "да" : "нет") << endl;

    cout << set << " + " << sSet << " = ";
    set.unite(sSet);
    cout << set << endl;
    set.insert(10);
    set.insert(9);
    cout << "Первое множество: " << set << endl;

    cout << set << " - " << sSet << " = ";
    set.subtract(sSet);
    cout << set << endl;

    set.insert(5);
    set.insert(7);
    cout << set << " & " << sSet << " = ";
    set.intersect(sSet);
    cout << set << endl;

    Set<int> tSet = sSet;
    cout << tSet << " = " << sSet << endl;
}