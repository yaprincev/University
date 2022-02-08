#pragma once
#ifndef Triade_H
#define Triade_H
#endif // !Triade_H

#include <iostream>
#include <string>
using namespace std;
class Triade {
protected:
    int first, second, third;
public:
    Triade();

    Triade(int fir, int sec, int thir);

    void plusFirst();
    void plusSecond();
    void plusThird();


    string toString();
};