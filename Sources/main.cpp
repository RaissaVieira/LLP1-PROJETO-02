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


<<<<<<< HEAD
    //imobiliaria.cadastrarCasa();

    //imobiliaria.salvarCasas();
    //imobiliaria.buscarPorBairro();
    //imobiliaria.buscarPorCidade();
    //imobiliaria.buscarPorValor();
    imobiliaria.removerImovel(2);
=======
    cout << imobiliaria.toString();
    

>>>>>>> 5f3823f5ed53c21004bcccf1726574155a2238f6
    
    return 0;
}