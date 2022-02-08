#ifndef Date_H
#define Date_H
#endif // !Date_H

#include <iostream>
#include <string>
class Date {
private:
    unsigned int year, month, day, currentYear = 2021, currentMonth = 11;


public:
    Date();

    Date(std::string date);


    Date(unsigned int year, unsigned int month, unsigned int day);

    std::string toString();
    int returnYear();
 
    std::string Stazh();
};
