#ifndef IMOVEL_H
#define IMOVEL_H

#include "../Headers/Endereco.h"


class Imovel{
protected:
    int tipo; // 1 -> apartamento, 2 -> casa, 3 -> terreno
    std::string descricao;
    double valor;
    int tipoOferta; //Façamos o número 1 como venda e o número 2 como aluguel.
    Endereco endereco;
public:
    Imovel(std::string descricao, int tipoOferta, int valor, Endereco endereco);
    std::string getDescricao();
    int getTipoOferta();
    Endereco getEndereco();
    double getValor();
    int getTipo();

    void setTipo(int tipo);

};

#endif