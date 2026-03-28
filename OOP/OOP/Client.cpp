#include "Client.h"
#include <iostream>

int Client::nrClienti = 0;
Client::Client(int i, std::string n, std::string t, std::string adr)
    : Persoana(n, t) {
    id = i;
    adresa = adr;
    nrClienti++;
}

Client::~Client() {}
void Client::adaugaAnimal(Animal* a) {
    animale.push_back(a);
}

void Client::afiseaza() const {
    Persoana::afiseaza();
    std::cout << "ID: " << id << "\n";
    std::cout << "Adresa: " << adresa << "\n";
    std::cout << "Nr animale: " << animale.size() << "\n";
}

void Client::setNume(std::string n) {
    nume = n;
}

int Client::getId() const {
    return id;
}

int Client::getNrClienti() {
    return nrClienti;
}