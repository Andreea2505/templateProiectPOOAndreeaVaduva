#include "Stoc.h"
#include <iostream>

Stoc::Stoc() {}


Stoc::Stoc(const Stoc& dreapta) {
    medicamente = dreapta.medicamente;
}

Stoc& Stoc::operator=(const Stoc& dreapta) {
    if (this != &dreapta) {
        medicamente = dreapta.medicamente;
    }
    return *this;
}

void Stoc::adaugaMedicament(const Medicament& m) {
    medicamente.push_back(m);
}

void Stoc::afiseazaStoc() const {
    for (size_t i = 0; i < medicamente.size(); i++) {
        medicamente[i].afiseaza();
    }
}

Medicament* Stoc::cautaMedicament(std::string nume) {
    for (size_t i = 0; i < medicamente.size(); i++) {
        if (medicamente[i].getNume() == nume)
            return &medicamente[i];
    }
    return nullptr;
}

void Stoc::actualizeazaStoc(std::string nume, int cantitate) {
    for (size_t i = 0; i < medicamente.size(); i++) {
        if (medicamente[i].getNume() == nume) {

            for (int j = 0; j < cantitate; j++) {
                if (medicamente[i].getStoc() > 0)
                    medicamente[i].scadeStoc();
            }

            return;
        }
    }

    throw UserInputError("Medicamentul nu exista in stoc!");
}