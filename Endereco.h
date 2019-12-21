#ifndef ENDERECO_H
#define ENDERECO_H

#include <iostream>


typedef struct{//Talvez seja melhor transformá-lo em uma classe...
    std::string logradouro;
    int numero;
    std::string bairro;
    std::string cidade;
    std::string CEP;

}tEndereco;


#endif