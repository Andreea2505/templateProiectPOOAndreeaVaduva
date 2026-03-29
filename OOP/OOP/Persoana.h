#pragma once
#include <string>
class Persoana {
protected:
    std::string nume;
    std::string telefon;
public:
    //constructor 
    Persoana(const std::string& n, std::string t);
    //destructor virtual 
    virtual ~Persoana();
    //const pt ca nu modifica obiectul 
    virtual void afiseaza() const ;
    std::string getNume() const;
};
