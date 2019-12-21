#ifndef ENDERECO_H
#define ENDERECO_H

#include <iostream>

class Endereco{
private:
    std::string logradouro;
    int numero;
    std::string bairro;
    std::string cidade;
    std::string CEP;
public:
    Endereco(){}
    Endereco(std::string logradouro, int numero, std::string bairro, std::string cidade, std::string CEP);
    std::string getLogradouro();
    int getNumero();
    std::string getBairro();
    std::string getCidade();
    std::string getCEP();

};

#endif