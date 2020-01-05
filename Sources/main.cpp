#include <iostream>
#include <iomanip>
#include "../Headers/LRY_IMO.h"
#include <sstream>
#include <fstream>

using namespace std;


int main()
{ 

    setlocale(LC_ALL,"portuguese");
    //Fazendo alguns testes
    LRY_IMO imobiliaria;

    imobiliaria.lerCasasSalvas();
    imobiliaria.lerApartamentosSalvos();
    imobiliaria.lerTerrenosSalvos();

    imobiliaria.getImoveis();

    //imobiliaria.getImoveis(); //Lista todos os terrenos, casas e apartamentos
    
    return 0;
}