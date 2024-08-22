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
    };
}