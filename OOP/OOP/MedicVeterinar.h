#pragma once
#include "Persoana.h"
#include <string>

class MedicVeterinar : virtual public Persoana {
protected:
    double salariu;
    std::string specializare;

public:
    MedicVeterinar(const std::string& n, std::string t, double s, std::string spec);
     ~MedicVeterinar();

    void afiseaza() const;
    double getSalariu() const;
    std::string getSpecializare() const;

    std::string getNume() const;

};
