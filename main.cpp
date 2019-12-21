#include <iostream>
#include <iomanip>
#include "Apartamento.h"

using namespace std;

int main()
{
    Endereco end("Rua dos tolos", 0, "Bairro 778", "KDMNNT", "778");
    Apartamento *ap = new Apartamento("Apzinho", 1, 250000, end, "nascente norte", 
    2, 600, 1,200);

    cout<<ap->toString();


    return 0;
}