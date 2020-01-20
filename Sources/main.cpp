#include "../Headers/LRY_IMO.h"
#include <sstream>
#include <stdio.h>

using namespace std;

LRY_IMO imobiliaria;
std::string lista;

void limpa_tela()
{
    #ifdef __unix__
        system("clear");
    #elif WIN32
        system("cls");
    #endif
    
    //printf("\e[H\e[2J");
}

extern int MenuPrincipal();

void SalvarArquivo()
{

    string opcao;

    cout << "Deseja salvar as alterações no arquivo Imoveis.txt?\n";
    cout << "\t1-SIM\n";
    cout << "\t2-NAO\n";
    cout<<"\tDigite a operação que deseja ser realizada: ";
    cin>>opcao;
    cin.ignore();

    stringstream op (opcao);
    int escolha = 0;
    op>>escolha;

    switch (escolha)
    {
    case 0:
        limpa_tela();
        SalvarArquivo();
        break;
    case 1:
        imobiliaria.salvarImoveis();
        break;
    case 2:
        break;
    default:
        limpa_tela();
        SalvarArquivo();
    }

}

void novaOperacao()
{
    cout << "\n __________________________________________\n";
    string opcao;

    cout << "Deseja realizar uma nova operacao?\n";
    cout << "\t1-SIM\n";
    cout << "\t2-NAO\n";
    cout<<"\tDigite a operação que deseja ser realizada: ";
    cin>>opcao;
    cin.ignore();

    stringstream op (opcao);
    int escolha = 0;
    op>>escolha;

    switch (escolha)
    {
    case 0:
        limpa_tela();
        novaOperacao();
        break;
    case 1:
        limpa_tela();
        MenuPrincipal();
        break;
    case 2:
        limpa_tela();
        SalvarArquivo();
        break;
    default:
        limpa_tela();
        novaOperacao();
    }
    //novaOperacao();

}

void MenuCadastro ()
{
    limpa_tela();
    string opcao;
    cout<<"LRY Imobiliária"<<endl;
    cout<<"CADASTRO"<<endl;
    cout<<"\t1-Cadastrar Casa"<<endl;
    cout<<"\t2-Cadastrar Apartamento"<<endl;
    cout<<"\t3-Cadastrar Terreno"<<endl;
    cout<<"\t4-Voltar"<<endl;
    cout<<"\tDigite a operação que deseja ser realizada: ";
    cin>>opcao;
    cin.ignore();

    stringstream op (opcao);
    int escolha = 0;
    op>>escolha;

    switch (escolha)
    {
    case 0:
        limpa_tela();
        MenuCadastro();
        break;
    case 1:
        limpa_tela();
        imobiliaria.cadastrarCasa();
        novaOperacao();
        break;
    case 2:
        limpa_tela();
        imobiliaria.cadastrarApartamento();
        novaOperacao();
        break;
    case 3:
        limpa_tela();
        imobiliaria.cadastrarTerreno();
        novaOperacao();
        break;
    case 4: 
        MenuPrincipal();
        break;
    default:
        MenuCadastro();
    }
    novaOperacao();
}
void MenuEditar ()
{
    imobiliaria.editarImoveis();
    novaOperacao();
}

void MenuListar ()
{

    limpa_tela();
    string opcao;
    cout<<"LRY Imobiliária"<<endl;
    cout<<"LISTAR"<<endl;
    cout<<"\t1-Listar Casa"<<endl;
    cout<<"\t2-Listar Apartamento"<<endl;
    cout<<"\t3-Listar Terreno"<<endl;
    cout<<"\t4-Listar os imoveis para aluguel"<<endl;
    cout<<"\t5-Listar os imoveis para venda"<<endl;
    cout<<"\t6-Listar todos os imoveis"<<endl;
    cout<<"\t7-Voltar"<<endl;
    cout<<"\tDigite a operação que deseja ser realizada: ";
    cin>>opcao;
    cin.ignore();

    stringstream op (opcao);
    int escolha = 0;
    op>>escolha;

    switch (escolha)
    {
    case 0:
        MenuListar();
        break;
    case 1:
        limpa_tela();
        std::cout<<imobiliaria.getCasas();
        break;
    case 2:
        limpa_tela();
        std::cout<<imobiliaria.getApartamentos();
        break;
    case 3:
        limpa_tela();
        std::cout<<imobiliaria.getTerrenos();
        break;
    case 4:
        limpa_tela();
        imobiliaria.listarTipoAluguel();
        break;
    case 5:
        limpa_tela();
        imobiliaria.listarTipoVenda();
        break;
    case 6:
        limpa_tela();
        imobiliaria.getImoveis();
        break;
    case 7: 
        MenuPrincipal();
        break;
    default:
        MenuListar();
    }
    novaOperacao();
}

void MenuRemover (std::string lista)
{
    imobiliaria.removerImovel(lista);
    novaOperacao();
}

void MenuBuscar (int buscar)
{
    limpa_tela();
    string opcao;
    cout<<"LRY Imobiliária"<<endl;
    cout<<"BUSCAR"<<endl;
    cout<<"\t1-Buscar por bairro"<<endl;
    cout<<"\t2-Buscar por cidade"<<endl;
    cout<<"\t3-Buscar por valor"<<endl;
    cout<<"\t4-Buscar por descricao"<<endl;
    cout<<"\t5-Voltar"<<endl;
    cout<<"\tDigite a operação que deseja ser realizada: ";
    cin>>opcao;
    cin.ignore();

    stringstream op (opcao);
    int escolha = 0;
    op>>escolha; 
    //std::string lista;

    switch (escolha)
    {
    case 0:
        MenuBuscar(3);
        break;
    case 1:
        limpa_tela();
        lista=imobiliaria.buscarPorBairro();
        cout<<lista;
        //MenuRemoverA(lista);
        break;
    case 2:
        limpa_tela();
        lista=imobiliaria.buscarPorCidade();
        cout<<lista;
        //MenuRemoverA(lista);
        break;
    case 3:
        limpa_tela();
        lista=imobiliaria.buscarPorValor();
        cout<<lista;
        //MenuRemoverA(lista);
        break;
    case 4:
        limpa_tela();
        lista=imobiliaria.buscarPorDescricao();
        cout<<lista;
        break;
        //MenuRemoverA(lista);
    case 5: 
        limpa_tela();
        MenuPrincipal();
        break;
    default:
        MenuBuscar(3);
    }

    if(buscar != 5)
        novaOperacao();
}

int MenuPrincipal()
{   
    int buscar;
    
    limpa_tela();
    string opcao;
    cout<<"LRY Imobiliária"<<endl;
    cout<<"\t1-Cadastro"<<endl;
    cout<<"\t2-Listar"<<endl;
    cout<<"\t3-Buscar"<<endl;
    cout<<"\t4-Editar"<<endl;
    cout<<"\t5-Remover"<<endl;
    cout<<"\t6-Sair"<<endl;
    cout<<"\tDigite a operação que deseja ser realizada: ";
    cin>>opcao;
    cin.ignore();

    stringstream op (opcao);
    int escolha = 0;
    op>>escolha;

    switch (escolha)
    {
    case 0:
        MenuPrincipal();
        break;
    case 1:
        MenuCadastro();
        break;
    case 2:
        MenuListar();
        break;
    case 3:
        MenuBuscar(3);
        break;
    case 4:
        MenuBuscar(5);
        MenuEditar();
        break;
    case 5: 
        MenuBuscar(5);
        MenuRemover(lista);
        break;
    case 6:
        return 0;
    default:
        MenuPrincipal();
    }
}

int main (void)
{
    imobiliaria.lerImoveisSalvos();
    setlocale(LC_ALL,"portuguese");

    MenuPrincipal();
}

