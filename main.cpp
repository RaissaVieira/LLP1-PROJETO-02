#include <iostream>
#include "Apartamento.h"

using namespace std;

int main()
{
    tEndereco end;
    end.bairro = "Bairro 778";
    end.CEP = "778";
    end.cidade = "KDMNNT";
    end.logradouro = "Rua dos tolos";
    end.numero = 0;
    Apartamento *ap = new Apartamento("Apzinho", 1, 250000, end, "nascente norte", 
    2, 600, 1,200);


    cout<<ap->toString();


    return 0;
}