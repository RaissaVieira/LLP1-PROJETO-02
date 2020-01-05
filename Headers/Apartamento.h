#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "../Headers/Imovel.h"

class Apartamento : public Imovel{
private:
    std::string posicao;
    int numeroDeQuartos;
    double valorDoCondominio;
    int vagasDeGaragem;
    double area;
public:
    Apartamento(std::string descricao, int tipoOferta, int valor, Endereco endereco,std::string posicao, 
    int numeroDeQuartos, double valorDoCondominio, int vagasDeGaragem,double area);
    std::string getPosicao();
    int getNumeroDeQuartos();
    double getValorDoCondominio();
    int getVagasDeGaragem();
    double getArea();
    std::string toString();

}; 


#endif