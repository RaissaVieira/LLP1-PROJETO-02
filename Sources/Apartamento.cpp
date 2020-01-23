#include "../Headers/Apartamento.h"
#include <iomanip>
#include <sstream>


Apartamento::Apartamento(std::string descricao, int tipoOferta, double valor, Endereco endereco,std::string posicao, 
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
    return this->valorDoCondominio;
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
    saida << "\tPosicao: " << getPosicao() << "\n";
    saida << "\tNumero de quartos: " << getNumeroDeQuartos() << "\n";
    saida << "\tValor do condominio: " << getValorDoCondominio() << "\n";
    saida << "\tNumero de vagas de garagem: " << getVagasDeGaragem() << "\n";
    saida << "\tArea: " << getArea() << "\n";

    return saida.str();
}

void Apartamento::setPosicao(std::string posicao)
{
    this->posicao = posicao;
}
void Apartamento::setNumeroDeQuartos(int numeroDeQuartos)
{
    this->numeroDeQuartos = numeroDeQuartos;
}
void Apartamento::setValorDoCondominio(double valorDoCondominio)
{
    this->valorDoCondominio = valorDoCondominio;
}
void Apartamento::setVagasDeGaragem(int vagasDeGaragem)
{
    this->vagasDeGaragem = vagasDeGaragem;
}
void Apartamento::setArea(double area)
{
    this->area = area;
}
