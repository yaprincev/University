#include "Payment.h"
#include <iostream>
#include <string>

using namespace std;

Payment::Payment() {

    fio = "";
    oklad = 0;
    procent_nadbavki = 0;
    nalog = 0.13;
    otrab_day_month = 0;
    rab_day_month = 0;
    nachislen_sum = 0;
    uderzh_sum = 0;
    zp = 0;
}

Payment::Payment(string fio, float oklad, Date year, float procent, int otrab_day_month, int rab_day_month) {
    this->fio = (fio.length() > 5) ? fio : "";
    this->year_of_start = year;
    this->oklad = (oklad > 0) ? oklad : 0;
    this->procent_nadbavki = (procent > 0) ? procent : 0;
    this->nalog = 0.13;
    this->otrab_day_month = (otrab_day_month > 0) ? otrab_day_month : 0;
    this->rab_day_month = (rab_day_month > 0) ? rab_day_month : 0;
    this->nachislen_sum = 0;
    this->uderzh_sum = 0;
    this->zp = 0;
}

/*void Payment::read() {
    string fio, fam, im, ot;
    float oklad;
    Date year_of_start;
    float procent_nadbavki;
    float nalog;
    int otrab_day_month;
    int rab_day_month;
    float nachislen_sum;
    float uderzh_sum;

    cout << "Введите ФИО" << endl;
    cin >> fam >> im >> ot;
    fio = fam + " " + im + " " + ot;
    cout << "Введите оклад" << endl;
    cin >> oklad;
    cout << "Введите дату трудоустройства" << endl;
    this->year_of_start.Read();
    cout << "Введите процент надбавки" << endl;
    cin >> procent_nadbavki;
    cout << "Количество отработанных дней" << endl;
    cin >> otrab_day_month;
    cout << "Введите количество рабочих дней" << endl;
    cin >> rab_day_month;
    Init(fio, oklad, year_of_start, procent_nadbavki, otrab_day_month, rab_day_month);
}*/

/*void Payment::Display() {
    cout << "Оклад: " << oklad << endl;
    year_of_start.Display();
    cout << "Процент надбавки: " << procent_nadbavki << endl;
    cout << "Налог: " << nalog << endl;
    cout << "Количество отработанных дней: " << otrab_day_month << endl;
    cout << "Количество рабочих дней: " << rab_day_month << endl;
    cout << "Начисленная сумма: " << nachislen_sum << endl;
    cout << "Удержанная сумма: " << uderzh_sum << endl;
    cout << "Зарплата: " << zp << endl;
}*/

void Payment::vichisl_nach_summ()
{
    nachislen_sum = oklad * rab_day_month;
}

void Payment::vichisl_yder_summ()
{
    uderzh_sum = nachislen_sum * 0.01 + nachislen_sum * nalog;
}

void Payment::vichisl_zp()
{
    zp = nachislen_sum - uderzh_sum;
}
string Payment::stazh() {
    return year_of_start.Stazh();
}

string Payment::toString() {
    return "Оклад: " + to_string((int)oklad) + "\nПроцент надбавки: " + to_string((int)procent_nadbavki) + "\nНалог: " + to_string(nalog) + "\nКоличество отработанных дней: " + 
        to_string(otrab_day_month) + "\nКоличество рабочих дней: " + to_string(rab_day_month) + "\nНачисленная сумма: " + to_string((int)nachislen_sum) + "\nУдержанная сумма: " 
        + to_string((int)uderzh_sum) + "\nЗарплата: " + to_string((int)zp);
}

ostream& operator<<(ostream& ostr, Payment &n) {
    ostr << n.fio << endl << n.toString() << "\nСтаж: " << n.stazh() << endl;
    return (ostr);
}