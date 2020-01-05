#include "LRY_IMO.h"
#include <iostream>

#define TIPO_APARTAMENTO 1
#define TIPO_CASA 2
#define TIPO_TERRENO 3

using namespace std;

void LRY_IMO::cadastrarApartamento(){
    Apartamento *ap;
    Endereco *end;
    string descricao, cidade, bairro, CEP, logradouro, posicao;
    int tipoOferta, numero, vagasDeGaragem, numeroDeQuartos;
    double valor, valorDoCondominio, area;

    cout<<"Descrição: ";
    getline(cin,descricao);
    cout<<"Tipo de oferta: ";
    cin>>tipoOferta;
    cout<<"Valor: ";
    cin>>valor;
    cout<<"Cidade: ";
    cin.ignore();
    getline(cin,cidade);
    cout<<"Bairro: ";
    getline(cin,bairro);
    cout<<"CEP: ";
    getline(cin,CEP);
    cout<<"Logradouro: ";
    getline(cin,logradouro);
    cout<<"Número: ";
    cin>>numero;
    cout<<"Posição: ";
    cin.ignore();
    getline(cin,posicao);
    cout<<"Número de quartos: ";
    cin>>numeroDeQuartos;
    cout<<"Valor do condominio: ";
    cin>>valorDoCondominio;
    cout<<"Número de vagas de garagem: ";
    cin>>vagasDeGaragem;
    cout<<"Área: ";
    cin>>area;
    cin.ignore();

    end = new Endereco(logradouro, numero, bairro, cidade, CEP);

    ap = new Apartamento(descricao,tipoOferta,valor, *end, posicao, numeroDeQuartos, valorDoCondominio, vagasDeGaragem, area);
    ap->setTipo(1);

    this->imoveis.push_back(ap);

    cout<<"Apartamento cadastrado com sucesso!\n";

}

void LRY_IMO::cadastrarTerreno (){
    Terreno *ter;
    Endereco *end;
    string descricao, cidade, bairro, CEP, logradouro;
    int tipoOferta, numero;
    double valor, area;

    cout<<"Descrição: ";
    getline(std::cin,descricao);
    cout<<"Tipo de oferta: ";
    cin>>tipoOferta;
    cout<<"Valor: ";
    cin>>valor;
    cout<<"Cidade: ";
    cin.ignore();
    getline(cin,cidade);
    cout<<"Bairro: ";
    getline(cin,bairro);
    cout<<"CEP: ";
    getline(cin,CEP);
    cout<<"Logradouro: ";
    getline(cin,logradouro);
    cout<<"Número: ";
    cin>>numero;
    cout<<"Área: ";
    cin>>area;
    cin.ignore();

    end = new Endereco(logradouro, numero, bairro, cidade, CEP);
    ter = new Terreno (descricao,tipoOferta,valor, *end, area);
    ter->setTipo(3);
    this->imoveis.push_back(ter);

    cout<<"Terreno cadastrado com sucesso!\n";

}

void LRY_IMO::cadastrarCasa(){
    Casa *casa;
    Endereco *end;
    string descricao, cidade, bairro, CEP, logradouro;
    int tipoOferta, numero, numeroDePavimentos, numeroDeQuartos;
    double valor, areaDoTerreno, areaConstruida;

    cout<<"Descrição: ";
    getline(cin,descricao);
    cout<<"Tipo de oferta: ";
    cin>>tipoOferta;
    cout<<"Valor: ";
    cin>>valor;
    cout<<"Cidade: ";
    cin.ignore();
    getline(cin,cidade);
    cout<<"Bairro: ";
    getline(cin,bairro);
    cout<<"CEP: ";
    getline(cin,CEP);
    cout<<"Logradouro: ";
    getline(cin,logradouro);
    cout<<"Número: ";
    cin>>numero;
    cout<<"Número de pavimentos ";
    cin>>numeroDePavimentos;
    cout<<"Número de quartos: ";
    cin>>numeroDeQuartos;
    cout<<"Área do terreno: ";
    cin>>areaDoTerreno;
    cout<<"Área construida: ";
    cin>>areaConstruida;
    cin.ignore();

    end = new Endereco(logradouro, numero, bairro, cidade, CEP);

    casa = new Casa(descricao,tipoOferta,valor, *end, numeroDePavimentos, numeroDeQuartos, areaDoTerreno, areaConstruida);
    casa->setTipo(2);

    this->imoveis.push_back(casa);

    cout<<"Casa cadastrada com sucesso!\n";

}

void LRY_IMO::listarCasa(){
    
    vector<Imovel *>::iterator it;
    string saida;
    int i=1;
    cout << "\t=========CASAS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if((*it)->getTipo() == TIPO_CASA)
        {         
            cout << "\t=========Casa "<<i<<"=========\n";
            cout << "Descrição: " << ((Casa *)*it)->getDescricao() << "\n";
            cout << "CEP: " << ((Casa *)*it)->getEndereco().getCEP() << "\n";
            cout << "Cidade: " << ((Casa *)*it)->getEndereco().getCidade() << "\n";
            cout << "Bairro: " << ((Casa *)*it)->getEndereco().getBairro() << "\n";
            cout << "Logradouro: " << ((Casa *)*it)->getEndereco().getLogradouro() << "\n";
            cout << "Número: " << ((Casa *)*it)->getEndereco().getNumero() << "\n";
            cout << "Valor: " << ((Casa *)*it)->getValor() << "\n";
            cout << "Tipo de Oferta: " << ((Casa *)*it)->getTipoOferta() << "\n";
            cout << "Área Construída: " << ((Casa *)*it)->getAreaConstruida() << "\n";
            cout << "Área do Terreno: " << ((Casa *)*it)->getAreaDoTerreno() << "\n";
            cout << "Número de Pavimentos: " << ((Casa *)*it)->getNumeroDePavimentos() << "\n";
            cout << "Número de Quartos: " << ((Casa *)*it)->getNumeroDeQuartos() << "\n";
            i++;
        }
    }
}
void LRY_IMO::listarApartamento(){
    
    vector<Imovel *>::iterator it;
    int i=1;
    string saida;
    cout << "\t=========Apartamentos=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if((*it)->getTipo() == TIPO_APARTAMENTO)
        {         
            cout << "\t=========Apartamento "<<i<<"=========\n";
            cout << "Descrição: " << ((Apartamento *)*it)->getDescricao() << "\n";
            cout << "CEP: " << ((Apartamento *)*it)->getEndereco().getCEP() << "\n";
            cout << "Cidade: " << ((Apartamento *)*it)->getEndereco().getCidade() << "\n";
            cout << "Bairro: " << ((Apartamento *)*it)->getEndereco().getBairro() << "\n";
            cout << "Logradouro: " << ((Apartamento *)*it)->getEndereco().getLogradouro() << "\n";
            cout << "Número: " << ((Apartamento *)*it)->getEndereco().getNumero() << "\n";
            cout << "Valor: " << ((Apartamento *)*it)->getValor() << "\n";
            cout << "Tipo de Oferta: " << ((Apartamento *)*it)->getTipoOferta() << "\n";
            cout << "Área: " << ((Apartamento *)*it)->getArea() << "\n";
            cout << "Valor do Condominio: " << ((Apartamento *)*it)->getValorDoCondominio() << "\n";
            cout << "Vagas de Garagem: " << ((Apartamento *)*it)->getVagasDeGaragem() << "\n";
            cout << "Número de Quartos: " << ((Apartamento *)*it)->getNumeroDeQuartos() << "\n";
            cout << "Posição: " << ((Apartamento *)*it)->getPosicao()<< "\n";
            i++;
        }
    }
}
void LRY_IMO::listarTerreno(){
    
    vector<Imovel *>::iterator it;
    int i=1;
    string saida;
    cout << "\t=========Terrenos=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if((*it)->getTipo() == TIPO_TERRENO)
        {         
            cout << "\t=========Terreno "<<i<<"=========\n";
            cout << "Descrição: " << ((Terreno *)*it)->getDescricao() << "\n";
            cout << "CEP: " << ((Terreno *)*it)->getEndereco().getCEP() << "\n";
            cout << "Cidade: " << ((Terreno *)*it)->getEndereco().getCidade() << "\n";
            cout << "Bairro: " << ((Terreno *)*it)->getEndereco().getBairro() << "\n";
            cout << "Logradouro: " << ((Terreno *)*it)->getEndereco().getLogradouro() << "\n";
            cout << "Número: " << ((Terreno *)*it)->getEndereco().getNumero() << "\n";
            cout << "Valor: " << ((Terreno *)*it)->getValor() << "\n";
            cout << "Tipo de Oferta: " << ((Terreno *)*it)->getTipoOferta() << "\n";
            cout << "Área : " << ((Terreno *)*it)->getArea() << "\n";
            i++;
        }
    }
}
void LRY_IMO::getImoveis(){
    listarCasa();
    listarTerreno();
    listarApartamento();
}

/*
    GALERA, OS MÉTODOS TOSTRING E GETIMOVEIS NÃO FAZEM A MESMA COISA NÃO?
    PS.: Quando eu testo o toString não funciona...
    Aí eu pensei em complementar o GetImoveis com mais informações, deixei toString comentado.
*/

/*std::string LRY_IMO::toString(){
    std::vector<Imovel *>::iterator it;
    std::string saida;


    std::cout << "\t=========APARTAMENTOS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo apartamentos.
    {
        if((*it)->getTipo() == TIPO_APARTAMENTO)
        {
            std::cout << "entrei";
            saida += ((Apartamento *)*it)->toString();
        }
    }
   
    std::cout << "\t=========TERRENOS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Terrenos.
    {
        if((*it)->getTipo() == TIPO_TERRENO)
        {
            saida += ((Terreno *)*it)->toString();
        }
    }

    std::cout << "\t=========CASAS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if((*it)->getTipo() == TIPO_CASA)
        {
            saida += ((Casa *)*it)->toString();
        }
    }

    return saida;
}

void LRY_IMO::getImoveis(){
    //Lista todos os terrenos, casas e apartamentos
    std::vector<Imovel *>::iterator it;
    std::string saida;


    std::cout << "\t=========APARTAMENTOS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo apartamentos.
    {
        if((*it)->getTipo() == TIPO_APARTAMENTO)
        {

            std::cout << "Descricao: " << ((Apartamento *)*it)->getDescricao() << "\n";
            std::cout << "Cidade: " << ((Apartamento *)*it)->getEndereco().getCidade() << "\n";
            std::cout << "Bairro: " << ((Apartamento *)*it)->getEndereco().getBairro() << "\n";
            std::cout << "Valor: " << ((Apartamento *)*it)->getValor() << "\n";
        }
    }
   
    std::cout << "\t=========TERRENOS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Terrenos.
    {
        if((*it)->getTipo() == TIPO_TERRENO)
        {

            std::cout << "Descricao: " << ((Terreno *)*it)->getDescricao() << "\n";;
            std::cout << "Cidade: " << ((Terreno *)*it)->getEndereco().getCidade() << "\n";
            std::cout << "Bairro: " << ((Terreno *)*it)->getEndereco().getBairro() << "\n";
            std::cout << "Valor: " << ((Terreno *)*it)->getValor() << "\n";
        }
    }

    std::cout << "\t=========CASAS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if((*it)->getTipo() == TIPO_CASA)
        {         

            std::cout << "Descricao: " << ((Casa *)*it)->getDescricao() << "\n";
            std::cout << "Cidade: " << ((Casa *)*it)->getEndereco().getCidade() << "\n";
            std::cout << "Bairro: " << ((Casa *)*it)->getEndereco().getBairro() << "\n";
            std::cout << "Valor: " << ((Casa *)*it)->getValor() << "\n";
        }
    }
}
*/

