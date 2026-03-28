#include "Medicament.h"
#include <iostream>

Medicament::Medicament(std::string n, int s) {
    nume = n;
    stoc = s;
}
Medicament::Medicament(const Medicament& dreapta) {
    nume = dreapta.nume;
    stoc = dreapta.stoc;
}
Medicament& Medicament::operator=(const Medicament& dreapta) {
    if (this != &dreapta) {
        nume = dreapta.nume;
        stoc = dreapta.stoc;
    }
    return *this;
}

std::string Medicament::getNume() {
    return nume;
}

int Medicament::getStoc() {
    return stoc;
}

void Medicament::scadeStoc() {
    if (stoc > 0) stoc--;
}

void Medicament::afiseaza() const {
    std::cout << "Medicament: " << nume << " | Stoc: " << stoc << "\n";
}

void Medicament::cresteStoc(int cantitate) {
    stoc += cantitate;
}