#pragma once
#include "Animal.h"
class Mamifer: public Animal {
private:
	bool areBlana;
public:
	Mamifer(int i,const std::string& n, unsigned v, Client* p, bool Blana);
	double CalculeazaCost()const override;
	void Afiseaza()const override;



};
