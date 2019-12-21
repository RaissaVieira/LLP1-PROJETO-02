#ifndef IMOVEL_H
#define IMOVEL_H

#include "Endereco.h"


class Imovel{
protected:
    std::string descricao;
    double valor;
    int tipoOferta; //Façamos o número 1 como venda e o número 2 como aluguel.
    tEndereco endereco;
public:
    Imovel(std::string descricao, int tipoOferta, int valor, tEndereco endereco);
    std::string getDescricao();
    int getTipoOferta();
    tEndereco getEndereco();
    double getValor();

};

#endif