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

    cout<<imobiliaria.toString();
    
    return 0;
}