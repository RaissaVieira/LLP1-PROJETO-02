#ifndef LRY_IMO_H
#define LRY_IMO_H

#include "Apartamento.h"
#include <vector>

class LRY_IMO{ //CRUD imobiliária
private:
    std::vector<Apartamento>apartamentos;
public:
    void cadastrarApartamento();
    std::string toString();

};

#endif