#include "Carnivor.h"
#include <iostream>
Carnivor::Carnivor(int i, std::string n, unsigned v, Client* p, bool blana, std::string carne)
    : Mamifer(i, n, v, p, blana) {
    tipCarne = carne;
}
double Carnivor::CalculeazaCost() {
    double costBaza = Mamifer::CalculeazaCost();
    // carnivorele sunt mai scumpe cu 20%
    return costBaza * 1.2;
}

void Carnivor::Afiseaza() {
    Mamifer::Afiseaza();
    std::cout << "Tip carne: " << tipCarne << "\n";
}