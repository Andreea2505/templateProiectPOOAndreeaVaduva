#pragma once
#include "Animal.h"
class Reptila :public Animal {
private:
	bool esteVeninoasa;
public:
	Reptila(int i, std::string n, unsigned v,Client* p, bool e);
	double CalculeazaCost() override;
	void Afiseaza() override;
};
