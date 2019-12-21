#include <iostream>
#include "Apartamento.h"

using namespace std;

int main()
{
    tEndereco end;
    end.bairro = "Bairro 778";
    end.CEP = "778";
    end.cidade = "KDMNNT";
    end.logradouro = "Rua dos tolos";
    end.numero = 0;
    Apartamento *ap = new Apartamento("Apzinho", 1, 250000, end, "nascente norte", 
    2, 600, 1,200);


    cout<<"ANUNCIO:\n\n";
    cout<<"\tDescricao: "<<ap->getDescricao()<<endl;
    cout<<"\tTipo de oferta: "<<((ap->getTipoOferta() == 1) ? "venda\n" : "aluguel\n");
    cout<<"\tPreco: "<<ap->getValor()<<endl;
    cout<<"\tEndereco:\n";
    cout<<"\t\tCidade: "<<end.cidade<<endl;
    cout<<"\t\tBairro: "<<end.bairro<<endl;
    cout<<"\t\tCEP: "<<end.CEP<<endl;
    cout<<"\t\tLogradouro: "<<end.logradouro<<endl;
    cout<<"\t\tNumero: "<<end.numero<<endl;
    cout<<"\tPosicao: "<<ap->getPosicao()<<endl;
    cout<<"\tNumero de quartos: "<<ap->getNumeroDeQuartos()<<endl;
    cout<<"\tValor do condominio: "<<ap->getValorDoCondominio()<<endl;
    cout<<"\tNumero de vagas de garagem: "<<ap->getVagasDeGaragem()<<endl;
    cout<<"\tArea: "<<ap->getArea()<<endl;


    return 0;
}