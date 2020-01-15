#ifndef LRY_IMO_H
#define LRY_IMO_H

#include "../Headers/Apartamento.h"
#include "../Headers/Terreno.h"
#include "../Headers/Casa.h"
#include <vector>
#include <string>
#include <locale>
#include <iostream>

#define VENDA 1
#define ALUGUEL 2
#define VENDA_OU_ALUGUEL 3


class LRY_IMO{ //CRUD imobiliária
private:
    std::vector<Imovel *>imoveis;
public:
    void cadastrarApartamento();
    void cadastrarTerreno();
    void cadastrarCasa(); 
    void getImoveis(); //Lista todos os terrenos, casas e apartamentos
    void listarTipoAluguel();
    void listarTipoVenda();
    void lerCasasSalvas();
    void lerApartamentosSalvos();
    void lerTerrenosSalvos();
    void lerImoveisSalvos();
    void salvarApartamentos();
    void salvarCasas();
    void salvarTerrenos();
    void salvarImoveis();
    void removerImovel(int tipoImovel);


    string maiusculo(std::string frase);
    string toString();
    string getCasas(int tipoOferta = VENDA_OU_ALUGUEL);
    string getTerrenos(int tipoOferta = VENDA_OU_ALUGUEL);
    string getApartamentos(int tipoOferta = VENDA_OU_ALUGUEL);
    string LRY_IMO::buscarPorBairro(string buscar)
    string buscarPorCidade();
    string buscarPorValor();
    string buscarPorDescricao();
};

#endif