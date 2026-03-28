#pragma once
#include <vector>
#include "Animal.h"
#include "Persoana.h"
#include "Stoc.h"

class Meniu {
private:
    static Meniu* instanta;

    std::vector<Animal*> animale;
    std::vector<Persoana*> persoane;
    Stoc stoc;

    Meniu();

public:
    static Meniu* getInstanta();
    ~Meniu();

    void ruleaza();
    void adaugaPersoana();
    void adaugaAnimal();
    void afiseazaStoc();
    void adaugaMedicament();
    void efectueazaConsultatie();
    void afiseazaToateDatele();
    void stergeAnimal();
    void afiseazaStatistici();
    void actualizeazaStocMedicament();
};