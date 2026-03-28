#include "Mamifer.h"
Mamifer::Mamifer(int i, std::string n, unsigned v, Client* p, bool blana) :
	Animal(i, n, v, p) {
	areBlana = blana;
}
double Mamifer::CalculeazaCost() {
	if (areBlana)
		return 100;
	else 
		return 80;

}
void Mamifer::Afiseaza() {
	Animal::Afiseaza();
	std::cout << "Are blana: ";
	if (areBlana)
		std::cout << "Da\n";
	else
		std::cout << "Nu\n";
}