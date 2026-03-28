#pragma once
#include "Animal.h"
class Pasare :public Animal {
private:
	double anverguraAripi;
public:
	Pasare(int i, std::string n, unsigned v, Client* p, double a);
	double CalculeazaCost()  override;
	void Afiseaza() override;


};
