#include "Terreno.h"
#include <iomanip>
#include <sstream>
Terreno::Terreno(std::string descricao, int tipoOferta, int valor, Endereco endereco, double area){   this->descricao = descricao;
    this->tipoOferta = tipoOferta;
    this->valor = valor;
    this->endereco = endereco;
    this->area = area;
}
double Terreno::getArea(){
    return this->area;
}
std::string Terreno::toString(){

}