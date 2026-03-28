#pragma once
#include "Animal.h"
class Reptila :public Animal {
private:
	bool esteVeninoasa;
public:
	Reptila(int i, const std::string& n, unsigned v,Client* p, bool e);
	double CalculeazaCost()const override;
	void Afiseaza()const override;
};
