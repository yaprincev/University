#include <iostream>
#include <string>
#include "Time.h"
#include "Triade.h"
int main()
{
    Triade three(1, 2, 3);
    Time four(5, 90, 60);
    cout << four.toString() << endl;
    four.plusNMinute(5);
    //three.plusOne();
    cout << four.toString() << endl;
    four.normalizeTime();
    cout << four.toString() << endl;
}