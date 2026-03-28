#pragma once
#include<string>
#include<iostream>
//forward declaartion,pentru ca am pointer de la animal la client 
class Client;
class Animal {
protected:
	int id;
	std::string nume;
	unsigned varsta;
	Client* proprietar;
	static int nrAnimale;
public:
	Animal(int i, std::string n, unsigned v, Client* p);
	virtual ~Animal();
	virtual void Afiseaza();
	virtual double CalculeazaCost() = 0;
	int  getId() const;
	static int getNrAnimale();
};