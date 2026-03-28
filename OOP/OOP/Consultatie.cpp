#include "Consultatie.h"
#include <iostream>

Consultatie::Consultatie(Animal* a, MedicVeterinar* m) {
    animal = a;
    medic = m;
    costConsultatie = a->CalculeazaCost();
}

void Consultatie::efectueazaConsultatie(Stoc& stoc) {
    std::string numeMed;

    std::cout << "Introdu nume medicament: ";
    std::cin >> numeMed;

    Medicament* m = stoc.cautaMedicament(numeMed);

    if (m && m->getStoc() > 0) {
        std::cout << "Medicament gasit!\n";
        m->afiseaza();

        m->scadeStoc();
        std::cout << "Medic atribuit: " << medic->getNume()<<"\n";

        std::cout << "Consultatie efectuata! Cost: " << costConsultatie << "\n";
    }
    else {
        std::cout << "Medicament indisponibil!\n";
    }
}