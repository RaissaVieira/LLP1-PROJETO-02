#include "Imovel.h"

Imovel::Imovel(std::string descricao, int tipoOferta, int valor, tEndereco endereco)
{
    this->descricao = descricao;
    this->tipoOferta = tipoOferta;
    this->valor = valor;
    this->endereco = endereco;
}
std::string Imovel::getDescricao()
{
    return this->descricao;
}
int Imovel::getTipoOferta()
{
    return this->tipoOferta;
}   
tEndereco Imovel::getEndereco()
{
    return this->endereco;
}
double Imovel::getValor()
{
    return this->valor;
}