#include "MedicVeterinar.h"
#include <iostream>

MedicVeterinar::MedicVeterinar(std::string n, std::string t, double s, std::string spec)
    : Persoana(n, t) {
    salariu = s;
    specializare = spec;
}

MedicVeterinar::~MedicVeterinar() {}

void MedicVeterinar::afiseaza() const {
    std::cout << "Medic veterinar:\n";
    Persoana::afiseaza();
    std::cout << "Salariu: " << salariu << "\n";
    std::cout << "Specializare: " << specializare << "\n";
}

double MedicVeterinar::getSalariu() const { return salariu; }
std::string MedicVeterinar::getSpecializare() const { return specializare; }
std::string MedicVeterinar::getNume() const {
    return Persoana::getNume();
}
MedicVeterinar::~MedicVeterinar() {}
