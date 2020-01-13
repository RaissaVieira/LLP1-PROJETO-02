#include "../Headers/LRY_IMO.h"
#include <sstream>
#include <stdio.h>

using namespace std;

LRY_IMO imobiliaria;

extern void MenuPrincipal();

void novaOperacao(){
    printf("\e[H\e[2J"); 
    string opcao;

    cout << "Deseja realizar uma nova operacao?\n";
    cout << "\t1-SIM\n";
    cout << "\t1-NAO\n";
    cout<<"\tDigite a operação que deseja ser realizada: ";
    cin>>opcao;
    cin.ignore();

    stringstream op (opcao);
    int escolha = 0;
    op>>escolha;

    switch (escolha)
    {
    case 0:
        printf("\e[H\e[2J"); 
        novaOperacao();
        break;
    case 1:
        printf("\e[H\e[2J"); 
        MenuPrincipal();
        break;
    case 2:
        break;
    default:
        novaOperacao();
    }

}

void MenuCadastro (){
    printf("\e[H\e[2J"); 
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
        printf("\e[H\e[2J"); 
        MenuCadastro();
        break;
    case 1:
        printf("\e[H\e[2J"); 
        imobiliaria.cadastrarCasa();
        novaOperacao();
        break;
    case 2:
        printf("\e[H\e[2J"); 
        imobiliaria.cadastrarApartamento();
        novaOperacao();
        break;
    case 3:
        printf("\e[H\e[2J"); 
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

void MenuListar (){
    printf("\e[H\e[2J"); 
    string opcao;
    cout<<"LRY Imobiliária"<<endl;
    cout<<"LISTAR"<<endl;
    cout<<"\t1-Listar Casa"<<endl;
    cout<<"\t2-Listar Apartamento"<<endl;
    cout<<"\t3-Listar Terreno"<<endl;
    cout<<"\t4-Listar todos os imoveis"<<endl;
    cout<<"\t5-Voltar"<<endl;
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
        printf("\e[H\e[2J"); 
        imobiliaria.getCasas();
        break;
    case 2:
        printf("\e[H\e[2J"); 
        imobiliaria.getApartamentos();
        break;
    case 3:
        printf("\e[H\e[2J"); 
        imobiliaria.getTerrenos();
        break;
    case 4:
        imobiliaria.getImoveis();
        break;
    case 5: 
        MenuPrincipal();
        break;
    default:
        MenuListar();
    }
    novaOperacao();
}

void MenuBuscar (){
    printf("\e[H\e[2J"); 
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

    switch (escolha)
    {
    case 0:
        MenuBuscar();
        break;
    case 1:
        printf("\e[H\e[2J"); 
        imobiliaria.buscarPorBairro();
        novaOperacao();
        break;
    case 2:
        printf("\e[H\e[2J"); 
        imobiliaria.buscarPorCidade();
        novaOperacao();
        break;
    case 3:
        printf("\e[H\e[2J"); 
        imobiliaria.buscarPorValor();
        novaOperacao();
        break;
    case 4:
        printf("\e[H\e[2J"); 
        imobiliaria.buscarPorDescricao();
        novaOperacao();
    case 5: 
        printf("\e[H\e[2J"); 
        MenuPrincipal();
        break;
    default:
        MenuBuscar();
    }
    novaOperacao();
}

void MenuRemover (){
    printf("\e[H\e[2J"); 
    string opcao;
    cout<<"LRY Imobiliária"<<endl;
    cout<<"REMOVER"<<endl;
    cout<<"\t1-Remover Casa"<<endl;
    cout<<"\t2-Remover Apartamento"<<endl;
    cout<<"\t3-Remover Terreno"<<endl;
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
        MenuRemover();
        break;
    case 1:
        printf("\e[H\e[2J"); 
        imobiliaria.removerImovel(2);
        break;
    case 2:
        printf("\e[H\e[2J"); 
        imobiliaria.removerImovel(1);
        break;
    case 3:
        printf("\e[H\e[2J"); 
        imobiliaria.removerImovel(3);
        break;
    case 4: 
        printf("\e[H\e[2J"); 
        MenuPrincipal();
        break;
    default:
        MenuRemover();
    }
    novaOperacao();
}

void MenuPrincipal(){
    printf("\e[H\e[2J"); 
    string opcao;
    cout<<"LRY Imobiliária"<<endl;
    cout<<"\t1-Cadastro"<<endl;
    cout<<"\t2-Listar"<<endl;
    cout<<"\t3-Buscar"<<endl;
    cout<<"\t4-Remover"<<endl;
    cout<<"\t5-Editar"<<endl;
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
        MenuBuscar();
        break;
    case 4: 
        MenuRemover();
        break;
    case 5:
        cout<<"Editar"<<endl;
        break;
    case 6:
        break;
    default:
        MenuPrincipal();
    }
}
int main (void){
    setlocale(LC_ALL,"portuguese");
    MenuPrincipal();
}
