﻿// yamp4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <stack>  
using namespace std;

struct PirateShip
{
    string name;
    int guns;
    string capitanName;
    bool isSunk;

};








int main()
{
    string line;
    stack <string> steck;
    int count = 0;
    PirateShip pirate;
    ifstream file("textfile.txt");
    while (!file.eof()) {
        while (count < 4) {
            file >> line;
            switch (count)
            {
            case 0: pirate.name = line;
                break;
            case 1: pirate.guns = stoi(line);
                break;
            case 2: pirate.capitanName = line;
                break;
            case 3: if (line == "true") { pirate.isSunk = true; }
                  else pirate.isSunk = false;
                break;
            default:
                break; 
            }
            count++;
        }
        if (pirate.isSunk) steck.push(pirate.name);
        count = 0;
    }
    file.close();
    cout << steck.top() << endl;
    steck.pop();
    cout << steck.top();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
