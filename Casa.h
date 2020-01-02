#ifndef CASA_H
#define CASA_H

#include "Imovel.h"

using namespace std;

class Casa : public Imovel
{
private:
    int numeroDePavimentos;
    int numeroDeQuartos;
    double areaDoTerreno;
    double areaConstruida;

public:
    Casa(string descricao, int tipoOferta, int valor, Endereco endereco,
         int numeroDePavimentos, int numeroDeQuartos, double areaDoTerreno, double areaConstruida);

    int getNumeroDePavimentos();
    int getNumeroDeQuartos();
    double getAreaDoTerreno();
    double getAreaConstruida();
    string toString();
};


#endif