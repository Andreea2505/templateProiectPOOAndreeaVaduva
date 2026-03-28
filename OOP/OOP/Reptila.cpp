#include "Reptila.h"
#include<iostream>
Reptila::Reptila(int i, std::string n, unsigned v,Client * p, bool e) :Animal(i, n, v,p) {
	esteVeninoasa = e;
}
double Reptila::CalculeazaCost() {
	if (esteVeninoasa)
		return 150;
	else
		return 90;
}

void Reptila::Afiseaza()
{
	Animal::Afiseaza();
	std::cout << "Este veninoasa: ";
	if (esteVeninoasa)
		std::cout << "Da\n";
	else
		std::cout << "Nu\n";
}
