#include <iostream>
#include <iomanip>
#include "LRY_IMO.h"
#include "Apartamento.h"

using namespace std;

int main()
{
    //Fazendo alguns testes
    LRY_IMO imobiliaria;

    imobiliaria.cadastrarApartamento();
    imobiliaria.cadastrarTerreno();
    imobiliaria.cadastrarCasa();

    imobiliaria.toString();
    imobiliaria.getImoveis(); //Lista todos os terrenos, casas e apartamentos
    
    return 0;
}