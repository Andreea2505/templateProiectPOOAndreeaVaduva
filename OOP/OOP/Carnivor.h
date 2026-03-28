#pragma once
#include "Mamifer.h"
class Carnivor :public Mamifer {
private:
	std::string tipCarne;
public:
	Carnivor(int i, const std::string& n, unsigned v, Client* p, bool blana, std::string carne);
	double CalculeazaCost()const override;
	void Afiseaza() const override;

};
