#include <iostream>
#include "datum.h"

using std::cout;
using std::cin;
using std::endl;
int main() {
    int d;
    int m;
    int y;
    int odpoved;
    Datum datum;
    Datum dnes;
    Datum random( 1, 4, 2003);
    do {

        cout << "Zadej den: ";
        cin >> d;
        cout << "Zadej mesic: ";
        cin >> m;
        cout << "Zadej rok: ";
        cin >> y;
        if (datum.setDatum(d, m,y)) {
            cout << "Zadane datum je: "<< datum.getDatum() << endl;
            cout << "Pocet dni od 1. 1. 1900: "<< datum.pocetDni() << endl;
            cout << "Je "<< datum.poradiDne()<< ". den v tydnu." << endl<< endl;

            cout << "Datum dnes je: "<< dnes.getDatum() << endl;
            cout << "Pocet dni od 1. 1. 1900: "<< dnes.pocetDni() << endl;
            cout << "Je "<< dnes.poradiDne()<< ". den v tydnu." << endl<< endl;

            cout << "Datum náhodné je: "<< random.getDatum() << endl;
            cout << "Pocet dni od 1. 1. 1900: "<< random.pocetDni() << endl;
            cout << "Je "<< random.poradiDne()<< ". den v tydnu." << endl<< endl;
        } else {
            cout << "Chybne zadane datum!" << endl;
        }

        cout << "Pro ukonceni stiskni 1: ";
        cin >> odpoved;
    } while (odpoved != 1);
}
