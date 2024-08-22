#pragma once

#include "Inimigo.h"
#include "Jogador.h"

#define RAIO_PERSEGUIR_X 200.0f

namespace Personagens
{
    class InimigoMedio : public Inimigo
    {
        private:
            Jogador* jogador;
        public:
            InimigoMedio();
            ~InimigoMedio();
            void setJogador(Jogador* pJ);
            void executar();
            void persegueJogador(sf::Vector2f posJog, sf::Vector2f posIni);
            const sf::RectangleShape getCorpo();
    };
}