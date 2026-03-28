#pragma once
#include "Mamifer.h"
class Carnivor :public Mamifer {
private:
	std::string tipCarne;
public:
	Carnivor(int i, std::string n, unsigned v, Client* p, bool blana, std::string carne);
	double CalculeazaCost() override;
	void Afiseaza() override;

};
