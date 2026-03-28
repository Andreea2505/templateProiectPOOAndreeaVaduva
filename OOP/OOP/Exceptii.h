#pragma once
#include <exception>
#include <string>
#include <vector>
#include <iostream>
#include "Animal.h"
#include "Persoana.h"

class UserInputError : public std::exception {
private:
    std::string mesaj;

public:
    UserInputError(const std::string& m) : mesaj(m) {}

    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

// validari input
void valideazaTelefon(const std::string& tel);
void valideazaID(int id);
void valideazaNumar(std::istream& in);
void valideazaVarsta(unsigned varsta);

// validari meniuri
void valideazaIndex(int index, int size);
void valideazaVectorGol(int size, const std::string& obiect);

// id unic
void valideazaIdUnic(int id, const std::vector<Animal*>& animale);
void valideazaIdUnicPersoane(int id, const std::vector<Persoana*>& persoane);