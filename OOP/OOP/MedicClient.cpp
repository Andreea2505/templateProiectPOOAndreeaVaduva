#include "MedicClient.h"
#include <iostream>

MedicClient::MedicClient(int id, std::string n, std::string t, std::string adr, double s, std::string spec)
    : Persoana(n, t), Client(id, n, t, adr), MedicVeterinar(n, t, s, spec) {
 
}

MedicClient::~MedicClient() {}

void MedicClient::afiseaza() const {
    std::cout << "ClientMedic (client + medic):\n";
    Persoana::afiseaza();
    std::cout << "ID: " << id << "\n";
    std::cout << "Adresa: " << adresa << "\n";
    std::cout << "Nr animale: " << animale.size() << "\n";
    std::cout << "Salariu: " << salariu << "\n";
    std::cout << "Specializare: " << specializare << "\n";
}