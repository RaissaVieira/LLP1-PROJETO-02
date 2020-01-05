#ifndef LRY_IMO_H
#define LRY_IMO_H

#include "../Headers/Apartamento.h"
#include "../Headers/Terreno.h"
#include "../Headers/Casa.h"
#include <vector>

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
    void listarCasa(int tipoOferta = VENDA_OU_ALUGUEL);
    void listarTerreno(int tipoOferta = VENDA_OU_ALUGUEL);
    void listarApartamento(int tipoOferta = VENDA_OU_ALUGUEL);
    void listarTipoAluguel();
    void listarTipoVenda();
    void lerCasasSalvas();
    void lerApartamentosSalvos();
    void lerTerrenosSalvos();

    std::string toString();

};

#endif