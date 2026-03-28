#include "Animal.h"
#include "Client.h"

int Animal::nrAnimale = 0;
Animal::Animal(int i, const std::string& n, unsigned v, Client* p) {
	id = i;
	nume = n;
	varsta = v;
	proprietar = p;
	nrAnimale++;
}

Animal:: ~Animal(){
	nrAnimale--;
}
void Animal::Afiseaza()const {
	std::cout << "id: " << id << "  nume: " << nume << "  varsta: " << varsta;
}
int Animal::getId()const {
	return id;
}
int Animal::getNrAnimale() {
	return nrAnimale;
}
