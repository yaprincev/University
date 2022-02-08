#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

Date::Date() {
    year = 0;
    month = 0;
    day = 0;
    currentYear = 2021;
    currentMonth = 12;

}

Date::Date(string date) {
    string day, month, year;


    day = date.substr(0, date.find("."));
    date.erase(0, date.find(".") + 1);
    month = date.substr(0, date.find("."));
    year = date.erase(0, date.find(".") + 1);


    this->day = atoi(day.c_str());
    this->month = atoi(month.c_str());
    this->year = atoi(year.c_str());
}

Date::Date(unsigned int year, unsigned int month, unsigned int day) {
    this->day = day;
    this->month = month;
    this->year = year;
}




string Date::toString() {
    return "√од: " + to_string(year) + " ћес€ц: " + to_string(month) + " день: " + to_string(day);
}
string Date::Stazh() {
    if ((this->currentYear - this->year) > 1) {
        return to_string(this->currentYear - this->year);
    }
    else if ((this->currentYear - this->year) == 0) {
        return to_string(this->currentMonth - this->month) + " мес€ца(ев)";
    }
    else if (((this->currentYear - this->year) == 1) && (this->currentMonth + (12 - this->month) < 12)) {
        return to_string(this->currentMonth + (12 - this->month)) + " мес€ца(ев)";
    }
    return "1 год";
}
int Date::returnYear() {
    return year;
}