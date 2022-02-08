#include "Triade.h"
#include <iostream>
#include <string>

using namespace std;

Triade::Triade() {
    first = 0;
    second = 0;
    third = 0;
}

Triade::Triade(int fir, int sec, int thir) {
    first = fir;
    second = sec;
    third = thir;
}

void Triade::plusFirst() {
    first++;
}

void Triade::plusSecond() {
    second++;
}
void Triade::plusThird() {
    third++;
}

string Triade::toString() {
    return to_string(first) + " " + to_string(second) + " " + to_string(third);
}