#include "Pasare.h"
#include<iostream>
Pasare::Pasare(int i, const std::string& n, unsigned v, Client* p, double a) :Animal(i, n, v, p) {
	anverguraAripi = a;
}
double Pasare::CalculeazaCost() const{
	return 70 + anverguraAripi;
}
void Pasare::Afiseaza()const{
	Animal::Afiseaza();
	std::cout << "Anvergura aripi: " << anverguraAripi << "\n";
}
