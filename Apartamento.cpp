#include "Apartamento.h"


Apartamento::Apartamento(std::string descricao, int tipoOferta, int valor, tEndereco endereco,std::string posicao, 
int numeroDeQuartos, double valorDoCondominio, int vagasDeGaragem,double area) : Imovel(descricao, tipoOferta, valor, endereco)
{
    this->posicao = posicao;
    this->numeroDeQuartos = numeroDeQuartos;
    this->valorDoCondominio = valorDoCondominio;
    this->vagasDeGaragem = vagasDeGaragem;
    this->area = area;
}
std::string Apartamento::getPosicao()
{
    return this->posicao;
}
int Apartamento::getNumeroDeQuartos()
{
    return this->numeroDeQuartos;
}
double Apartamento::getValorDoCondominio()
{   
    return this->valor;
}   
int Apartamento::getVagasDeGaragem()
{
    return this->vagasDeGaragem;
}
double Apartamento::getArea()
{
    return this->area;
}
