//
// Created by Vojtěch Binar on 12.03.2022.
//
#include "datum.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

#define MAX_VALID_YR  2050
#define MIN_VALID_YR  1900


time_t now = time(0);
tm *ltm = localtime(&now);

Datum::~Datum() {
    std::cout << "Volani destruktoru. " << std::endl;
}
Datum::Datum() {
    this->day = ltm->tm_mday;
    this->month = 1 + ltm->tm_mon;
    this->year = 1900 + ltm->tm_year;
}
Datum::Datum(int d, int m, int y) {
    if (platnostY(y)){
        this->year = y;
    }else{
        this->year = 1900;
    }
    if (platnostM(m)){
        this->month = m;
    }else{
        this->month = m;
    }
    if (platnostD(d)){
        this->day = d;
    }else{
        this->day = 1;
    }
}
Datum::Datum(const Datum & orig) {
    this->day = orig.getDay();
    this->month = orig.getMonth();
    this->year = orig.getYear();
}
bool Datum::prestupny(int year) const {
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}
bool Datum::platnostD(int d) const {
    if (d < 1 || d > 31)
        return false;
    if (this->month == 2)
    {
        if (prestupny(this->year))
            return (d <= 29);
        else
            return (d <= 28);
    }
    if (this->month == 4 || this->month == 6 ||
            this->month == 9 || this->month == 11)
        return (d <= 30);
    return true;
}
bool Datum::platnostM(int m) const {
    if (m < 1 || m > 12)
        return false;
    return true;
}
bool Datum::platnostY(int y) const {
    if (y > MAX_VALID_YR ||
        y < MIN_VALID_YR)
        return false;
    return true;
}

bool Datum::platnost(int d, int m, int y) const {
    if(!this->platnostD(d)||!this->platnostM(m)||!this->platnostY(y))
        return false;
    return true;
}
int Datum::getDay() const {
    return this->day;
}
int Datum::getMonth() const {
    return this->month;
}
int Datum::getYear() const {
    return this->year;
}

std::string Datum::getDatum() const {
    return std::to_string(this->day) + ". " + std::to_string(this->month) + ". " + std::to_string(this->year);
}
int Datum::pocetDni() const {
    struct std::tm a = {0,0,0,1,0,0};
    struct std::tm b = {0,0,0,this->day, (this->month-1), (this->year-1900)};
    std::time_t x = std::mktime(&a);
    std::time_t y = std::mktime(&b);

return std::difftime(y, x)/(60 * 60 * 24);
}
int Datum::poradiDne() const{
    int mon;
    int year = this->year;
    if(this->month > 2)
        mon = this->month; //for march to december month code is same as month
    else{
        mon = (12+this->month); //for Jan and Feb, month code will be 13 and 14
        year--; //decrease year for month Jan and Feb
    }
    int y = year % 100; //last two digit
    int c = year / 100; //first two digit
    int w = (this->day + floor((13*(mon+1))/5) + y + floor(y/4) + floor(c/4) + (5*c));
    w = w % 7;
    if (!w){
        return 6;
    }else if (w == 1){
        return 7;
    }else{
        return (7-w);
    }
}
bool Datum::setYear(int y) {
    if(this->platnostY(y)){
        this->year = y;
        return true;
    }
    return false;
}
bool Datum::setMonth(int m) {
    if(this->platnostM(m)){
        this->month = m;
        return true;
    }
    return false;
}
bool Datum::setDay(int d) {
    if(this->platnostD(d)){
        this->day = d;
        return true;
    }
    return false;
}
bool Datum::setDatum(int d, int m, int y) {
    if (platnostY(y)){
        this->year = y;
    }else{
        return false;
    }
    if (platnostM(m)){
        this->month = m;
    }else{
        return false;
    }
    if (platnostD(d)){
        this->day = d;
    }else{
        return false;
    }
    return true;
}
std::string Datum::systemDatum() const {
    return std::to_string(ltm->tm_mday) + ". " + std::to_string(1 + ltm->tm_mon) + ". " + std::to_string(1900 + ltm->tm_year);
}
int Datum::dnyVMesici(int month) const {
    if( month == 2)
    {
        if(prestupny(this->year))
            return 29;
        else
            return 28;
    }
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
            ||month == 10 || month==12)
        return 31;
    else
        return 30;
}