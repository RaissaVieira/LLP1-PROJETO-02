#include "Terreno.h"
#include <sstream>
#include <iomanip>
Terreno::Terreno(std::string descricao, int tipoOferta, int valor, Endereco endereco, 
double area) : Imovel(descricao,tipoOferta,valor,endereco)
{  
    this->area = area;
}
double Terreno::getArea(){
    return this->area;
}
std::string Terreno::toString(){
     std::stringstream string;
     string << std::setprecision(2) << std::fixed;
     string << "\tDescricao: " + getDescricao() << "\n";
     string << "\tTipo de oferta: ";
     if(getTipoOferta() == 1)
        string << "venda\n";
     else
        string << "aluguel\n"; 
    string << "\tPreco: " << getValor() << "\n";
    string << "\tEndereco:\n";
    string << "\t\tCidade: " + this->endereco.getCidade() << "\n";
    string << "\t\tBairro: " << this->endereco.getBairro() << "\n";
    string << "\t\tCEP: " << this->endereco.getCEP() << "\n";
    string << "\t\tLogradouro: " << this->endereco.getLogradouro() << "\n";
    string << "\t\tNumero: " << this->endereco.getNumero() << "\n";
    string << "\tArea: " << getArea() << "\n";

    return string.str();

}