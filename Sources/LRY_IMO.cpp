#include "../Headers/LRY_IMO.h"
#include <iostream>
#include <fstream>
#include<bits/stdc++.h> //Utilizar esta biblioteca é uma má prática de programação.

#define TIPO_APARTAMENTO 1
#define TIPO_CASA 2
#define TIPO_TERRENO 3

#define VENDA 1
#define ALUGUEL 2
#define VENDA_OU_ALUGUEL 3


using namespace std; //Não é uma boa prática utilizar "using namespace..." em arquivos que não sejam o main

void LRY_IMO::lerImoveisSalvos()
{
    ifstream arquivoImoveis("./Arquivos/Imoveis.txt");
    int tipoImovel; //Pode ser 1, 2 ou 3

    while(!arquivoImoveis.eof())
    {
        arquivoImoveis >> tipoImovel;
        arquivoImoveis.ignore();

        if(tipoImovel == TIPO_APARTAMENTO)
        {
            Apartamento *ap;
            Endereco *end;
            string descricao, cidade, bairro, CEP, logradouro, posicao;
            int tipoOferta, numero, vagasDeGaragem, numeroDeQuartos;
            double valor, valorDoCondominio, area;

            getline(arquivoImoveis,descricao);
            arquivoImoveis>>tipoOferta;
            arquivoImoveis>>valor;
            arquivoImoveis.ignore();
            getline(arquivoImoveis,cidade);
            getline(arquivoImoveis,bairro);
            getline(arquivoImoveis,CEP);
            getline(arquivoImoveis,logradouro);
            arquivoImoveis>>numero;
            arquivoImoveis.ignore();
            getline(arquivoImoveis,posicao);
            arquivoImoveis>>numeroDeQuartos;
            arquivoImoveis>>valorDoCondominio;
            arquivoImoveis>>vagasDeGaragem;
            arquivoImoveis>>area;
            arquivoImoveis.ignore();

            end = new Endereco(logradouro, numero, bairro, cidade, CEP);

            ap = new Apartamento(descricao,tipoOferta,valor, *end, posicao, numeroDeQuartos, valorDoCondominio, vagasDeGaragem, area);
            ap->setTipo(1);

            this->imoveis.push_back(ap);
        }else if(tipoImovel == TIPO_CASA)
        {
            Casa *casa;
            Endereco *end;
            string descricao, cidade, bairro, CEP, logradouro;
            int tipoOferta, numero, numeroDePavimentos, numeroDeQuartos;
            double valor, areaDoTerreno, areaConstruida;

            getline(arquivoImoveis,descricao);
            arquivoImoveis>>tipoOferta;
            arquivoImoveis>>valor;
            arquivoImoveis.ignore();
            getline(arquivoImoveis,cidade);
            getline(arquivoImoveis,bairro);
            getline(arquivoImoveis,CEP);
            getline(arquivoImoveis,logradouro);
            arquivoImoveis>>numero;
            arquivoImoveis>>numeroDePavimentos;
            arquivoImoveis>>numeroDeQuartos;
            arquivoImoveis>>areaDoTerreno;
            arquivoImoveis>>areaConstruida;
            arquivoImoveis.ignore();

            end = new Endereco(logradouro, numero, bairro, cidade, CEP);

            casa = new Casa(descricao,tipoOferta,valor, *end, numeroDePavimentos, numeroDeQuartos, areaDoTerreno, areaConstruida);
            casa->setTipo(2);
            this->imoveis.push_back(casa);
        }else if(tipoImovel == TIPO_TERRENO)
        {
            Terreno *ter;
            Endereco *end;
            string descricao, cidade, bairro, CEP, logradouro;
            int tipoOferta, numero;
            double valor, area;

            getline(arquivoImoveis,descricao);
            arquivoImoveis>>tipoOferta;
            arquivoImoveis>>valor;
            arquivoImoveis.ignore();
            getline(arquivoImoveis,cidade);
            getline(arquivoImoveis,bairro);
            getline(arquivoImoveis,CEP);
            getline(arquivoImoveis,logradouro);
            arquivoImoveis>>numero;
            arquivoImoveis>>area;
            arquivoImoveis.ignore();

            end = new Endereco(logradouro, numero, bairro, cidade, CEP);
            ter = new Terreno (descricao,tipoOferta,valor, *end, area);
            ter->setTipo(3);
            this->imoveis.push_back(ter);
        }

    }

    arquivoImoveis.close();
}

void LRY_IMO::salvarImoveis()
{
    ofstream arquivoImoveis("./Arquivos/Imoveis.txt");

    vector<Imovel *>::iterator it;
    int contaImoveis = 0;
    
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if(contaImoveis > 0)
        {
            arquivoImoveis << "\n";
        }

        arquivoImoveis << (*it)->getTipo() << "\n";
        if((*it)->getTipo() == TIPO_APARTAMENTO)
        {        
            arquivoImoveis << ((Apartamento *)*it)->getDescricao() << "\n";
            arquivoImoveis << ((Apartamento *)*it)->getTipoOferta() << "\n";
            arquivoImoveis << ((Apartamento *)*it)->getValor() << "\n";
            arquivoImoveis << ((Apartamento *)*it)->getEndereco().getCidade() << "\n";
            arquivoImoveis << ((Apartamento *)*it)->getEndereco().getBairro() << "\n";
            arquivoImoveis << ((Apartamento *)*it)->getEndereco().getCEP() << "\n";
            arquivoImoveis << ((Apartamento *)*it)->getEndereco().getLogradouro() << "\n";
            arquivoImoveis << ((Apartamento *)*it)->getEndereco().getNumero() << "\n";
            arquivoImoveis << ((Apartamento *)*it)->getPosicao()<< "\n";
            arquivoImoveis << ((Apartamento *)*it)->getNumeroDeQuartos() << "\n";
            arquivoImoveis << ((Apartamento *)*it)->getValorDoCondominio() << "\n";
            arquivoImoveis << ((Apartamento *)*it)->getVagasDeGaragem() << "\n";
            arquivoImoveis << ((Apartamento *)*it)->getArea();
        }else if((*it)->getTipo() == TIPO_CASA)
        {   
            arquivoImoveis << ((Casa *)*it)->getDescricao() << "\n";
            arquivoImoveis << ((Casa *)*it)->getTipoOferta() << "\n";
            arquivoImoveis << ((Casa *)*it)->getValor() << "\n";
            arquivoImoveis << ((Casa *)*it)->getEndereco().getCidade() << "\n";
            arquivoImoveis << ((Casa *)*it)->getEndereco().getBairro() << "\n";
            arquivoImoveis << ((Casa *)*it)->getEndereco().getCEP() << "\n";
            arquivoImoveis << ((Casa *)*it)->getEndereco().getLogradouro() << "\n";
            arquivoImoveis << ((Casa *)*it)->getEndereco().getNumero() << "\n";
            arquivoImoveis << ((Casa *)*it)->getNumeroDePavimentos() << "\n";
            arquivoImoveis << ((Casa *)*it)->getNumeroDeQuartos() << "\n";
            arquivoImoveis << ((Casa *)*it)->getAreaDoTerreno() << "\n";
            arquivoImoveis << ((Casa *)*it)->getAreaConstruida();
        }else if((*it)->getTipo() == TIPO_TERRENO)
        {        
            arquivoImoveis << ((Terreno *)*it)->getDescricao() << "\n";
            arquivoImoveis << ((Terreno *)*it)->getTipoOferta() << "\n";
            arquivoImoveis << ((Terreno *)*it)->getValor() << "\n";
            arquivoImoveis << ((Terreno *)*it)->getEndereco().getCidade() << "\n";
            arquivoImoveis << ((Terreno *)*it)->getEndereco().getBairro() << "\n";
            arquivoImoveis << ((Terreno *)*it)->getEndereco().getCEP() << "\n";
            arquivoImoveis << ((Terreno *)*it)->getEndereco().getLogradouro() << "\n";
            arquivoImoveis << ((Terreno *)*it)->getEndereco().getNumero() << "\n";
            arquivoImoveis << ((Terreno *)*it)->getArea();
        }
        contaImoveis++;
    }
    arquivoImoveis.close();
    std::cout<<"Arquivo salvo com sucesso.\n";
}

void LRY_IMO::cadastrarApartamento()
{
    Apartamento *ap;
    Endereco *end;
    string descricao, cidade, bairro, CEP, logradouro, posicao;
    int tipoOferta, numero, vagasDeGaragem, numeroDeQuartos;
    double valor, valorDoCondominio, area;

    cout<<"Descrição: ";
    getline(cin,descricao);
    cout<<"Tipo de oferta(aluguel-1/venda-2): ";
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

void LRY_IMO::cadastrarTerreno ()
{
    Terreno *ter;
    Endereco *end;
    string descricao, cidade, bairro, CEP, logradouro;
    int tipoOferta, numero;
    double valor, area;

    cout<<"Descrição: ";
    getline(std::cin,descricao);
    cout<<"Tipo de oferta(aluguel-1/venda-2): ";
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

void LRY_IMO::cadastrarCasa()
{
    Casa *casa;
    Endereco *end;
    string descricao, cidade, bairro, CEP, logradouro;
    int tipoOferta, numero, numeroDePavimentos, numeroDeQuartos;
    double valor, areaDoTerreno, areaConstruida;

    cout<<"Descrição: ";
    getline(cin,descricao);
    cout<<"Tipo de oferta(aluguel-1/venda-2): ";
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
    cout<<"Número de pavimentos: ";
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

string LRY_IMO::getCasas(int tipoOferta)
{
    
    vector<Imovel *>::iterator it;
    stringstream saida;
    int i=1;
    saida << "\t=========CASAS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if(((*it)->getTipo() == TIPO_CASA)  && (((*it)->getTipoOferta() == tipoOferta) || tipoOferta == VENDA_OU_ALUGUEL))
        {         
            saida << "\t=========Casa "<<i<<"=========\n";
            saida << "Descrição: " << ((Casa *)*it)->getDescricao() << "\n";
            saida << "Tipo de Oferta: " << ((Casa *)*it)->getTipoOferta() << "\n";
            saida << "Valor: " << ((Casa *)*it)->getValor() << "\n";
            saida << "Cidade: " << ((Casa *)*it)->getEndereco().getCidade() << "\n";
            saida << "Bairro: " << ((Casa *)*it)->getEndereco().getBairro() << "\n";
            saida << "CEP: " << ((Casa *)*it)->getEndereco().getCEP() << "\n";
            saida << "Logradouro: " << ((Casa *)*it)->getEndereco().getLogradouro() << "\n";
            saida << "Número: " << ((Casa *)*it)->getEndereco().getNumero() << "\n";
            saida << "Número de Pavimentos: " << ((Casa *)*it)->getNumeroDePavimentos() << "\n";
            saida << "Número de Quartos: " << ((Casa *)*it)->getNumeroDeQuartos() << "\n";
            saida << "Área do Terreno: " << ((Casa *)*it)->getAreaDoTerreno() << "\n";
            saida << "Área Construída: " << ((Casa *)*it)->getAreaConstruida() << "\n";
            i++;
        }
    }
    if(i == 1)
    {
        saida << "Nenhum resultado encontrado...\n";
    }

    return saida.str();
}
string LRY_IMO::getApartamentos(int tipoOferta)
{
    
    vector<Imovel *>::iterator it;
    int i=1;
    stringstream saida;
    saida << "\t=========Apartamentos=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if(((*it)->getTipo() == TIPO_APARTAMENTO) && (((*it)->getTipoOferta() == tipoOferta) || tipoOferta == VENDA_OU_ALUGUEL))
        {         
            saida << "\t=========Apartamento "<<i<<"=========\n";
            saida << "Descrição: " << ((Apartamento *)*it)->getDescricao() << "\n";
            saida << "Tipo de Oferta: " << ((Apartamento *)*it)->getTipoOferta() << "\n";
            saida << "Valor: " << ((Apartamento *)*it)->getValor() << "\n";
            saida << "Cidade: " << ((Apartamento *)*it)->getEndereco().getCidade() << "\n";
            saida << "Bairro: " << ((Apartamento *)*it)->getEndereco().getBairro() << "\n";
            saida << "CEP: " << ((Apartamento *)*it)->getEndereco().getCEP() << "\n";
            saida << "Logradouro: " << ((Apartamento *)*it)->getEndereco().getLogradouro() << "\n";
            saida << "Número: " << ((Apartamento *)*it)->getEndereco().getNumero() << "\n";
            saida << "Posição: " << ((Apartamento *)*it)->getPosicao()<< "\n";
            saida << "Número de Quartos: " << ((Apartamento *)*it)->getNumeroDeQuartos() << "\n";
            saida << "Valor do Condominio: " << ((Apartamento *)*it)->getValorDoCondominio() << "\n";
            saida << "Vagas de Garagem: " << ((Apartamento *)*it)->getVagasDeGaragem() << "\n";
            saida << "Área: " << ((Apartamento *)*it)->getArea() << "\n";
            
            i++;
        }
    }
    if(i == 1)
    {
        saida << "Nenhum resultado encontrado...\n";
    }

    return saida.str();
}
string LRY_IMO::getTerrenos(int tipoOferta)
{
    
    vector<Imovel *>::iterator it;
    int i=1;
    stringstream saida;
    saida << "\t=========Terrenos=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if(((*it)->getTipo() == TIPO_TERRENO)  && (((*it)->getTipoOferta() == tipoOferta) || tipoOferta == VENDA_OU_ALUGUEL))
        {         
            saida << "\t=========Terreno "<<i<<"=========\n";
            saida << "Descrição: " << ((Terreno *)*it)->getDescricao() << "\n";
            saida << "Tipo de Oferta: " << ((Terreno *)*it)->getTipoOferta() << "\n";
            saida << "Valor: " << ((Terreno *)*it)->getValor() << "\n";
            saida << "Cidade: " << ((Terreno *)*it)->getEndereco().getCidade() << "\n";
            saida << "Bairro: " << ((Terreno *)*it)->getEndereco().getBairro() << "\n";
            saida << "CEP: " << ((Terreno *)*it)->getEndereco().getCEP() << "\n";
            saida << "Logradouro: " << ((Terreno *)*it)->getEndereco().getLogradouro() << "\n";
            saida << "Número: " << ((Terreno *)*it)->getEndereco().getNumero() << "\n";
            saida << "Área : " << ((Terreno *)*it)->getArea() << "\n";
            i++;
        }
    }
    if(i == 1)
    {
        saida << "Nenhum resultado encontrado...\n";
    }

    return saida.str();
}
void LRY_IMO::getImoveis()
{
    //Lista todos os terrenos, casas e apartamentos
    std::vector<Imovel *>::iterator it;
    int a , t, c;
    a=t=c=0;

    std::cout << "\t=========APARTAMENTOS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo apartamentos.
    {
        if((*it)->getTipo() == TIPO_APARTAMENTO)
        {
            std::cout << "\tApartamento " << ++a << "\n";
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
            std::cout << "\tTerreno " << ++t << "\n";
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
            std::cout << "\tCasa " << ++c << "\n";
            std::cout << "Descricao: " << ((Casa *)*it)->getDescricao() << "\n";
            std::cout << "Cidade: " << ((Casa *)*it)->getEndereco().getCidade() << "\n";
            std::cout << "Bairro: " << ((Casa *)*it)->getEndereco().getBairro() << "\n";
            std::cout << "Valor: " << ((Casa *)*it)->getValor() << "\n";
        }
    }
}
void LRY_IMO::listarTipoAluguel()
{
    cout << "Imoveis para alugar:" << endl;
    cout << getCasas(ALUGUEL);
    cout << getTerrenos(ALUGUEL);
    cout << getApartamentos(ALUGUEL);
}
void LRY_IMO::listarTipoVenda()
{
    cout << "Imoveis para vender:" << endl;
    cout << getCasas(VENDA);
    cout << getTerrenos(VENDA);
    cout << getApartamentos(VENDA);
}
std::string LRY_IMO::maiusculo(std::string frase)
{

    transform(frase.begin(), frase.end(), frase.begin(), ::toupper); 
    return frase;
}
std::string LRY_IMO::buscarPorBairro()
{
    std::string buscar;
    std::locale loc;
    stringstream saida;

    cout << "Digite o nome do bairro que deseja procurar: ";
    std::getline(std::cin,buscar);

    std::vector<Imovel *>::iterator it;
    int a=0, t=0, c=0;

    saida << "\t=========APARTAMENTOS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo apartamentos.
    {
        if((*it)->getTipo() == TIPO_APARTAMENTO){
            a++;
            if((maiusculo((*it)->getEndereco().getBairro())).find(maiusculo(buscar)) != string::npos )
            {
                saida << "\tApartamento " << a << "\n";
                saida << "Descrição: " << ((Apartamento *)*it)->getDescricao() << "\n";
                saida << "Tipo de Oferta: " << ((Apartamento *)*it)->getTipoOferta() << "\n";
                saida << "Valor: " << ((Apartamento *)*it)->getValor() << "\n";
                saida << "Cidade: " << ((Apartamento *)*it)->getEndereco().getCidade() << "\n";
                saida << "Bairro: " << ((Apartamento *)*it)->getEndereco().getBairro() << "\n";
                saida << "CEP: " << ((Apartamento *)*it)->getEndereco().getCEP() << "\n";
                saida << "Logradouro: " << ((Apartamento *)*it)->getEndereco().getLogradouro() << "\n";
                saida << "Número: " << ((Apartamento *)*it)->getEndereco().getNumero() << "\n";
                saida << "Posição: " << ((Apartamento *)*it)->getPosicao()<< "\n";
                saida << "Número de Quartos: " << ((Apartamento *)*it)->getNumeroDeQuartos() << "\n";
                saida << "Valor do Condominio: " << ((Apartamento *)*it)->getValorDoCondominio() << "\n";
                saida << "Vagas de Garagem: " << ((Apartamento *)*it)->getVagasDeGaragem() << "\n";
                saida << "Área: " << ((Apartamento *)*it)->getArea() << "\n";
            }
        }
    }
   
    saida << "\t=========TERRENOS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Terrenos.
    {
        if((*it)->getTipo() == TIPO_TERRENO){
            t++;
            if((maiusculo((*it)->getEndereco().getBairro())).find(maiusculo(buscar)) != string::npos )
            {
                saida << "\tTerreno " << t << "\n";
                saida << "Descrição: " << ((Terreno *)*it)->getDescricao() << "\n";
                saida << "Tipo de Oferta: " << ((Terreno *)*it)->getTipoOferta() << "\n";
                saida << "Valor: " << ((Terreno *)*it)->getValor() << "\n";
                saida << "Cidade: " << ((Terreno *)*it)->getEndereco().getCidade() << "\n";
                saida << "Bairro: " << ((Terreno *)*it)->getEndereco().getBairro() << "\n";
                saida << "CEP: " << ((Terreno *)*it)->getEndereco().getCEP() << "\n";
                saida << "Logradouro: " << ((Terreno *)*it)->getEndereco().getLogradouro() << "\n";
                saida << "Número: " << ((Terreno *)*it)->getEndereco().getNumero() << "\n";
                saida << "Área : " << ((Terreno *)*it)->getArea() << "\n";
            }
        }
    }

    saida << "\t=========CASAS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if((*it)->getTipo() == TIPO_CASA){
            c++;
            if((maiusculo((*it)->getEndereco().getBairro())).find(maiusculo(buscar)) != string::npos )
            {   
                saida << "\tCasa " << c << "\n";     
                saida << "Descrição: " << ((Casa *)*it)->getDescricao() << "\n";
                saida << "Tipo de Oferta: " << ((Casa *)*it)->getTipoOferta() << "\n";
                saida << "Valor: " << ((Casa *)*it)->getValor() << "\n";
                saida << "Cidade: " << ((Casa *)*it)->getEndereco().getCidade() << "\n";
                saida << "Bairro: " << ((Casa *)*it)->getEndereco().getBairro() << "\n";
                saida << "CEP: " << ((Casa *)*it)->getEndereco().getCEP() << "\n";
                saida << "Logradouro: " << ((Casa *)*it)->getEndereco().getLogradouro() << "\n";
                saida << "Número: " << ((Casa *)*it)->getEndereco().getNumero() << "\n";
                saida << "Número de Pavimentos: " << ((Casa *)*it)->getNumeroDePavimentos() << "\n";
                saida << "Número de Quartos: " << ((Casa *)*it)->getNumeroDeQuartos() << "\n";
                saida << "Área do Terreno: " << ((Casa *)*it)->getAreaDoTerreno() << "\n";
                saida << "Área Construída: " << ((Casa *)*it)->getAreaConstruida() << "\n";
            }
        }
    }
    return saida.str();
}
std::string LRY_IMO::buscarPorCidade()
{
    std::string buscar;
    std::locale loc;
    stringstream saida;

    cout << "Digite o nome da cidade que deseja procurar: ";
    std::getline(std::cin,buscar);

    std::vector<Imovel *>::iterator it;
    int a , t, c;
    a=t=c=0;

    saida << "\t=========APARTAMENTOS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo apartamentos.
    {
        
        if((*it)->getTipo() == TIPO_APARTAMENTO){
            a++;
            if((maiusculo((*it)->getEndereco().getCidade())).find(maiusculo(buscar)) != string::npos )
            {
                saida << "\tApartamento " << a << "\n";
                saida << "Descrição: " << ((Apartamento *)*it)->getDescricao() << "\n";
                saida << "Tipo de Oferta: " << ((Apartamento *)*it)->getTipoOferta() << "\n";
                saida << "Valor: " << ((Apartamento *)*it)->getValor() << "\n";
                saida << "Cidade: " << ((Apartamento *)*it)->getEndereco().getCidade() << "\n";
                saida << "Bairro: " << ((Apartamento *)*it)->getEndereco().getBairro() << "\n";
                saida << "CEP: " << ((Apartamento *)*it)->getEndereco().getCEP() << "\n";
                saida << "Logradouro: " << ((Apartamento *)*it)->getEndereco().getLogradouro() << "\n";
                saida << "Número: " << ((Apartamento *)*it)->getEndereco().getNumero() << "\n";
                saida << "Posição: " << ((Apartamento *)*it)->getPosicao()<< "\n";
                saida << "Número de Quartos: " << ((Apartamento *)*it)->getNumeroDeQuartos() << "\n";
                saida << "Valor do Condominio: " << ((Apartamento *)*it)->getValorDoCondominio() << "\n";
                saida << "Vagas de Garagem: " << ((Apartamento *)*it)->getVagasDeGaragem() << "\n";
                saida << "Área: " << ((Apartamento *)*it)->getArea() << "\n";
            }
        }
    }
   
    saida << "\t=========TERRENOS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Terrenos.
    {
        
        if((*it)->getTipo() == TIPO_TERRENO){
            t++;
            if((maiusculo((*it)->getEndereco().getCidade())).find(maiusculo(buscar)) != string::npos )
            {
                saida << "\tTerreno " << t << "\n";
                saida << "Descrição: " << ((Terreno *)*it)->getDescricao() << "\n";
                saida << "Tipo de Oferta: " << ((Terreno *)*it)->getTipoOferta() << "\n";
                saida << "Valor: " << ((Terreno *)*it)->getValor() << "\n";
                saida << "Cidade: " << ((Terreno *)*it)->getEndereco().getCidade() << "\n";
                saida << "Bairro: " << ((Terreno *)*it)->getEndereco().getBairro() << "\n";
                saida << "CEP: " << ((Terreno *)*it)->getEndereco().getCEP() << "\n";
                saida << "Logradouro: " << ((Terreno *)*it)->getEndereco().getLogradouro() << "\n";
                saida << "Número: " << ((Terreno *)*it)->getEndereco().getNumero() << "\n";
                saida << "Área : " << ((Terreno *)*it)->getArea() << "\n";
            }
        }
    }

    saida << "\t=========CASAS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        
        if((*it)->getTipo() == TIPO_CASA){
            c++;
            if((maiusculo((*it)->getEndereco().getCidade())).find(maiusculo(buscar)) != string::npos )
            {   
                saida << "\tCasa " << c << "\n";     
                saida << "Descrição: " << ((Casa *)*it)->getDescricao() << "\n";
                saida << "Tipo de Oferta: " << ((Casa *)*it)->getTipoOferta() << "\n";
                saida << "Valor: " << ((Casa *)*it)->getValor() << "\n";
                saida << "Cidade: " << ((Casa *)*it)->getEndereco().getCidade() << "\n";
                saida << "Bairro: " << ((Casa *)*it)->getEndereco().getBairro() << "\n";
                saida << "CEP: " << ((Casa *)*it)->getEndereco().getCEP() << "\n";
                saida << "Logradouro: " << ((Casa *)*it)->getEndereco().getLogradouro() << "\n";
                saida << "Número: " << ((Casa *)*it)->getEndereco().getNumero() << "\n";
                saida << "Número de Pavimentos: " << ((Casa *)*it)->getNumeroDePavimentos() << "\n";
                saida << "Número de Quartos: " << ((Casa *)*it)->getNumeroDeQuartos() << "\n";
                saida << "Área do Terreno: " << ((Casa *)*it)->getAreaDoTerreno() << "\n";
                saida << "Área Construída: " << ((Casa *)*it)->getAreaConstruida() << "\n";
            }
        }
    }
    return saida.str();
}
std::string LRY_IMO::buscarPorValor()
{
    double buscar;
    stringstream saida;

    cout << "Digite o valor que deseja procurar: ";
    cin >> buscar;

    std::vector<Imovel *>::iterator it;
    int a , t, c;
    a=t=c=0;

    saida << "\t=========APARTAMENTOS=========\n";
    saida << "\n\tApartamentos com valores MENORES ao desejado: \n\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo apartamentos.
    {
        
        if((*it)->getTipo() == TIPO_APARTAMENTO){
            a++;
            if((*it)->getValor() < buscar)
            {
                saida << "\tApartamento " << a << "\n";
                saida << "Descrição: " << ((Apartamento *)*it)->getDescricao() << "\n";
                saida << "Tipo de Oferta: " << ((Apartamento *)*it)->getTipoOferta() << "\n";
                saida << "Valor: " << ((Apartamento *)*it)->getValor() << "\n";
                saida << "Cidade: " << ((Apartamento *)*it)->getEndereco().getCidade() << "\n";
                saida << "Bairro: " << ((Apartamento *)*it)->getEndereco().getBairro() << "\n";
                saida << "CEP: " << ((Apartamento *)*it)->getEndereco().getCEP() << "\n";
                saida << "Logradouro: " << ((Apartamento *)*it)->getEndereco().getLogradouro() << "\n";
                saida << "Número: " << ((Apartamento *)*it)->getEndereco().getNumero() << "\n";
                saida << "Posição: " << ((Apartamento *)*it)->getPosicao()<< "\n";
                saida << "Número de Quartos: " << ((Apartamento *)*it)->getNumeroDeQuartos() << "\n";
                saida << "Valor do Condominio: " << ((Apartamento *)*it)->getValorDoCondominio() << "\n";
                saida << "Vagas de Garagem: " << ((Apartamento *)*it)->getVagasDeGaragem() << "\n";
                saida << "Área: " << ((Apartamento *)*it)->getArea() << "\n";
            }
        }
    }
   
    saida << "\t=========TERRENOS=========\n";
    saida << "\n\tTerrenos com valores MENORES ao desejado: \n\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Terrenos.
    {
        
        if((*it)->getTipo() == TIPO_TERRENO){
            t++;
            if((*it)->getValor() < buscar)
            {
                saida << "\tTerreno " << t << "\n";
                saida << "Descrição: " << ((Terreno *)*it)->getDescricao() << "\n";
                saida << "Tipo de Oferta: " << ((Terreno *)*it)->getTipoOferta() << "\n";
                saida << "Valor: " << ((Terreno *)*it)->getValor() << "\n";
                saida << "Cidade: " << ((Terreno *)*it)->getEndereco().getCidade() << "\n";
                saida << "Bairro: " << ((Terreno *)*it)->getEndereco().getBairro() << "\n";
                saida << "CEP: " << ((Terreno *)*it)->getEndereco().getCEP() << "\n";
                saida << "Logradouro: " << ((Terreno *)*it)->getEndereco().getLogradouro() << "\n";
                saida << "Número: " << ((Terreno *)*it)->getEndereco().getNumero() << "\n";
                saida << "Área : " << ((Terreno *)*it)->getArea() << "\n";
            }
        }
    }

    saida << "\t=========CASAS=========\n";
    saida << " \n\tCasas com valores MENORES ao desejado: \n\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        
        if((*it)->getTipo() == TIPO_CASA){
            c++;
            if((*it)->getValor() < buscar)
            {   
                saida << "\tCasa " << c << "\n";     
                saida << "Descrição: " << ((Casa *)*it)->getDescricao() << "\n";
                saida << "Tipo de Oferta: " << ((Casa *)*it)->getTipoOferta() << "\n";
                saida << "Valor: " << ((Casa *)*it)->getValor() << "\n";
                saida << "Cidade: " << ((Casa *)*it)->getEndereco().getCidade() << "\n";
                saida << "Bairro: " << ((Casa *)*it)->getEndereco().getBairro() << "\n";
                saida << "CEP: " << ((Casa *)*it)->getEndereco().getCEP() << "\n";
                saida << "Logradouro: " << ((Casa *)*it)->getEndereco().getLogradouro() << "\n";
                saida << "Número: " << ((Casa *)*it)->getEndereco().getNumero() << "\n";
                saida << "Número de Pavimentos: " << ((Casa *)*it)->getNumeroDePavimentos() << "\n";
                saida << "Número de Quartos: " << ((Casa *)*it)->getNumeroDeQuartos() << "\n";
                saida << "Área do Terreno: " << ((Casa *)*it)->getAreaDoTerreno() << "\n";
                saida << "Área Construída: " << ((Casa *)*it)->getAreaConstruida() << "\n";
            }
        }
    }
    return saida.str();
}
std::string LRY_IMO::buscarPorDescricao()
{
    std::string buscar;
    std::locale loc;
    stringstream saida;

    cout << "Digite o título que deseja procurar: ";
    std::getline(std::cin,buscar);

    std::vector<Imovel *>::iterator it;
    int a , t, c;
    a=t=c=0;

    saida << "\t=========APARTAMENTOS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo apartamentos.
    {
        if((*it)->getTipo() == TIPO_APARTAMENTO){
            a++;
            if((maiusculo((*it)->getDescricao()).find(maiusculo(buscar))) != string::npos)
            {
                saida << "\tApartamento " << a << "\n";
                saida << "Descrição: " << ((Apartamento *)*it)->getDescricao() << "\n";
                saida << "Tipo de Oferta: " << ((Apartamento *)*it)->getTipoOferta() << "\n";
                saida << "Valor: " << ((Apartamento *)*it)->getValor() << "\n";
                saida << "Cidade: " << ((Apartamento *)*it)->getEndereco().getCidade() << "\n";
                saida << "Bairro: " << ((Apartamento *)*it)->getEndereco().getBairro() << "\n";
                saida << "CEP: " << ((Apartamento *)*it)->getEndereco().getCEP() << "\n";
                saida << "Logradouro: " << ((Apartamento *)*it)->getEndereco().getLogradouro() << "\n";
                saida << "Número: " << ((Apartamento *)*it)->getEndereco().getNumero() << "\n";
                saida << "Posição: " << ((Apartamento *)*it)->getPosicao()<< "\n";
                saida << "Número de Quartos: " << ((Apartamento *)*it)->getNumeroDeQuartos() << "\n";
                saida << "Valor do Condominio: " << ((Apartamento *)*it)->getValorDoCondominio() << "\n";
                saida << "Vagas de Garagem: " << ((Apartamento *)*it)->getVagasDeGaragem() << "\n";
                saida << "Área: " << ((Apartamento *)*it)->getArea() << "\n";
            }
        }
    }
   
    saida << "\t=========TERRENOS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Terrenos.
    {
        if((*it)->getTipo() == TIPO_TERRENO){
            t++;
            if((maiusculo((*it)->getDescricao())).find(maiusculo(buscar)) != string::npos )
            {
                saida << "\tTerreno " << t << "\n";
                saida << "Descrição: " << ((Terreno *)*it)->getDescricao() << "\n";
                saida << "Tipo de Oferta: " << ((Terreno *)*it)->getTipoOferta() << "\n";
                saida << "Valor: " << ((Terreno *)*it)->getValor() << "\n";
                saida << "Cidade: " << ((Terreno *)*it)->getEndereco().getCidade() << "\n";
                saida << "Bairro: " << ((Terreno *)*it)->getEndereco().getBairro() << "\n";
                saida << "CEP: " << ((Terreno *)*it)->getEndereco().getCEP() << "\n";
                saida << "Logradouro: " << ((Terreno *)*it)->getEndereco().getLogradouro() << "\n";
                saida << "Número: " << ((Terreno *)*it)->getEndereco().getNumero() << "\n";
                saida << "Área : " << ((Terreno *)*it)->getArea() << "\n";
            }
        }
    }

    saida << "\t=========CASAS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if((*it)->getTipo() == TIPO_CASA){
            c++;
            if((maiusculo((*it)->getDescricao())).find(maiusculo(buscar)) != string::npos )
            {   
                saida << "\tCasa " << c << "\n";     
                saida << "Descrição: " << ((Casa *)*it)->getDescricao() << "\n";
                saida << "Tipo de Oferta: " << ((Casa *)*it)->getTipoOferta() << "\n";
                saida << "Valor: " << ((Casa *)*it)->getValor() << "\n";
                saida << "Cidade: " << ((Casa *)*it)->getEndereco().getCidade() << "\n";
                saida << "Bairro: " << ((Casa *)*it)->getEndereco().getBairro() << "\n";
                saida << "CEP: " << ((Casa *)*it)->getEndereco().getCEP() << "\n";
                saida << "Logradouro: " << ((Casa *)*it)->getEndereco().getLogradouro() << "\n";
                saida << "Número: " << ((Casa *)*it)->getEndereco().getNumero() << "\n";
                saida << "Número de Pavimentos: " << ((Casa *)*it)->getNumeroDePavimentos() << "\n";
                saida << "Número de Quartos: " << ((Casa *)*it)->getNumeroDeQuartos() << "\n";
                saida << "Área do Terreno: " << ((Casa *)*it)->getAreaDoTerreno() << "\n";
                saida << "Área Construída: " << ((Casa *)*it)->getAreaConstruida() << "\n";
            }
        }
    }
    return saida.str();
}
void LRY_IMO::removerImovel( string lista)
{
    //cout<<lista;
    int numero=1,tipo=0;
    //while(numero!=0 && (tipo==1 || tipo==2)){
    cout << "\n __________________________________________\n";
    std::cout<<"Digite o tipo do imóvel que você deseja remover(Apartamento=1, Casa=2, Terreno=3): ";
    std::cin>>tipo;
    std::cout<<"Digite o número do imóvel que você deseja remover: ";
    std::cin>>numero;
    //}
   vector<Imovel *>::iterator it;
   vector<Imovel *>::iterator pos;
    int count=0;
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)
    {
        if((*it)->getTipo() == tipo){
            count++;
            if(count==numero){
                pos=it;
            }

        }
    }
    this->imoveis.erase(pos);  
}
string LRY_IMO::toString()
{
    vector<Imovel *>::iterator it;
    stringstream saida;
    int i=1;

    saida << "\t/=========APARTAMENTOS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if((*it)->getTipo() == TIPO_APARTAMENTO)
        {         
            saida << "\t=========Apartamento "<<i<<"=========\n";
            saida << ((Apartamento *)(*it))->toString();
            i++;
        }
    }
    i = 1;
    saida << "\t=========CASAS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if((*it)->getTipo() == TIPO_CASA)
        {         
            saida << "\t=========Casa "<<i<<"=========\n";
            saida << ((Casa *)(*it))->toString();
            i++;
        }
    }
    i = 1;
    saida << "\t=========TERRENO=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if((*it)->getTipo() == TIPO_TERRENO)
        {         
            saida << "\t=========Terreno "<<i<<"=========\n";
            saida << ((Terreno *)(*it))->toString();
            i++;
        }
    }

    return saida.str();
}
void LRY_IMO::editarImoveis()
{
    /*switch(tipoImovel)
    {
        case TIPO_APARTAMENTO: cout << getApartamentos(); break;
        case TIPO_CASA:        cout << getCasas(); break;
        case TIPO_TERRENO:     cout << getTerrenos(); 
    }*/
    int numero, count = 0, tipo;
    cout<<"Digite o tipo do imóvel que você deseja remover(Apartamento=1, Casa=2, Terreno=3): ";
    cin>>tipo;
    cout<<"Digite o número do imóvel que você deseja editar: ";
    cin>>numero;
    cin.ignore();

    vector<Imovel *>::iterator it, alvo;
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)
    {
        if((*it)->getTipo() == tipo){
            count++;
            if(count==numero){
                alvo=it;
            }

        }
    }
    cout << "Pressione ENTER para manter os valores atuais.\n";
    if(tipo == TIPO_APARTAMENTO)
    {
        Apartamento *ap;
        Endereco *end;
        string descricao, cidade, bairro, CEP, logradouro, posicao,
        tipoOferta, numero, vagasDeGaragem, numeroDeQuartos,
        valor, valorDoCondominio, area;
        stringstream novoApartamento;
        
        cout << "Descrição: ";
        getline(cin,descricao);
        if(descricao.empty())
            novoApartamento << (*alvo)->getDescricao() << endl;
        else
            novoApartamento << descricao << endl;
        cout << "Tipo de oferta: ";
        getline(cin,tipoOferta);
        if(tipoOferta.empty())
            novoApartamento << (*alvo)->getTipoOferta()<< endl;
        else
            novoApartamento << tipoOferta << endl;
        cout << "Valor: ";
        getline(cin,valor);
        if(valor.empty())
            novoApartamento << (*alvo)->getValor()<< endl;
        else
            novoApartamento << valor << endl;
        cout << "Cidade: ";
        getline(cin,cidade);
        if(cidade.empty())
            novoApartamento << (*alvo)->getEndereco().getCidade() << endl;
        else
            novoApartamento << cidade << endl;
        cout << "Bairro: ";
        getline(cin,bairro);
        if(bairro.empty())
            novoApartamento << (*alvo)->getEndereco().getBairro() << endl;
        else
            novoApartamento << bairro << endl;
        cout << "CEP: ";
        getline(cin,CEP);
        if(CEP.empty())
            novoApartamento << (*alvo)->getEndereco().getCEP() << endl;
        else
            novoApartamento << CEP << endl;
        cout << "Logradouro: ";
        getline(cin,logradouro);
        if(logradouro.empty())
            novoApartamento << (*alvo)->getEndereco().getLogradouro() << endl;
        else
            novoApartamento << logradouro << endl;
        cout << "Número: ";
        getline(cin,numero);
        if(numero.empty())
            novoApartamento << (*alvo)->getEndereco().getNumero() << endl;
        else
            novoApartamento << numero << endl;
        cout << "Posição: ";
        getline(cin,posicao);
        if(posicao.empty())
            novoApartamento << ((Apartamento *)(*alvo))->getPosicao() << endl;
        else
            novoApartamento << posicao << endl;
        cout << "Número de Quartos: ";
        getline(cin,numeroDeQuartos);
        if(numeroDeQuartos.empty())
            novoApartamento << ((Apartamento *)(*alvo))->getNumeroDeQuartos() << endl;
        else
            novoApartamento << numeroDeQuartos << endl;
        cout << "Valor do Condomínio: ";
        getline(cin,valorDoCondominio);
        if(valorDoCondominio.empty())
            novoApartamento << ((Apartamento *)(*alvo))->getValorDoCondominio() << endl;
        else
            novoApartamento << valorDoCondominio << endl;
        cout << "Vagas de Garagem: ";
        getline(cin,vagasDeGaragem);
        if(vagasDeGaragem.empty())
            novoApartamento << ((Apartamento *)(*alvo))->getVagasDeGaragem() << endl;
        else
            novoApartamento << vagasDeGaragem << endl;
        cout << "Área: ";
        getline(cin,area);
        if(area.empty())
            novoApartamento << ((Apartamento *)(*alvo))->getArea() << endl;
        else
            novoApartamento << area << endl;
        
        int tipoOfertaInt, numeroInt, vagasDeGaragemInt, numeroDeQuartosInt;
        double areaDoub, valorDoub, valorDoCondominioDoub;

        getline(novoApartamento, descricao);
        (*alvo)->setDescricao(descricao);
        novoApartamento >> tipoOfertaInt;
        (*alvo)->setTipoOferta(tipoOfertaInt);
        novoApartamento >>  valorDoub;
        (*alvo)->setValor(valorDoub);
        novoApartamento.ignore();
        getline(novoApartamento, cidade);
        getline(novoApartamento, bairro);
        getline(novoApartamento, CEP);
        getline(novoApartamento, logradouro);
        novoApartamento >> numeroInt;
        novoApartamento.ignore();
        end = new Endereco(logradouro, numeroInt, bairro, cidade, CEP);
        (*alvo)->setEndereco(*end);
        getline(novoApartamento, posicao);
        ((Apartamento *)(*alvo))->setPosicao(posicao);
        novoApartamento >> numeroDeQuartosInt;
        ((Apartamento *)(*alvo))->setNumeroDeQuartos(numeroDeQuartosInt);
        novoApartamento >> valorDoCondominioDoub;
        ((Apartamento *)(*alvo))->setValorDoCondominio(valorDoCondominioDoub);
        novoApartamento >> vagasDeGaragemInt;
        ((Apartamento *)(*alvo))->setVagasDeGaragem(vagasDeGaragemInt);        
        novoApartamento >> areaDoub;
        ((Apartamento *)(*alvo))->setArea(areaDoub);
        

    }else if(tipo == TIPO_CASA)
    {
        Casa *casa;
        Endereco *end;
        string descricao, cidade, bairro, CEP, logradouro,
        tipoOferta, numero, numeroDePavimentos, numeroDeQuartos,
        valor, areaDoTerreno, areaConstruida;
        stringstream novaCasa;

        cout<<"Descrição: ";
        getline(cin,descricao);
        if(descricao.empty())
            novaCasa << (*alvo)->getDescricao() << endl;
        else
            novaCasa << descricao << endl;
        cout<<"Tipo de oferta: ";
        getline(cin, tipoOferta);
        if(tipoOferta.empty())
            novaCasa << (*alvo)->getTipoOferta() << endl;
        else
            novaCasa << tipoOferta << endl;
        cout<<"Valor: ";
        getline(cin, valor);
        if(valor.empty())
            novaCasa << (*alvo)->getValor() << endl;
        else
            novaCasa << valor << endl;
        cout<<"Cidade: ";
        getline(cin,cidade);
        if(cidade.empty())
            novaCasa << (*alvo)->getEndereco().getCidade() << endl;
        else
            novaCasa << cidade << endl;
        cout<<"Bairro: ";
        getline(cin,bairro);
        if(bairro.empty())
            novaCasa << (*alvo)->getEndereco().getBairro() << endl;
        else
            novaCasa << bairro << endl;
        cout<<"CEP: ";
        getline(cin,CEP);
        if(CEP.empty())
            novaCasa << (*alvo)->getEndereco().getCEP() << endl;
        else
            novaCasa << CEP << endl;
        cout<<"Logradouro: ";
        getline(cin,logradouro);
        if(logradouro.empty())
            novaCasa << (*alvo)->getEndereco().getLogradouro() << endl;
        else
            novaCasa << logradouro << endl;
        cout<<"Número: ";
        getline(cin, numero);
        if(numero.empty())
            novaCasa << (*alvo)->getEndereco().getNumero() << endl;
        else
            novaCasa << numero << endl;
        cout<<"Número de pavimentos: ";
        getline(cin, numeroDePavimentos);
        if(numeroDePavimentos.empty())
            novaCasa << ((Casa *)(*alvo))->getNumeroDePavimentos() << endl;
        else
            novaCasa << numeroDePavimentos << endl;
        cout<<"Número de quartos: ";
        getline(cin, numeroDeQuartos);
        if(numeroDeQuartos.empty())
            novaCasa << ((Casa *)(*alvo))->getNumeroDeQuartos() << endl;
        else
            novaCasa << numeroDeQuartos << endl;
        cout<<"Área do terreno: ";
        getline(cin, areaDoTerreno);
        if(areaDoTerreno.empty())
            novaCasa << ((Casa *)(*alvo))->getAreaDoTerreno() << endl;
        else
            novaCasa << areaDoTerreno << endl;
        cout<<"Área construida: ";
        getline(cin, areaConstruida);
        if(areaConstruida.empty())
            novaCasa << ((Casa *)(*alvo))->getAreaConstruida() << endl;
        else
            novaCasa << areaConstruida << endl;

        int tipoOfertaInt, numeroInt, numeroDePavimentosInt, numeroDeQuartosInt;
        double valorDoub, areaDoTerrenoDoub, areaConstruidaDoub;
        
        getline(novaCasa, descricao);
        (*alvo)->setDescricao(descricao);
        novaCasa >> tipoOfertaInt;
        (*alvo)->setTipoOferta(tipoOfertaInt);
        novaCasa >> valorDoub;
        (*alvo)->setValor(valorDoub);
        novaCasa.ignore();
        getline(novaCasa, cidade);
        getline(novaCasa, bairro);
        getline(novaCasa, CEP);
        getline(novaCasa, logradouro);
        novaCasa >> numeroInt;

        end = new Endereco(logradouro, numeroInt, bairro, cidade, CEP);
        (*alvo)->setEndereco(*end);

        novaCasa >> numeroDePavimentosInt;
        ((Casa *)(*alvo))->setNumeroDePavimentos(numeroDePavimentosInt);
        novaCasa >> numeroDeQuartosInt;
        ((Casa *)(*alvo))->setNumeroDeQuartos(numeroDeQuartosInt);
        novaCasa >> areaDoTerrenoDoub;
        ((Casa *)(*alvo))->setAreaDoTerreno(areaDoTerrenoDoub);
        novaCasa >> areaConstruidaDoub;
        ((Casa*)(*alvo))->setAreaConstruida(areaConstruidaDoub);
    }else if(tipo == TIPO_TERRENO)
    {
        Terreno *ter;
        Endereco *end;
        string descricao, cidade, bairro, CEP, logradouro,
        tipoOferta, numero,
        valor, area;
        stringstream novoTerreno;

        cout<<"Descrição: ";
        getline(cin,descricao);
        if(descricao.empty())
            novoTerreno << (*alvo)->getDescricao() << endl;
        else
            novoTerreno << descricao << endl;
        cout<<"Tipo de oferta: ";
        getline(cin, tipoOferta);
        if(tipoOferta.empty())
            novoTerreno << (*alvo)->getTipoOferta() << endl;
        else
            novoTerreno << tipoOferta << endl;
        cout<<"Valor: ";
        getline(cin, valor);
        if(valor.empty())
            novoTerreno << (*alvo)->getValor() << endl;
        else
            novoTerreno << valor << endl;
        cout<<"Cidade: ";
        getline(cin,cidade);
        if(cidade.empty())
            novoTerreno << (*alvo)->getEndereco().getCidade() << endl;
        else
            novoTerreno << cidade << endl;
        cout<<"Bairro: ";
        getline(cin,bairro);
        if(bairro.empty())
            novoTerreno << (*alvo)->getEndereco().getBairro() << endl;
        else
            novoTerreno << bairro << endl;
        cout<<"CEP: ";
        getline(cin,CEP);
        if(CEP.empty())
            novoTerreno << (*alvo)->getEndereco().getCEP() << endl;
        else
            novoTerreno << CEP << endl;
        cout<<"Logradouro: ";
        getline(cin,logradouro);
        if(logradouro.empty())
            novoTerreno << (*alvo)->getEndereco().getLogradouro() << endl;
        else
            novoTerreno << logradouro << endl;
        cout<<"Número: ";
        getline(cin, numero);
        if(numero.empty())
            novoTerreno << (*alvo)->getEndereco().getNumero() << endl;
        else
            novoTerreno << numero << endl;
        cout<<"Área: ";
        getline(cin, area);
        if(area.empty())//=========================================
            novoTerreno << ((Terreno *)(*alvo))->getArea() << endl;
        else
            novoTerreno << area << endl;

        int tipoOfertaInt, numeroInt;
        double valorDoub, areaDoub;

        getline(novoTerreno, descricao);
        (*alvo)->setDescricao(descricao);
        novoTerreno >> tipoOfertaInt;
        (*alvo)->setTipoOferta(tipoOfertaInt);
        novoTerreno >> valorDoub;
        (*alvo)->setValor(valorDoub);
        novoTerreno.ignore();
        getline(novoTerreno, cidade);
        getline(novoTerreno, bairro);
        getline(novoTerreno, CEP);
        getline(novoTerreno, logradouro);
        novoTerreno >> numeroInt;
        end = new Endereco(logradouro, numeroInt, bairro, cidade, CEP);
        (*alvo)->setEndereco(*end);
        novoTerreno >> areaDoub;
        ((Terreno *)(*alvo))->setArea(areaDoub);
    }
    cout << "Imóvel editado com sucesso!\n";
}