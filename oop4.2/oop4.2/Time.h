#pragma once
#pragma once
#ifndef Time_H
#define Rime_H
#include "Triade.h"
#endif // !Triade_H

class Time : public Triade {
public:

    Time(int hour, int minute, int sec);


    void plusNSecond(int n);

    void plusNMinute(int n);


    void normalizeTime();
};