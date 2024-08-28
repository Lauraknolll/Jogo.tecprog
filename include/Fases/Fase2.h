#pragma once

#include "Fase.h"

namespace Fases
{
    class Fase2 : public Fase
    {
        private:
        public:
            Fase2();
            ~Fase2();
            void criarInimigosDificeis(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarObstaculosDificeis(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarInimigosMedios(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarObstaculosMedios(sf::Vector2f posicao, sf::Vector2f tamanho);
    };
}