#pragma once
#include "Animal.h"
class Pasare :public Animal {
private:
	double anverguraAripi;
public:
	Pasare(int i, const std::string& n, unsigned v, Client* p, double a);
	double CalculeazaCost()const  override;
	void Afiseaza()const override;


};
