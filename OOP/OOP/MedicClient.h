#pragma once
#include "Client.h"
#include "MedicVeterinar.h"

class MedicClient : public Client, public MedicVeterinar {
public:
    MedicClient(int id, const std::string& n, std::string t, std::string adr, double s, std::string spec);
    ~MedicClient();

    void afiseaza() const;
};

