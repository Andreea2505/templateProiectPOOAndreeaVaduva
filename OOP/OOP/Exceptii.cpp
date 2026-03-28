#include "Exceptii.h"
#include <regex>
#include <limits>
#include "Client.h"

void valideazaTelefon(const std::string& tel) {
    std::regex pattern("^07[0-9]{8}$");
    if (!std::regex_match(tel, pattern))
        throw UserInputError("Telefon invalid! Format: 07xxxxxxxx");
}

void valideazaID(int id) {
    if (id <= 0)
        throw UserInputError("ID invalid! Trebuie sa fie pozitiv.");
}

void valideazaNumar(std::istream& in) {
    if (in.fail()) {
        in.clear();
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw UserInputError("Trebuie introdus un NUMAR valid!");
    }
}

void valideazaVarsta(unsigned varsta) {
    if (varsta == 0 || varsta > 100)
        throw UserInputError("Varsta animal invalida!");
}

void valideazaIndex(int index, int size) {
    if (index < 0 || index >= size)
        throw UserInputError("Index invalid!");
}

void valideazaVectorGol(int size, const std::string& obiect) {
    if (size == 0)
        throw UserInputError("Nu exista " + obiect + " in sistem!");
}

void valideazaIdUnic(int id, const std::vector<Animal*>& animale) { 
    for (size_t i = 0; i < animale.size(); i++) {
        if (animale[i]->getId() == id)
            throw UserInputError("Exista deja un animal cu acest ID!");
    }

}
void valideazaIdUnicPersoane(int id, const std::vector<Persoana*>& persoane) {
    for (size_t i = 0; i < persoane.size(); i++) {
        Client* c = dynamic_cast<Client*>(persoane[i]);
        if (c && c->getId() == id)
            throw UserInputError("Exista deja o persoana cu acest ID!");
    }
}