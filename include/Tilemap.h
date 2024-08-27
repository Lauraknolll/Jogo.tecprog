#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "json.hpp"
#include <vector>
#include <fstream>
#include <string>
#include "Gerenciador/GerenciadorGrafico.h"
#include "Gerenciador/GerenciadorEventos.h"
#include "Entidades/Entidade.h"
#include "Listas/ListaEntidade.h"


/*
    Classe Tilemap
    - Classe responsável por carregar o mapa do jogo
    - Cria as entidades do jogo
    - Cria o mapa do jogo

    LEIA OS COMENTARIOS DO .CPP E AJUSTE NO SEU CÓDIGO

*/

class Entidade;

class Tilemap{
    private:
        nlohmann::json mapa; // mapa.json  
        Gerenciador::GerenciadorGrafico* textura_mapa;
        Gerenciador::GerenciadorEvento* pGEvento; 

    public:
        Tilemap(std::string mapJson, std::string caminhoImagem = "");
        ~Tilemap();

        void carregarMapa(std::string mapJson, std::string caminhoImagem);
        Entidades::Entidade* criarEntidade (sf::Vector2f posicao, sf::Vector2f tamanho, int tipo);
        void criarMapa(Lista::ListaEntidade* jogador, Lista::ListaEntidade* inimigo, Lista::ListaEntidade* obstaculo/*, sf::Texture* textura_mapa*/);
};