#include <iostream>
#include <iomanip>
#include "LRY_IMO.h"
#include <sstream>


using namespace std;

int main()
{
    setlocale(LC_ALL,"portuguese");
    //Fazendo alguns testes
    LRY_IMO imobiliaria;

    imobiliaria.cadastrarApartamento();
    imobiliaria.cadastrarTerreno();
    imobiliaria.cadastrarCasa();

    imobiliaria.getImoveis(); //Lista todos os terrenos, casas e apartamentos
    
    return 0;
}