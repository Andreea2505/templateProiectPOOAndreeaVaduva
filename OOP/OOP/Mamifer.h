#pragma once
#include "Animal.h"
class Mamifer: public Animal {
private:
	bool areBlana;
public:
	Mamifer(int i, std::string n, unsigned v, Client* p, bool Blana);
	double CalculeazaCost() override;
	void Afiseaza() override;



};
