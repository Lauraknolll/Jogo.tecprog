#pragma once

#include "Personagem.h"

#include <cmath>

namespace Personagens
{
    class Inimigo : public Personagem
    {
        protected:
            sf::Clock relogio;
        public:
            Inimigo();
            ~Inimigo();
            virtual void executar() = 0;
            virtual void imprimir(Gerenciador::GerenciadorGrafico *gG) = 0;
            virtual void colide(Entidade *outraEntidade, sf::Vector2f intersecao) = 0;
    };
}
