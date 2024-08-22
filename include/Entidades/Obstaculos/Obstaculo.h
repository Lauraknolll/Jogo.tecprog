#pragma once

#include "../Entidade.h"
#include "../../Colisao.h"
#include "../../Gerenciador/GerenciadorGrafico.h"
#include "../../CoordTl.h"

namespace Obstaculos
{
    class Obstaculo : public Entidades::Entidade
    {
    protected:
    public:
        Obstaculo(float x = 0.f, float y = 0.f, float ww = 100.f, float hh = 100.f);
        ~Obstaculo();

        virtual void executar();
        virtual void imprimir(Gerenciador::GerenciadorGrafico *gG);
        virtual int const getTipo() const;
        virtual void colide(Entidade *outraEntidade, CoordF intercesao) {}
        // virtual void obstacular(Personagem* pP, int dir) = 0;
    };
}
