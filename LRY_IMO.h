#ifndef LRY_IMO_H
#define LRY_IMO_H

#include "Apartamento.h"
#include "Terreno.h"
#include <vector>

class LRY_IMO{ //CRUD imobiliária
private:
    std::vector<Imovel *>imoveis;
public:
    void cadastrarApartamento();
    void cadastrarTerreno();
    std::string toString();

};

#endif