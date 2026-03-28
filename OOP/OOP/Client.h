#pragma once
#include "Persoana.h"
#include <vector>
class Animal;
class Client : virtual public Persoana {
protected:
    int id;
    std::string adresa;
    std::vector<Animal*> animale;
    static int nrClienti;

public:
    Client(int i, std::string n, std::string t, std::string adr);
    ~Client();

    void adaugaAnimal(Animal* a);
    void afiseaza() const;
    void setNume(std::string n);
    int getId() const;

    static int getNrClienti();
};