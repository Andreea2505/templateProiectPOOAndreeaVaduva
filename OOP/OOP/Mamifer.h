#pragma once
#include "Animal.h"
class Mamifer: public Animal {
private:
	bool areBlana;
public:
	Mamifer(int i, std::string n, unsigned v, Client* p, bool Blana);
	//override-verifica daca signatura e corect preluata din clasa parintelui 
	double CalculeazaCost() override;
	void Afiseaza() override;



};