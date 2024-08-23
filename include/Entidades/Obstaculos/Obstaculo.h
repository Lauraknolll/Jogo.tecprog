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
        Obstaculo(float xxx = 0.f, float y = 0.f, float ww = 100.f, float hh = 100.f, Entidades::ID id = Entidades::vazio);
        ~Obstaculo();

        virtual void executar();
        virtual void imprimir(Gerenciador::GerenciadorGrafico *gG) = 0;
        virtual int const getTipo() const;
        virtual void colide(Entidade *outraEntidade, sf::Vector2f intersecao) {}
        // virtual void obstacular(Personagem* pP, int dir) = 0;
    };
}
