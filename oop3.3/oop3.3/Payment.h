#ifndef Payment_H
#define Payment_H
#include "Date.h"
#endif // !Payment_H

#include <iostream>
#include <string>
using namespace std;
class Payment {
private:
    string fio;
    float oklad;
    Date year_of_start;
    float procent_nadbavki;
    float nalog;
    int otrab_day_month;
    int rab_day_month;
    float nachislen_sum;
    float uderzh_sum;
    float zp;
public:
    Payment();
    Payment(string fio, float oklad, Date year, float procent, int otrab_day_month, int rab_day_month);
    // read();

   // void Display();
    string toString();
    void vichisl_nach_summ();
    void vichisl_yder_summ();

    void vichisl_zp();
    friend ostream& operator<<(ostream& ostr, Payment &n);
    string stazh();
};