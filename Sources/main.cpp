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

    //imobiliaria.cadastrarCasa();

    //imobiliaria.salvarCasas();
    //imobiliaria.buscarPorBairro();
    //imobiliaria.buscarPorCidade();
    imobiliaria.buscarPorValor();

    
    return 0;
}