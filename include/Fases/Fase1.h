#pragma once

#include "Fase.h"

namespace Fases
{
    class Fase1 : public Fase
    {
        private:
            bool temDoisJogadores;

            Gerenciador::GerenciadorColisoes* pGColisoes;
            Gerenciador::GerenciadorEvento* pGEventos;

            list<Entidades::Entidade*> ListaJogadoresFase1;
            list<Entidades::Entidade*> ListaObstaculosFase1;
            vector<Entidades::Entidade*> ListaInimigosFase1;

            Lista::ListaEntidade* Lista_Entidades;

            nlohmann::json mapa;
        public:
            Fase1();
            ~Fase1();
            void executar();
            void cria();

            void criarJogadores(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarPlataformas(sf::Vector2f posicao, sf::Vector2f tamanho);

            void criarInimigosFaceis(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarObstaculosFaceis(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarInimigosMedios(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarObstaculosMedios(sf::Vector2f posicao, sf::Vector2f tamanho);

            void carregarMapa(std::string mapJson);
            void criarMapa(std::string caminho_mapa);
    };
}