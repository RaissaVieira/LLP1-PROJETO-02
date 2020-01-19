#include "../Headers/LRY_IMO.h"
#include <sstream>
#include <stdio.h>

using namespace std;

LRY_IMO imobiliaria;
std::string lista;


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
        printf("\e[H\e[2J"); 
        SalvarArquivo();
        break;
    case 1:
        imobiliaria.salvarImoveis();
        break;
    case 2:
        break;
    default:
        printf("\e[H\e[2J"); 
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
        printf("\e[H\e[2J"); 
        novaOperacao();
        break;
    case 1:
        printf("\e[H\e[2J"); 
        MenuPrincipal();
        break;
    case 2:
        printf("\e[H\e[2J");
        SalvarArquivo();
        break;
    default:
        printf("\e[H\e[2J"); 
        novaOperacao();
    }
    //novaOperacao();

}

void MenuCadastro ()
{
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
void MenuEditar ()
{
    printf("\e[H\e[2J"); 
    string opcao;
    cout<<"LRY Imobiliária"<<endl;
    cout<<"CADASTRO"<<endl;
    cout<<"\t1-Editar Casa"<<endl;
    cout<<"\t2-Editar Apartamento"<<endl;
    cout<<"\t3-Editar Terreno"<<endl;
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
        imobiliaria.editarImoveis(2);
        novaOperacao();
        break;
    case 2:
        printf("\e[H\e[2J"); 
        imobiliaria.editarImoveis(1);
        novaOperacao();
        break;
    case 3:
        printf("\e[H\e[2J"); 
        imobiliaria.editarImoveis(3);
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

void MenuListar ()
{

    printf("\e[H\e[2J"); 
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
        printf("\e[H\e[2J"); 
        std::cout<<imobiliaria.getCasas(3);
        break;
    case 2:
        printf("\e[H\e[2J"); 
        std::cout<<imobiliaria.getApartamentos(3);
        break;
    case 3:
        printf("\e[H\e[2J"); 
        std::cout<<imobiliaria.getTerrenos(3);
        break;
    case 4:
        printf("\e[H\e[2J"); 
        imobiliaria.listarTipoAluguel();
        break;
    case 5:
        printf("\e[H\e[2J"); 
        imobiliaria.listarTipoVenda();
        break;
    case 6:
        printf("\e[H\e[2J"); 
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
    //std::string lista;

    switch (escolha)
    {
    case 0:
        MenuBuscar(3);
        break;
    case 1:
        printf("\e[H\e[2J");
        lista=imobiliaria.buscarPorBairro();
        cout<<lista;
        //MenuRemoverA(lista);
        break;
    case 2:
        printf("\e[H\e[2J");
        lista=imobiliaria.buscarPorCidade();
        cout<<lista;
        //MenuRemoverA(lista);
        break;
    case 3:
        printf("\e[H\e[2J"); 
        lista=imobiliaria.buscarPorValor();
        cout<<lista;
        //MenuRemoverA(lista);
        break;
    case 4:
        printf("\e[H\e[2J"); 
        lista=imobiliaria.buscarPorDescricao();
        cout<<lista;
        //MenuRemoverA(lista);
    case 5: 
        printf("\e[H\e[2J"); 
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
    
    printf("\e[H\e[2J"); 
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

