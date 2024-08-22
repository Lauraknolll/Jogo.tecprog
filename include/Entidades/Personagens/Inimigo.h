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
            virtual void colide(Entidade *outraEntidade, CoordF intersepta) = 0;
    };
}
