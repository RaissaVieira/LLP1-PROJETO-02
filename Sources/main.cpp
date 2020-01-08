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


    cout << imobiliaria.toString();
    

    
    return 0;
}