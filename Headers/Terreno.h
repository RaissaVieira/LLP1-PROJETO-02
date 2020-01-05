#pragma once
#include "../Headers/Imovel.h"

class Terreno : public Imovel
{
private:
    double area;
public:
    Terreno(std::string descricao, int tipoOferta, int valor, Endereco endereco, double area);
    double getArea();
    std::string toString();
};



