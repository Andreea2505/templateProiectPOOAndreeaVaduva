#include "Persoana.h"
#include <iostream>
Persoana::Persoana(std::string n, std::string t) {
    nume = n;
    telefon = t;
}
Persoana::~Persoana() {}

void Persoana::afiseaza() const {
    std::cout << "Nume: " << nume << "\n";
    std::cout << "Telefon: " << telefon << "\n";
}
std::string Persoana::getNume() const {
    return nume;
}