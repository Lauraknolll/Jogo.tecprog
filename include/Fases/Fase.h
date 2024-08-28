#pragma once

#include <fstream>
#include <string>
#include "../Ente.h"
#include "../Gerenciador/GerenciadorColisoes.h"
#include "../Gerenciador/GerenciadorEventos.h"
#include "../Entidades/Personagens/Jogador.h"
#include "../Entidades/Personagens/InimigoFacil.h"
#include "../Entidades/Personagens/InimigoMedio.h"
#include "../Entidades/Obstaculos/Plataforma.h"
#include "../Entidades/Obstaculos/Lava.h"
#include "../Gerenciador/GerenciadorEventos.h"
#include "../json.hpp"

namespace Fases
{
    class Fase : public Ente
    {   
        protected:
            list<Entidades::Entidade*> ListaJogadores;
            list<Entidades::Entidade*> ListaObstaculos;
            vector<Entidades::Entidade*> ListaInimigos;
            Lista::ListaEntidade* Lista_Entidades;
            Gerenciador::GerenciadorColisoes* pGColisoes;
            Gerenciador::GerenciadorEvento* pEventos;
            Personagens::Jogador* jog1;
            Personagens::Jogador* jog2;
            nlohmann::json mapa; 
            //a fins de que o inimigo precisa conhecer o jogador, mas tem que pensar num jeito melhor
           
        public:
            Fase();
            ~Fase();
            void criarJogadores(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarInimigosFaceis(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarInimigosMedios(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarPLataformas(sf::Vector2f posicao, sf::Vector2f tamanho);
            void cria();
            void executar();
            void carregarMapa(std::string mapJson);
            void criarMapa(std::string caminho_mapa);
    };
}