#pragma once
#include <string>

class Medicament {
private:
    std::string nume;
    int stoc;

public:
    Medicament(std::string n, int s);

    Medicament(const Medicament& dreapta);

    Medicament& operator=(const Medicament& dreapta);

    std::string getNume();
    int getStoc();
    void scadeStoc();
    void afiseaza() const;
    void cresteStoc(int cantitate);
};