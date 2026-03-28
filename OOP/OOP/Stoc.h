#pragma once
#include <vector>
#include "Medicament.h"
#include "Exceptii.h"

class Stoc {
private:
    std::vector<Medicament> medicamente;

public:
    Stoc();

    Stoc(const Stoc& dreapta);
    Stoc& operator=(const Stoc& dreapta);

    void adaugaMedicament(const Medicament& m);
    void afiseazaStoc() const;
    Medicament* cautaMedicament(std::string nume);
    void actualizeazaStoc(std::string nume, int cantitate);
};