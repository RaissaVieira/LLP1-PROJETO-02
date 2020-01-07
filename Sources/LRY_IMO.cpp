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

void LRY_IMO::lerCasasSalvas()
{
    ifstream casas("./Arquivos/Casas.txt");

    while(!casas.eof())
    {
        Casa *casa;
        Endereco *end;
        string descricao, cidade, bairro, CEP, logradouro;
        int tipoOferta, numero, numeroDePavimentos, numeroDeQuartos;
        double valor, areaDoTerreno, areaConstruida;

        getline(casas,descricao);
        casas>>tipoOferta;
        casas>>valor;
        casas.ignore();
        getline(casas,cidade);
        getline(casas,bairro);
        getline(casas,CEP);
        getline(casas,logradouro);
        casas>>numero;
        casas>>numeroDePavimentos;
        casas>>numeroDeQuartos;
        casas>>areaDoTerreno;
        casas>>areaConstruida;
        casas.ignore();

        end = new Endereco(logradouro, numero, bairro, cidade, CEP);

        casa = new Casa(descricao,tipoOferta,valor, *end, numeroDePavimentos, numeroDeQuartos, areaDoTerreno, areaConstruida);
        casa->setTipo(2);
        this->imoveis.push_back(casa);
    }

    casas.close();
}

void LRY_IMO::lerApartamentosSalvos()
{
    ifstream apartamentos("./Arquivos/Apartamentos.txt");

    while(!apartamentos.eof())
    {
        Apartamento *ap;
        Endereco *end;
        string descricao, cidade, bairro, CEP, logradouro, posicao;
        int tipoOferta, numero, vagasDeGaragem, numeroDeQuartos;
        double valor, valorDoCondominio, area;

        getline(apartamentos,descricao);
        apartamentos>>tipoOferta;
        apartamentos>>valor;
        apartamentos.ignore();
        getline(apartamentos,cidade);
        getline(apartamentos,bairro);
        getline(apartamentos,CEP);
        getline(apartamentos,logradouro);
        apartamentos>>numero;
        apartamentos.ignore();
        getline(apartamentos,posicao);
        apartamentos>>numeroDeQuartos;
        apartamentos>>valorDoCondominio;
        apartamentos>>vagasDeGaragem;
        apartamentos>>area;
        apartamentos.ignore();

        end = new Endereco(logradouro, numero, bairro, cidade, CEP);

        ap = new Apartamento(descricao,tipoOferta,valor, *end, posicao, numeroDeQuartos, valorDoCondominio, vagasDeGaragem, area);
        ap->setTipo(1);

        this->imoveis.push_back(ap);
    }
    apartamentos.close();
}

void LRY_IMO::lerTerrenosSalvos()
{
    ifstream terrenos("./Arquivos/Terrenos.txt");

    while(!terrenos.eof())
    {
        Terreno *ter;
        Endereco *end;
        string descricao, cidade, bairro, CEP, logradouro;
        int tipoOferta, numero;
        double valor, area;

        getline(terrenos,descricao);
        terrenos>>tipoOferta;
        terrenos>>valor;
        terrenos.ignore();
        getline(terrenos,cidade);
        getline(terrenos,bairro);
        getline(terrenos,CEP);
        getline(terrenos,logradouro);
        terrenos>>numero;
        terrenos>>area;
        terrenos.ignore();

        end = new Endereco(logradouro, numero, bairro, cidade, CEP);
        ter = new Terreno (descricao,tipoOferta,valor, *end, area);
        ter->setTipo(3);
        this->imoveis.push_back(ter);
    }
    terrenos.close();
}

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

void LRY_IMO::cadastrarTerreno ()
{
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

void LRY_IMO::cadastrarCasa()
{
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

void LRY_IMO::listarCasa(int tipoOferta)
{
    
    vector<Imovel *>::iterator it;
    string saida;
    int i=1;
    cout << "\t=========CASAS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if(((*it)->getTipo() == TIPO_CASA)  && (((*it)->getTipoOferta() == tipoOferta) || tipoOferta == VENDA_OU_ALUGUEL))
        {         
            cout << "\t=========Casa "<<i<<"=========\n";
            cout << "Descrição: " << ((Casa *)*it)->getDescricao() << "\n";
            cout << "Tipo de Oferta: " << ((Casa *)*it)->getTipoOferta() << "\n";
            cout << "Valor: " << ((Casa *)*it)->getValor() << "\n";
            cout << "Cidade: " << ((Casa *)*it)->getEndereco().getCidade() << "\n";
            cout << "Bairro: " << ((Casa *)*it)->getEndereco().getBairro() << "\n";
            cout << "CEP: " << ((Casa *)*it)->getEndereco().getCEP() << "\n";
            cout << "Logradouro: " << ((Casa *)*it)->getEndereco().getLogradouro() << "\n";
            cout << "Número: " << ((Casa *)*it)->getEndereco().getNumero() << "\n";
            cout << "Número de Pavimentos: " << ((Casa *)*it)->getNumeroDePavimentos() << "\n";
            cout << "Número de Quartos: " << ((Casa *)*it)->getNumeroDeQuartos() << "\n";
            cout << "Área do Terreno: " << ((Casa *)*it)->getAreaDoTerreno() << "\n";
            cout << "Área Construída: " << ((Casa *)*it)->getAreaConstruida() << "\n";
            i++;
        }
    }
    if(i == 1)
    {
        cout << "Nenhum resultado encontrado...\n";
    }
}
void LRY_IMO::listarApartamento(int tipoOferta){
    
    vector<Imovel *>::iterator it;
    int i=1;
    string saida;
    cout << "\t=========Apartamentos=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if(((*it)->getTipo() == TIPO_APARTAMENTO) && (((*it)->getTipoOferta() == tipoOferta) || tipoOferta == VENDA_OU_ALUGUEL))
        {         
            cout << "\t=========Apartamento "<<i<<"=========\n";
            cout << "Descrição: " << ((Apartamento *)*it)->getDescricao() << "\n";
            cout << "Tipo de Oferta: " << ((Apartamento *)*it)->getTipoOferta() << "\n";
            cout << "Valor: " << ((Apartamento *)*it)->getValor() << "\n";
            cout << "Cidade: " << ((Apartamento *)*it)->getEndereco().getCidade() << "\n";
            cout << "Bairro: " << ((Apartamento *)*it)->getEndereco().getBairro() << "\n";
            cout << "CEP: " << ((Apartamento *)*it)->getEndereco().getCEP() << "\n";
            cout << "Logradouro: " << ((Apartamento *)*it)->getEndereco().getLogradouro() << "\n";
            cout << "Número: " << ((Apartamento *)*it)->getEndereco().getNumero() << "\n";
            cout << "Posição: " << ((Apartamento *)*it)->getPosicao()<< "\n";
            cout << "Número de Quartos: " << ((Apartamento *)*it)->getNumeroDeQuartos() << "\n";
            cout << "Valor do Condominio: " << ((Apartamento *)*it)->getValorDoCondominio() << "\n";
            cout << "Vagas de Garagem: " << ((Apartamento *)*it)->getVagasDeGaragem() << "\n";
            cout << "Área: " << ((Apartamento *)*it)->getArea() << "\n";
            
            i++;
        }
    }
    if(i == 1)
    {
        cout << "Nenhum resultado encontrado...\n";
    }
}
void LRY_IMO::listarTerreno(int tipoOferta){
    
    vector<Imovel *>::iterator it;
    int i=1;
    string saida;
    cout << "\t=========Terrenos=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if(((*it)->getTipo() == TIPO_TERRENO)  && (((*it)->getTipoOferta() == tipoOferta) || tipoOferta == VENDA_OU_ALUGUEL))
        {         
            cout << "\t=========Terreno "<<i<<"=========\n";
            cout << "Descrição: " << ((Terreno *)*it)->getDescricao() << "\n";
            cout << "Tipo de Oferta: " << ((Terreno *)*it)->getTipoOferta() << "\n";
            cout << "Valor: " << ((Terreno *)*it)->getValor() << "\n";
            cout << "Cidade: " << ((Terreno *)*it)->getEndereco().getCidade() << "\n";
            cout << "Bairro: " << ((Terreno *)*it)->getEndereco().getBairro() << "\n";
            cout << "CEP: " << ((Terreno *)*it)->getEndereco().getCEP() << "\n";
            cout << "Logradouro: " << ((Terreno *)*it)->getEndereco().getLogradouro() << "\n";
            cout << "Número: " << ((Terreno *)*it)->getEndereco().getNumero() << "\n";
            cout << "Área : " << ((Terreno *)*it)->getArea() << "\n";
            i++;
        }
    }
    if(i == 1)
    {
        cout << "Nenhum resultado encontrado...\n";
    }
}
void LRY_IMO::getImoveis(){
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
    listarCasa(ALUGUEL);
    listarTerreno(ALUGUEL);
    listarApartamento(ALUGUEL);
}

void LRY_IMO::listarTipoVenda()
{
    cout << "Imoveis para vender:" << endl;
    listarCasa(VENDA);
    listarTerreno(VENDA);
    listarApartamento(VENDA);
}

std::string LRY_IMO::maiusculo(std::string frase){

    transform(frase.begin(), frase.end(), frase.begin(), ::toupper); 
    return frase;
}

void LRY_IMO::buscarPorBairro(){
    std::string buscar;
    std::locale loc;

    cout << "Digite o nome do bairro que deseja procurar: ";
    std::getline(std::cin,buscar);

    std::vector<Imovel *>::iterator it;
    int a , t, c;
    a=t=c=0;

    std::cout << "\t=========APARTAMENTOS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo apartamentos.
    {
        if((*it)->getTipo() == TIPO_APARTAMENTO){
            if((maiusculo((*it)->getEndereco().getBairro())).find(maiusculo(buscar)) != string::npos )
            {
                std::cout << "\tApartamento " << ++a << "\n";
                cout << "Descrição: " << ((Apartamento *)*it)->getDescricao() << "\n";
                cout << "Tipo de Oferta: " << ((Apartamento *)*it)->getTipoOferta() << "\n";
                cout << "Valor: " << ((Apartamento *)*it)->getValor() << "\n";
                cout << "Cidade: " << ((Apartamento *)*it)->getEndereco().getCidade() << "\n";
                cout << "Bairro: " << ((Apartamento *)*it)->getEndereco().getBairro() << "\n";
                cout << "CEP: " << ((Apartamento *)*it)->getEndereco().getCEP() << "\n";
                cout << "Logradouro: " << ((Apartamento *)*it)->getEndereco().getLogradouro() << "\n";
                cout << "Número: " << ((Apartamento *)*it)->getEndereco().getNumero() << "\n";
                cout << "Posição: " << ((Apartamento *)*it)->getPosicao()<< "\n";
                cout << "Número de Quartos: " << ((Apartamento *)*it)->getNumeroDeQuartos() << "\n";
                cout << "Valor do Condominio: " << ((Apartamento *)*it)->getValorDoCondominio() << "\n";
                cout << "Vagas de Garagem: " << ((Apartamento *)*it)->getVagasDeGaragem() << "\n";
                cout << "Área: " << ((Apartamento *)*it)->getArea() << "\n";
            }
        }
    }
   
    std::cout << "\t=========TERRENOS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Terrenos.
    {
        if((*it)->getTipo() == TIPO_TERRENO){

            if((maiusculo((*it)->getEndereco().getBairro())).find(maiusculo(buscar)) != string::npos )
            {
                std::cout << "\tTerreno " << ++t << "\n";
                cout << "Descrição: " << ((Terreno *)*it)->getDescricao() << "\n";
                cout << "Tipo de Oferta: " << ((Terreno *)*it)->getTipoOferta() << "\n";
                cout << "Valor: " << ((Terreno *)*it)->getValor() << "\n";
                cout << "Cidade: " << ((Terreno *)*it)->getEndereco().getCidade() << "\n";
                cout << "Bairro: " << ((Terreno *)*it)->getEndereco().getBairro() << "\n";
                cout << "CEP: " << ((Terreno *)*it)->getEndereco().getCEP() << "\n";
                cout << "Logradouro: " << ((Terreno *)*it)->getEndereco().getLogradouro() << "\n";
                cout << "Número: " << ((Terreno *)*it)->getEndereco().getNumero() << "\n";
                cout << "Área : " << ((Terreno *)*it)->getArea() << "\n";
            }
        }
    }

    std::cout << "\t=========CASAS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if((*it)->getTipo() == TIPO_CASA){

            if((maiusculo((*it)->getEndereco().getBairro())).find(maiusculo(buscar)) != string::npos )
            {   
                std::cout << "\tCasa " << ++c << "\n";     
                cout << "Descrição: " << ((Casa *)*it)->getDescricao() << "\n";
                cout << "Tipo de Oferta: " << ((Casa *)*it)->getTipoOferta() << "\n";
                cout << "Valor: " << ((Casa *)*it)->getValor() << "\n";
                cout << "Cidade: " << ((Casa *)*it)->getEndereco().getCidade() << "\n";
                cout << "Bairro: " << ((Casa *)*it)->getEndereco().getBairro() << "\n";
                cout << "CEP: " << ((Casa *)*it)->getEndereco().getCEP() << "\n";
                cout << "Logradouro: " << ((Casa *)*it)->getEndereco().getLogradouro() << "\n";
                cout << "Número: " << ((Casa *)*it)->getEndereco().getNumero() << "\n";
                cout << "Número de Pavimentos: " << ((Casa *)*it)->getNumeroDePavimentos() << "\n";
                cout << "Número de Quartos: " << ((Casa *)*it)->getNumeroDeQuartos() << "\n";
                cout << "Área do Terreno: " << ((Casa *)*it)->getAreaDoTerreno() << "\n";
                cout << "Área Construída: " << ((Casa *)*it)->getAreaConstruida() << "\n";
            }
        }
    }

}
void LRY_IMO::buscarPorCidade(){
    std::string buscar;
    std::locale loc;

    cout << "Digite o nome da cidade que deseja procurar: ";
    std::getline(std::cin,buscar);

    std::vector<Imovel *>::iterator it;
    int a , t, c;
    a=t=c=0;

    std::cout << "\t=========APARTAMENTOS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo apartamentos.
    {
        if((*it)->getTipo() == TIPO_APARTAMENTO){
            if((maiusculo((*it)->getEndereco().getCidade())).find(maiusculo(buscar)) != string::npos )
            {
                std::cout << "\tApartamento " << ++a << "\n";
                cout << "Descrição: " << ((Apartamento *)*it)->getDescricao() << "\n";
                cout << "Tipo de Oferta: " << ((Apartamento *)*it)->getTipoOferta() << "\n";
                cout << "Valor: " << ((Apartamento *)*it)->getValor() << "\n";
                cout << "Cidade: " << ((Apartamento *)*it)->getEndereco().getCidade() << "\n";
                cout << "Bairro: " << ((Apartamento *)*it)->getEndereco().getBairro() << "\n";
                cout << "CEP: " << ((Apartamento *)*it)->getEndereco().getCEP() << "\n";
                cout << "Logradouro: " << ((Apartamento *)*it)->getEndereco().getLogradouro() << "\n";
                cout << "Número: " << ((Apartamento *)*it)->getEndereco().getNumero() << "\n";
                cout << "Posição: " << ((Apartamento *)*it)->getPosicao()<< "\n";
                cout << "Número de Quartos: " << ((Apartamento *)*it)->getNumeroDeQuartos() << "\n";
                cout << "Valor do Condominio: " << ((Apartamento *)*it)->getValorDoCondominio() << "\n";
                cout << "Vagas de Garagem: " << ((Apartamento *)*it)->getVagasDeGaragem() << "\n";
                cout << "Área: " << ((Apartamento *)*it)->getArea() << "\n";
            }
        }
    }
   
    std::cout << "\t=========TERRENOS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Terrenos.
    {
        if((*it)->getTipo() == TIPO_TERRENO){

            if((maiusculo((*it)->getEndereco().getCidade())).find(maiusculo(buscar)) != string::npos )
            {
                std::cout << "\tTerreno " << ++t << "\n";
                cout << "Descrição: " << ((Terreno *)*it)->getDescricao() << "\n";
                cout << "Tipo de Oferta: " << ((Terreno *)*it)->getTipoOferta() << "\n";
                cout << "Valor: " << ((Terreno *)*it)->getValor() << "\n";
                cout << "Cidade: " << ((Terreno *)*it)->getEndereco().getCidade() << "\n";
                cout << "Bairro: " << ((Terreno *)*it)->getEndereco().getBairro() << "\n";
                cout << "CEP: " << ((Terreno *)*it)->getEndereco().getCEP() << "\n";
                cout << "Logradouro: " << ((Terreno *)*it)->getEndereco().getLogradouro() << "\n";
                cout << "Número: " << ((Terreno *)*it)->getEndereco().getNumero() << "\n";
                cout << "Área : " << ((Terreno *)*it)->getArea() << "\n";
            }
        }
    }

    std::cout << "\t=========CASAS=========\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if((*it)->getTipo() == TIPO_CASA){

            if((maiusculo((*it)->getEndereco().getCidade())).find(maiusculo(buscar)) != string::npos )
            {   
                std::cout << "\tCasa " << ++c << "\n";     
                cout << "Descrição: " << ((Casa *)*it)->getDescricao() << "\n";
                cout << "Tipo de Oferta: " << ((Casa *)*it)->getTipoOferta() << "\n";
                cout << "Valor: " << ((Casa *)*it)->getValor() << "\n";
                cout << "Cidade: " << ((Casa *)*it)->getEndereco().getCidade() << "\n";
                cout << "Bairro: " << ((Casa *)*it)->getEndereco().getBairro() << "\n";
                cout << "CEP: " << ((Casa *)*it)->getEndereco().getCEP() << "\n";
                cout << "Logradouro: " << ((Casa *)*it)->getEndereco().getLogradouro() << "\n";
                cout << "Número: " << ((Casa *)*it)->getEndereco().getNumero() << "\n";
                cout << "Número de Pavimentos: " << ((Casa *)*it)->getNumeroDePavimentos() << "\n";
                cout << "Número de Quartos: " << ((Casa *)*it)->getNumeroDeQuartos() << "\n";
                cout << "Área do Terreno: " << ((Casa *)*it)->getAreaDoTerreno() << "\n";
                cout << "Área Construída: " << ((Casa *)*it)->getAreaConstruida() << "\n";
            }
        }
    }

}

void LRY_IMO::buscarPorValor(){
    double buscar;

    cout << "Digite o valor que deseja procurar: ";
    cin >> buscar;

    std::vector<Imovel *>::iterator it;
    int a , t, c;
    a=t=c=0;

    std::cout << "\t=========APARTAMENTOS=========\n";
    cout << "\n\tApartamentos com valores MENORES ao desejado: \n\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo apartamentos.
    {
        if((*it)->getTipo() == TIPO_APARTAMENTO){
            
            if((*it)->getValor() < buscar)
            {
                std::cout << "\tApartamento " << ++a << "\n";
                cout << "Descrição: " << ((Apartamento *)*it)->getDescricao() << "\n";
                cout << "Tipo de Oferta: " << ((Apartamento *)*it)->getTipoOferta() << "\n";
                cout << "Valor: " << ((Apartamento *)*it)->getValor() << "\n";
                cout << "Cidade: " << ((Apartamento *)*it)->getEndereco().getCidade() << "\n";
                cout << "Bairro: " << ((Apartamento *)*it)->getEndereco().getBairro() << "\n";
                cout << "CEP: " << ((Apartamento *)*it)->getEndereco().getCEP() << "\n";
                cout << "Logradouro: " << ((Apartamento *)*it)->getEndereco().getLogradouro() << "\n";
                cout << "Número: " << ((Apartamento *)*it)->getEndereco().getNumero() << "\n";
                cout << "Posição: " << ((Apartamento *)*it)->getPosicao()<< "\n";
                cout << "Número de Quartos: " << ((Apartamento *)*it)->getNumeroDeQuartos() << "\n";
                cout << "Valor do Condominio: " << ((Apartamento *)*it)->getValorDoCondominio() << "\n";
                cout << "Vagas de Garagem: " << ((Apartamento *)*it)->getVagasDeGaragem() << "\n";
                cout << "Área: " << ((Apartamento *)*it)->getArea() << "\n";
            }
        }
    }
   
    std::cout << "\t=========TERRENOS=========\n";
    cout << "\n\tTerrenos com valores MENORES ao desejado: \n\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Terrenos.
    {
        if((*it)->getTipo() == TIPO_TERRENO){

            if((*it)->getValor() < buscar)
            {
                std::cout << "\tTerreno " << ++t << "\n";
                cout << "Descrição: " << ((Terreno *)*it)->getDescricao() << "\n";
                cout << "Tipo de Oferta: " << ((Terreno *)*it)->getTipoOferta() << "\n";
                cout << "Valor: " << ((Terreno *)*it)->getValor() << "\n";
                cout << "Cidade: " << ((Terreno *)*it)->getEndereco().getCidade() << "\n";
                cout << "Bairro: " << ((Terreno *)*it)->getEndereco().getBairro() << "\n";
                cout << "CEP: " << ((Terreno *)*it)->getEndereco().getCEP() << "\n";
                cout << "Logradouro: " << ((Terreno *)*it)->getEndereco().getLogradouro() << "\n";
                cout << "Número: " << ((Terreno *)*it)->getEndereco().getNumero() << "\n";
                cout << "Área : " << ((Terreno *)*it)->getArea() << "\n";
            }
        }
    }

    std::cout << "\t=========CASAS=========\n";
    cout << " \n\tCasas com valores MENORES ao desejado: \n\n";
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if((*it)->getTipo() == TIPO_CASA){

            if((*it)->getValor() < buscar)
            {   
                std::cout << "\tCasa " << ++c << "\n";     
                cout << "Descrição: " << ((Casa *)*it)->getDescricao() << "\n";
                cout << "Tipo de Oferta: " << ((Casa *)*it)->getTipoOferta() << "\n";
                cout << "Valor: " << ((Casa *)*it)->getValor() << "\n";
                cout << "Cidade: " << ((Casa *)*it)->getEndereco().getCidade() << "\n";
                cout << "Bairro: " << ((Casa *)*it)->getEndereco().getBairro() << "\n";
                cout << "CEP: " << ((Casa *)*it)->getEndereco().getCEP() << "\n";
                cout << "Logradouro: " << ((Casa *)*it)->getEndereco().getLogradouro() << "\n";
                cout << "Número: " << ((Casa *)*it)->getEndereco().getNumero() << "\n";
                cout << "Número de Pavimentos: " << ((Casa *)*it)->getNumeroDePavimentos() << "\n";
                cout << "Número de Quartos: " << ((Casa *)*it)->getNumeroDeQuartos() << "\n";
                cout << "Área do Terreno: " << ((Casa *)*it)->getAreaDoTerreno() << "\n";
                cout << "Área Construída: " << ((Casa *)*it)->getAreaConstruida() << "\n";
            }
        }
    }
}
void LRY_IMO::removerImovel(int tipoImovel){
    if(tipoImovel==1){
        listarApartamento();
    }
    if(tipoImovel==1){
        listarCasa();
    }
    if(tipoImovel==1){
        listarTerreno();
    }
    int numero;
    std::cout<<"Digite o número do imóvel que você deseja remover: ";
    std::cin>>numero;
    if(tipoImovel==1){
        listarApartamento();
    }
    if(tipoImovel==1){
        listarCasa();
    }
    if(tipoImovel==1){
        listarTerreno();
    }
}
