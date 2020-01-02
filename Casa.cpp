#include "Casa.h"
#include <iomanip>
#include <sstream>

Casa::Casa(string descricao, int tipoOferta, int valor, Endereco endereco,
           int numeroDePavimentos, int numeroDeQuartos, double areaDoTerreno, double areaConstruida) : Imovel(descricao, tipoOferta, valor, endereco){
    
    this->numeroDePavimentos = numeroDePavimentos;
    this->numeroDeQuartos = numeroDeQuartos;
    this->areaDoTerreno = areaDoTerreno;
    this->areaConstruida = areaConstruida;

}

int Casa::getNumeroDePavimentos(){
    return numeroDePavimentos;
}
int Casa::getNumeroDeQuartos(){
    return numeroDeQuartos;
}
double Casa::getAreaDoTerreno(){
    return areaDoTerreno;
}
double Casa::getAreaConstruida(){
    return areaConstruida;
}
std::string Casa::toString(){
    std::stringstream saida;
    saida << std::setprecision(2) << std::fixed;

    saida << "\tDescricao: " + getDescricao() << "\n";
    saida << "\tTipo de oferta: ";
    if(getTipoOferta() == 1)
        saida << "venda\n";
    else
        saida << "aluguel\n"; 
    saida << "\tPreco: " << getValor() << "\n";
    saida << "\tEndereco:\n";
    saida << "\t\tCidade: " + this->endereco.getCidade() << "\n";
    saida << "\t\tBairro: " << this->endereco.getBairro() << "\n";
    saida << "\t\tCEP: " << this->endereco.getCEP() << "\n";
    saida << "\t\tLogradouro: " << this->endereco.getLogradouro() << "\n";
    saida << "\t\tNumero: " << this->endereco.getNumero() << "\n";
    saida << "\tNumero de pavimentos: " << getNumeroDePavimentos() << "\n";
    saida << "\tNumero de quartos: " << getNumeroDeQuartos() << "\n";
    saida << "\tArea do terreno: " << getAreaDoTerreno() << "\n";
    saida << "\tArea constuida: " << getAreaConstruida() << "\n";

    return saida.str();
}