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

    cout << "������� ���" << endl;
    cin >> fam >> im >> ot;
    fio = fam + " " + im + " " + ot;
    cout << "������� �����" << endl;
    cin >> oklad;
    cout << "������� ���� ���������������" << endl;
    this->year_of_start.Read();
    cout << "������� ������� ��������" << endl;
    cin >> procent_nadbavki;
    cout << "���������� ������������ ����" << endl;
    cin >> otrab_day_month;
    cout << "������� ���������� ������� ����" << endl;
    cin >> rab_day_month;
    Init(fio, oklad, year_of_start, procent_nadbavki, otrab_day_month, rab_day_month);
}*/

/*void Payment::Display() {
    cout << "�����: " << oklad << endl;
    year_of_start.Display();
    cout << "������� ��������: " << procent_nadbavki << endl;
    cout << "�����: " << nalog << endl;
    cout << "���������� ������������ ����: " << otrab_day_month << endl;
    cout << "���������� ������� ����: " << rab_day_month << endl;
    cout << "����������� �����: " << nachislen_sum << endl;
    cout << "���������� �����: " << uderzh_sum << endl;
    cout << "��������: " << zp << endl;
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
    return "�����: " + to_string((int)oklad) + "\n������� ��������: " + to_string((int)procent_nadbavki) + "\n�����: " + to_string(nalog) + "\n���������� ������������ ����: " + 
        to_string(otrab_day_month) + "\n���������� ������� ����: " + to_string(rab_day_month) + "\n����������� �����: " + to_string((int)nachislen_sum) + "\n���������� �����: " 
        + to_string((int)uderzh_sum) + "\n��������: " + to_string((int)zp);
}

ostream& operator<<(ostream& ostr, Payment &n) {
    ostr << n.fio << endl << n.toString() << "\n����: " << n.stazh() << endl;
    return (ostr);
}