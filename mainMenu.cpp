#include "LRY_IMO.h"
#include <iostream>
#include <string>

using namespace std;

int MenuPrincipal(){
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

    int escolha = stoi(opcao);

    switch (escolha)
    {
    case 0:
        MenuPrincipal();
        break;
    case 1:
        cout<<"Cadastro"<<endl;
    case 2:
        cout<<"Listar"<<endl;
    case 3:
        cout<<"Buscar"<<endl;
    case 4: 
        cout<<"Remover"<<endl;
    case 5:
        cout<<"Editar"<<endl;
    case 6:
        return 0;

    }

    
}
int main (void){
    setlocale(LC_ALL,"portuguese");
    MenuPrincipal();
}