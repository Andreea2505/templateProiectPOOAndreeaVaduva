#include "Erbivor.h"
#include <iostream>

Erbivor::Erbivor(int i, std::string n, unsigned v, Client* p, bool blana, std::string plante)
    : Mamifer(i, n, v, p, blana) {
    tipPlante = plante;
}

double Erbivor::CalculeazaCost() {
    double costBaza = Mamifer::CalculeazaCost();
    // erbivorele sunt mai ieftine cu 10%
    return costBaza * 0.9;
}

void Erbivor::Afiseaza() {
    Mamifer::Afiseaza();
    std::cout << "Tip plante: " << tipPlante << "\n";
}