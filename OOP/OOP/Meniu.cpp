#include "Meniu.h"
#include "Client.h"
#include "MedicVeterinar.h"
#include "MedicClient.h"
#include "Carnivor.h"
#include "Erbivor.h"
#include "Pasare.h"
#include "Reptila.h"
#include "Consultatie.h"
#include "Medicament.h"
#include "Exceptii.h"
#include <iostream>

Meniu* Meniu::instanta = nullptr;

Meniu::Meniu() {}

Meniu::~Meniu() {
    for (size_t i = 0; i < animale.size(); i++)
        delete animale[i];

    for (size_t i = 0; i < persoane.size(); i++)
        delete persoane[i];
    instanta=nullptr;
}

Meniu* Meniu::getInstanta() {
    if (!instanta) instanta = new Meniu();
    return instanta;
}

void Meniu::ruleaza() {
    int opt;
    do {
        std::cout << "\n1.Adauga persoana\n2.Adauga animal\n3.Afisare stoc\n";
        std::cout << "4.Adauga medicament\n5.Consultatie\n6.Afisare\n7.Sterge animal\n8.Statistici\n9.Actualizare stoc medicament\n0.Exit\n";

        std::cin >> opt;
        valideazaNumar(std::cin);

        if (opt == 1) adaugaPersoana();
        else if (opt == 2) adaugaAnimal();
        else if (opt == 3) afiseazaStoc();
        else if (opt == 4)adaugaMedicament();
        else if (opt == 5) efectueazaConsultatie();
        else if (opt == 6) afiseazaToateDatele();
        else if (opt == 7) stergeAnimal();
        else if (opt == 8) afiseazaStatistici();
        else if (opt == 9) actualizeazaStocMedicament();

    } while (opt != 0);
}

void Meniu::adaugaPersoana() {
    try {
        int tip;
        std::cout << "1.Client 2.Medic 3.ClientMedic\n";
        std::cin >> tip; valideazaNumar(std::cin);

        std::cin.ignore();

        std::string nume, tel;
        std::cout << "Nume: ";
        std::getline(std::cin, nume);

        std::cout << "Telefon: ";
        std::getline(std::cin, tel);
        valideazaTelefon(tel);

        if (tip == 1 || tip == 3) {
            int id;
            std::cout << "ID: "; std::cin >> id;
            valideazaNumar(std::cin);
            valideazaID(id);
            valideazaIdUnicPersoane(id, persoane);

            std::cin.ignore();

            std::string adr;
            std::cout << "Adresa: ";
            std::getline(std::cin, adr);

            if (tip == 1)
                persoane.push_back(new Client(id, nume, tel, adr));
            else {
                double salariu;
                std::cout << "Salariu: "; std::cin >> salariu; valideazaNumar(std::cin);

                std::cin.ignore();

                std::string spec;
                std::cout << "Specializare: ";
                std::getline(std::cin, spec);

                persoane.push_back(new MedicClient(id, nume, tel, adr, salariu, spec));
            }
        }
        else {
            double salariu;
            std::cout << "Salariu: "; std::cin >> salariu; valideazaNumar(std::cin);

            std::cin.ignore();

            std::string spec;
            std::cout << "Specializare: ";
            std::getline(std::cin, spec);

            persoane.push_back(new MedicVeterinar(nume, tel, salariu, spec));
        }

        std::cout << "Adaugat!\n";
    }
    catch (const UserInputError& e) {
        std::cout << "Eroare: " << e.what() << "\n";
    }
}

void Meniu::adaugaAnimal() {
    try {
        int tip;
        std::cout << "1.Mamifer 2.Pasare 3.Reptila\n";
        std::cin >> tip; valideazaNumar(std::cin);

        int id; std::string nume; unsigned varsta;
        std::cout << "ID: "; std::cin >> id;
        valideazaNumar(std::cin);
        valideazaID(id);
        valideazaIdUnic(id, animale);

        std::cin.ignore();

        std::cout << "Nume: ";
        std::getline(std::cin, nume);

        std::cout << "Varsta: "; std::cin >> varsta;
        valideazaNumar(std::cin);
        valideazaVarsta(varsta);

        if (tip == 1) {
            char sub;
            std::cout << "a.Carnivor b.Erbivor\n";
            std::cin >> sub;

            bool blana;
            std::cout << "Blana(1/0): ";
            std::cin >> blana;
            valideazaNumar(std::cin);

            std::cin.ignore();

            if (sub == 'a') {
                std::string carne;
                std::cout << "Tip carne: ";
                std::getline(std::cin, carne);

                animale.push_back(new Carnivor(id, nume, varsta, nullptr, blana, carne));
            }
            else {
                std::string plante;
                std::cout << "Tip plante: ";
                std::getline(std::cin, plante);

                animale.push_back(new Erbivor(id, nume, varsta, nullptr, blana, plante));
            }
        }
        else if (tip == 2) {
            double a;
            std::cout << "Anvergura: ";
            std::cin >> a;
            valideazaNumar(std::cin);

            animale.push_back(new Pasare(id, nume, varsta, nullptr, a));
        }
        else {
            bool v;
            std::cout << "Veninos(1/0): ";
            std::cin >> v;
            valideazaNumar(std::cin);

            animale.push_back(new Reptila(id, nume, varsta, nullptr, v));
        }

        std::cout << "Animal adaugat!\n";
    }
    catch (const UserInputError& e) {
        std::cout << "Eroare: " << e.what() << "\n";
    }
}
void Meniu::adaugaMedicament() {
    try {
        std::string nume;
        int cantitate;

        std::cin.ignore();

        std::cout << "Nume medicament: ";
        std::getline(std::cin, nume);

        std::cout << "Cantitate: ";
        std::cin >> cantitate;
        valideazaNumar(std::cin);

        Medicament m(nume, cantitate); 
        stoc.adaugaMedicament(m);

        std::cout << "Medicament adaugat!\n";
    }
    catch (const UserInputError& e) {
        std::cout << e.what() << "\n";
    }
}

void Meniu::afiseazaStoc() {
    stoc.afiseazaStoc();
}

void Meniu::afiseazaToateDatele() {
    std::cout << "Persoane: " << "\n";
    for (size_t i = 0; i < persoane.size(); i++)
        persoane[i]->afiseaza();
    std::cout << "Animale: " << "\n";
    for (size_t i = 0; i < animale.size(); i++)
        animale[i]->Afiseaza();
}

void Meniu::stergeAnimal() {
    try {
        valideazaVectorGol(animale.size(), "animale");

        for (size_t i = 0; i < animale.size(); i++) {
            std::cout << i << ". ";
            animale[i]->Afiseaza();
        }

        int index;
        std::cin >> index;
        valideazaNumar(std::cin);
        valideazaIndex(index, animale.size());

        delete animale[index];
        animale.erase(animale.begin() + index);

        std::cout << "Animal sters!\n";
    }
    catch (const UserInputError& e) {
        std::cout << e.what() << "\n";
    }
}

void Meniu::afiseazaStatistici() {
    int nrMedici = 0;

    for (size_t i = 0; i < persoane.size(); i++)
    {
        if (dynamic_cast<MedicVeterinar*>(persoane[i]))
        {
            nrMedici++;
        }
    }

    std::cout << "\nNr animale: " << Animal::getNrAnimale();
    std::cout << "\nNr clienti: " << Client::getNrClienti();
    std::cout << "\nNr medici: " << nrMedici << "\n";
}

void Meniu::actualizeazaStocMedicament() {
    try {
        std::string nume;
        int cantitate;

        std::cin.ignore();

        std::cout << "Nume medicament: ";
        std::getline(std::cin, nume);

        std::cout << "De cate ori sa se scada stocul: ";
        std::cin >> cantitate;
        valideazaNumar(std::cin);

        stoc.actualizeazaStoc(nume, cantitate);

        std::cout << "Stoc actualizat!\n";
    }
    catch (const UserInputError& e) {
        std::cout << e.what() << "\n";
    }
}

void Meniu::efectueazaConsultatie() {
    try {
        valideazaVectorGol(animale.size(), "animale");

        for (size_t i = 0; i < animale.size(); i++) {
            std::cout << i << ". ";
            animale[i]->Afiseaza();
        }

        int index;
        std::cin >> index;
        valideazaNumar(std::cin);
        valideazaIndex(index, animale.size());

        Animal* a = animale[index];

        MedicVeterinar* medic = nullptr;
        for (size_t i = 0; i < persoane.size(); i++) {
            medic = dynamic_cast<MedicVeterinar*>(persoane[i]);
            if (medic)
                break;
        }

        if (!medic)
            throw UserInputError("Nu exista medic!");

        Consultatie c(a, medic);
        c.efectueazaConsultatie(stoc);
    }
    catch (const UserInputError& e) {
        std::cout << e.what() << "\n";
    }
}
