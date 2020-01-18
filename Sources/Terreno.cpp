#include "../Headers/Terreno.h"
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
    saida << "\tArea: " << getArea() << "\n";

    return saida.str();

}


void Terreno::setArea(double area)
{
    this->area = area;
} 