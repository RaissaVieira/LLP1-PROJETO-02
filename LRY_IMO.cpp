#include "LRY_IMO.h"
#include <iostream>

#define TIPO_APARTAMENTO 1
#define TIPO_CASA 2
#define TIPO_TERRENO 3

void LRY_IMO::cadastrarApartamento()
{
    Apartamento *ap;
    Endereco *end;
    std::string descricao, cidade, bairro, CEP, logradouro, posicao;
    int tipoOferta, numero, vagasDeGaragem, numeroDeQuartos;
    double valor, valorDoCondominio, area;

    std::cout<<"Descricao: ";
    getline(std::cin,descricao);
    std::cout<<"Tipo de oferta: ";
    std::cin>>tipoOferta;
    std::cout<<"Valor: ";
    std::cin>>valor;
    std::cout<<"Cidade: ";
    std::cin.ignore();
    getline(std::cin,cidade);
    std::cout<<"Bairro: ";
    getline(std::cin,bairro);
    std::cout<<"CEP: ";
    getline(std::cin,CEP);
    std::cout<<"Logradouro: ";
    getline(std::cin,logradouro);
    std::cout<<"Numero: ";
    std::cin>>numero;
    std::cout<<"Posicao: ";
    std::cin.ignore();
    getline(std::cin,posicao);
    std::cout<<"Numero de quartos: ";
    std::cin>>numeroDeQuartos;
    std::cout<<"Valor do condominio: ";
    std::cin>>valorDoCondominio;
    std::cout<<"Numero de vagas de garagem: ";
    std::cin>>vagasDeGaragem;
    std::cout<<"Area: ";
    std::cin>>area;
    std::cin.ignore();

    end = new Endereco(logradouro, numero, bairro, cidade, CEP);

    ap = new Apartamento(descricao,tipoOferta,valor, *end,posicao, numeroDeQuartos, valorDoCondominio, vagasDeGaragem, area);
    ap->setTipo(1);

    this->imoveis.push_back(ap);

    std::cout<<"Apartamento cadastrado com sucesso!\n";

}

void LRY_IMO::cadastrarTerreno ()
{
    Terreno *ter;
    Endereco *end;
    std::string descricao, cidade, bairro, CEP, logradouro;
    int tipoOferta, numero;
    double valor, area;

    std::cout<<"Descricao: ";
    getline(std::cin,descricao);
    std::cout<<"Tipo de oferta: ";
    std::cin>>tipoOferta;
    std::cout<<"Valor: ";
    std::cin>>valor;
    std::cout<<"Cidade: ";
    std::cin.ignore();
    getline(std::cin,cidade);
    std::cout<<"Bairro: ";
    getline(std::cin,bairro);
    std::cout<<"CEP: ";
    getline(std::cin,CEP);
    std::cout<<"Logradouro: ";
    getline(std::cin,logradouro);
    std::cout<<"Numero: ";
    std::cin>>numero;
    std::cout<<"Area: ";
    std::cin>>area;
    std::cin.ignore();

    end = new Endereco(logradouro, numero, bairro, cidade, CEP);
    ter = new Terreno (descricao,tipoOferta,valor, *end, area);
    ter->setTipo(1);
    this->imoveis.push_back(ter);

    std::cout<<"Terreno cadastrado com sucesso!\n";

}

std::string LRY_IMO::toString()
{
    std::vector<Imovel *>::iterator it;
    std::string saida;


    std::cout << "\t=========APARTAMENTOS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo apartamentos.
    {
        if((*it)->getTipo() == TIPO_APARTAMENTO)
        {
            saida += ((Apartamento *)*it)->toString();
        }
    }

    /*
        Implemente aqui o toString para os terrenos e casas
    */
   
    std::cout << "\t=========Terrenos=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo apartamentos.
    {
        if((*it)->getTipo() == TIPO_TERRENO)
        {
            saida += ((Terreno *)*it)->toString();
        }
    }

    return saida;
}
