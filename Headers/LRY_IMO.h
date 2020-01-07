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
    void listarCasaPorTipo(int tipoOferta = VENDA_OU_ALUGUEL);
    void listarTerrenoPorTipo(int tipoOferta = VENDA_OU_ALUGUEL);
    void listarApartamentoPorTipo(int tipoOferta = VENDA_OU_ALUGUEL);
    void listarCasa();
    void listarTerreno();
    void listarApartamento();
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
    std::string maiusculo(std::string frase);
    void buscarPorBairro(std::string bairro);
    void removerImovel();


    std::string toString();
};

#endif