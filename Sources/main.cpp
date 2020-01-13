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

    imobiliaria.lerImoveisSalvos();

    //imobiliaria.buscarPorDescricao();
    
    imobiliaria.removerImovel(1);
    std::cout<<imobiliaria.getApartamentos();

    
    return 0;
}