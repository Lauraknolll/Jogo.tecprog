#pragma once

#include "Obstaculo.h"

namespace Obstaculos
{
    class Lava : public Obstaculo
    {
    private:
    public:
        Lava(float x = 0.f, float y = 0.f);
        ~Lava();
        void imprimir(Gerenciador::GerenciadorGrafico *gG);
        unsigned int tomarDano() const;
    };
}