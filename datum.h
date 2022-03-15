//
// Created by Vojtěch Binar on 12.03.2022.
//

#ifndef DATUM_DATUM_H
#define DATUM_DATUM_H
#include <iostream>
using std::string;


class Datum {
public:
    Datum();
    Datum(int, int, int);
    Datum(const Datum &);
    virtual ~Datum();
    int getMonth()const;
    int getDay()const;
    int getYear()const;
    string getDatum()const;
    int pocetDni()const;
    int poradiDne()const;
    bool setYear(int);
    bool setMonth(int);
    bool setDay(int);
    bool setDatum(int, int, int);

//    Zlomek & operator=(const Zlomek &);
//    Zlomek & operator+=(const Zlomek &);
//    Zlomek & operator-=(const Zlomek &);
//    Zlomek & operator*=(const Zlomek &);
//    Zlomek & operator/=(const Zlomek &);
//    Zlomek operator+(const Zlomek &) const;
//    Zlomek operator-(const Zlomek &) const;
//    Zlomek operator*(const Zlomek &) const;
//    Zlomek operator/(const Zlomek &) const;
//    bool operator==(const Zlomek &) const;
//    friend std::ostream & operator<<(std::ostream &, const Zlomek &);
private:
    int day;
    int year;
    int month;
    bool platnostD(int)const;
    bool platnostM(int)const;
    bool platnostY(int)const;
    bool platnost(int, int, int)const;
    bool prestupny(int)const;
    int dnyVMesici(int)const;
    string systemDatum()const;

//    int nsd(int, int)const;
//    int nsn(int, int)const;
//    void vymenaHodnot(int &, int &);
};
#endif //DATUM_DATUM_H
