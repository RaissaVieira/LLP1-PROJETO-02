#include "../Headers/LRY_IMO.h"
#include <iostream>
#include <fstream>

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
    lerApartamentosSalvos();
    lerCasasSalvas();
    lerTerrenosSalvos();
}

void LRY_IMO::salvarCasas()
{
    ofstream casas("./Arquivos/Casas.txt");
    vector<Imovel *>::iterator it;
    int contaCasas = 0;
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if((*it)->getTipo() == TIPO_CASA)
        {        
            if(contaCasas > 0)//Evita que se pule a primeira linha do arquivo
            {
                casas << "\n"; //Isto aqui serve para pular linha entre o fim dos dados de uma casa e o começo dos dados de outra.
            } 
            casas << ((Casa *)*it)->getDescricao() << "\n";
            casas << ((Casa *)*it)->getTipoOferta() << "\n";
            casas << ((Casa *)*it)->getValor() << "\n";
            casas << ((Casa *)*it)->getEndereco().getCidade() << "\n";
            casas << ((Casa *)*it)->getEndereco().getBairro() << "\n";
            casas << ((Casa *)*it)->getEndereco().getCEP() << "\n";
            casas << ((Casa *)*it)->getEndereco().getLogradouro() << "\n";
            casas << ((Casa *)*it)->getEndereco().getNumero() << "\n";
            casas << ((Casa *)*it)->getNumeroDePavimentos() << "\n";
            casas << ((Casa *)*it)->getNumeroDeQuartos() << "\n";
            casas << ((Casa *)*it)->getAreaDoTerreno() << "\n";
            casas << ((Casa *)*it)->getAreaConstruida();
            contaCasas++;
        }
    }
    casas.close();
}

void LRY_IMO::salvarApartamentos()
{
    ofstream apartamentos("./Arquivos/Apartamentos.txt");
    vector<Imovel *>::iterator it;
    int contaApartamentos = 0;
    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if((*it)->getTipo() == TIPO_APARTAMENTO)
        {        
            if(contaApartamentos > 0)
            {
                apartamentos << "\n";//Procedimento análogo ao que ocorre no método salvarCasas().
            }
            apartamentos << ((Apartamento *)*it)->getDescricao() << "\n";
            apartamentos << ((Apartamento *)*it)->getTipoOferta() << "\n";
            apartamentos << ((Apartamento *)*it)->getValor() << "\n";
            apartamentos << ((Apartamento *)*it)->getEndereco().getCidade() << "\n";
            apartamentos << ((Apartamento *)*it)->getEndereco().getBairro() << "\n";
            apartamentos << ((Apartamento *)*it)->getEndereco().getCEP() << "\n";
            apartamentos << ((Apartamento *)*it)->getEndereco().getLogradouro() << "\n";
            apartamentos << ((Apartamento *)*it)->getEndereco().getNumero() << "\n";
            apartamentos << ((Apartamento *)*it)->getPosicao()<< "\n";
            apartamentos << ((Apartamento *)*it)->getNumeroDeQuartos() << "\n";
            apartamentos << ((Apartamento *)*it)->getValorDoCondominio() << "\n";
            apartamentos << ((Apartamento *)*it)->getVagasDeGaragem() << "\n";
            apartamentos << ((Apartamento *)*it)->getArea();
            contaApartamentos++;
        }
    }
    apartamentos.close();
}

void LRY_IMO::salvarTerrenos()
{
    ofstream terrenos("./Arquivos/Terrenos.txt");
    vector<Imovel *>::iterator it;
    int contaTerrenos = 0;

    for(it = this->imoveis.begin(); it < imoveis.end(); it++)//Exibindo Casas.
    {
        if((*it)->getTipo() == TIPO_TERRENO)
        {        
            if(contaTerrenos > 0){
                terrenos << "\n"; //Procedimento análogo ao que ocorre no método salvarCasas().
            }  
            terrenos << ((Terreno *)*it)->getDescricao() << "\n";
            terrenos << ((Terreno *)*it)->getTipoOferta() << "\n";
            terrenos << ((Terreno *)*it)->getValor() << "\n";
            terrenos << ((Terreno *)*it)->getEndereco().getCidade() << "\n";
            terrenos << ((Terreno *)*it)->getEndereco().getBairro() << "\n";
            terrenos << ((Terreno *)*it)->getEndereco().getCEP() << "\n";
            terrenos << ((Terreno *)*it)->getEndereco().getLogradouro() << "\n";
            terrenos << ((Terreno *)*it)->getEndereco().getNumero() << "\n";
            terrenos << ((Terreno *)*it)->getArea();
            contaTerrenos++;
        }
    }
    terrenos.close();
}

void LRY_IMO::salvarImoveis()
{
    salvarApartamentos();
    salvarCasas();
    salvarTerrenos();
}

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

void LRY_IMO::listarCasa(int tipoOferta){
    
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
    listarCasa();
    listarTerreno();
    listarApartamento();
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


/*
    GALERA, OS MÉTODOS TOSTRING E GETIMOVEIS NÃO FAZEM A MESMA COISA NÃO?
    PS.: Quando eu testo o toString não funciona...
    Aí eu pensei em complementar o GetImoveis com mais informações, deixei toString comentado.

    --Realmente.
*/

