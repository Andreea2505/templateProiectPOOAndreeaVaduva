#pragma once
#include "Animal.h"
#include "MedicVeterinar.h"
#include "Stoc.h"

class Consultatie {
private:
    Animal* animal;
    MedicVeterinar* medic;
    double costConsultatie;

public:
    Consultatie(Animal* a, MedicVeterinar* m);
    //se cauta medicamentul si se decrementeaza stocul 
    void efectueazaConsultatie(Stoc& stoc);
};