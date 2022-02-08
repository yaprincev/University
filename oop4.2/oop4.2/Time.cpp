#include "Time.h"
#include <iostream>
#include <string>

Time::Time(int hour, int minute, int sec) {
    first = hour;
    second = minute;
    third = sec;
}



void Time::plusNSecond(int n) {
    third = third + n;
}

void Time::plusNMinute(int n) {
    second = second + n;
}


void Time::normalizeTime() {
    if (third > 59) {
        second++;
        third = third - 60;
        normalizeTime();
    }
    else if (second > 59) {
        first++;
        second = second - 60;
        normalizeTime();
    }
    else { return; }
}