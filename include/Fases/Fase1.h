#pragma once

#include "Fase.h"

namespace Fases
{
    class Fase1 : public Fase
    {
        private:
            list<Entidades::Entidade*> ListaObstaculosFase1;
            vector<Entidades::Entidade*> ListaInimigosFase1;

            nlohmann::json mapa;
        public:
            Fase1();
            ~Fase1();
            void criarInimigosFaceis(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarObstaculosFaceis(sf::Vector2f posicao, sf::Vector2f tamanho);
            void carregarMapa(std::string mapJson);
    };
}