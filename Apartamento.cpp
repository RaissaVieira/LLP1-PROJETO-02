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


std::string Apartamento::toString()
{
    std::string saida = "";
    saida +="\tDescricao: " + getDescricao() + "\n";
    saida += "\tTipo de oferta: ";
    if(getTipoOferta() == 1)
        saida += "venda\n";
    else
        saida += "aluguel\n"; 
    saida += "\tPreco: "+ std::to_string(getValor()) + "\n";
    saida +="\tEndereco:\n";
    saida +="\t\tCidade: " + this->endereco.cidade + "\n";
    saida +="\t\tBairro: " + this->endereco.bairro + "\n";
    saida +="\t\tCEP: " + this->endereco.CEP + "\n";
    saida +="\t\tLogradouro: "+ this->endereco.logradouro + "\n";
    saida +="\t\tNumero: " + std::to_string(this->endereco.numero) + "\n";
    saida += "\tPosicao: " + getPosicao() + "\n";
    saida +="\tNumero de quartos: " + std::to_string(getNumeroDeQuartos()) + "\n";
    saida +="\tValor do condominio: " + std::to_string(getValorDoCondominio()) + "\n";
    saida +="\tNumero de vagas de garagem: " + std::to_string(getVagasDeGaragem()) + "\n";
    saida +="\tArea: " + std::to_string(getArea()) + "\n";

    return saida;
}
