#include "Endereco.h"

Endereco::Endereco(std::string logradouro, int numero, std::string bairro, std::string cidade, std::string CEP)
{
    this->logradouro = logradouro;
    this->numero = numero;
    this->bairro = bairro;
    this->cidade = cidade;
    this->CEP = CEP;
}

std::string Endereco::getLogradouro()
{
    return this->logradouro;
}
int Endereco::getNumero()
{
    return this->numero;
}
std::string Endereco::getBairro()
{
    return this->bairro;
}
std::string Endereco::getCidade()
{
    return this->cidade;
}
std::string Endereco::getCEP()
{
    return this->CEP;
}