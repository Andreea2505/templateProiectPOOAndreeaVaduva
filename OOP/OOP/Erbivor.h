#pragma once
#include "Mamifer.h"

class Erbivor : public Mamifer {
private:
    std::string tipPlante; // tipul de plante preferat
public:
    Erbivor(int i, std::string n, unsigned v, Client* p, bool blana, std::string plante);
    //mostenite de la mamifer,care le a mostenit de la animal 
    double CalculeazaCost() override;
    void Afiseaza() override;
};
