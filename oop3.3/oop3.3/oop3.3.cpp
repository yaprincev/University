#include <iostream>
#include <string>
//#include "Date.h"
#include "Payment.h"

using namespace std;



int main()
{
    setlocale(LC_ALL, "Russian");
    Date date("01.05.2021");
    Payment max("Япринцев Максим", 200, date, 2, 10, 12);
    max.vichisl_nach_summ();
    max.vichisl_yder_summ();
    max.vichisl_zp();
   
    cout << max << endl;
}