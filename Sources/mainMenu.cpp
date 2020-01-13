#include "../Headers/LRY_IMO.h"
#include <sstream>

using namespace std;

extern void MenuPrincipal();

void MenuCadastro (){
    string opcao;
    cout<<"------------------LRY Imobiliária------------"<<endl;
    cout<<"\tCadastro"<<endl;
    cout<<"\t1-Cadastrar Casa"<<endl;
    cout<<"\t2-Cadastrar Apartamento"<<endl;
    cout<<"\t3-Cadastrar Terreno"<<endl;
    cout<<"\t4-Voltar"<<endl;
    cout<<"\tDigite a operação que deseja ser realizada: ";
    cin>>opcao;

    stringstream op (opcao);
    int escolha = 0;
    op>>escolha;

    switch (escolha)
    {
    case 0:
        MenuCadastro();
        break;
    case 1:
        
        break;
    case 2:
        cout<<"Listar"<<endl;
        break;
    case 3:
        cout<<"Buscar"<<endl;
        break;
    case 4: 
        MenuPrincipal();
        break;
    }
}
int MenuPrincipal(){
    string opcao;
    cout<<"------------------LRY Imobiliária------------"<<endl;
    cout<<"\t1-Cadastro"<<endl;
    cout<<"\ts2-Listar"<<endl;
    cout<<"\t3-Buscar"<<endl;
    cout<<"\t4-Remover"<<endl;
    cout<<"\t5-Editar"<<endl;
    cout<<"\t6-Sair"<<endl;
    cout<<"\tDigite a operação que deseja ser realizada: ";
    cin>>opcao;

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
        cout<<"Listar"<<endl;
        break;
    case 3:
        cout<<"Buscar"<<endl;
        break;
    case 4: 
        cout<<"Remover"<<endl;
        break;
    case 5:
        cout<<"Editar"<<endl;
        break;
    case 6:
        break;
    }
}
int main (void){
    setlocale(LC_ALL,"portuguese");
    LRY_IMO *imobiliaria = new LRY_IMO();
    MenuPrincipal();
}
