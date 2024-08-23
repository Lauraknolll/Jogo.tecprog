#pragma once
#include "../Entidade.h"

namespace Personagens
{
    class Personagem : public Entidades::Entidade
    {
    protected:
        int num_vidas;

    public:
        Personagem();
        ~Personagem();
        virtual void executar() = 0;
        virtual void imprimir(Gerenciador::GerenciadorGrafico *gG) = 0;
        virtual void colide(Entidade *outraEntidade, CoordF intersecao) = 0; 
    };
}