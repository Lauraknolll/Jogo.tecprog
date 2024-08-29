#pragma once
#include "../Entidade.h"
#include <stdlib.h>

namespace Personagens
{
    class Personagem : public Entidades::Entidade
    {
    protected:
        int num_vidas;

    public:
        Personagem(float xx = 0, float yy = 0, float ww = 50.0, float hh = 50.0, Entidades::ID id = Entidades::vazio);

        virtual ~Personagem();

        virtual int getNumVidas() = 0;

        virtual void executar() = 0;

        virtual void imprimir(Gerenciador::GerenciadorGrafico *gG) = 0;
        
        virtual void colide(Entidade *outraEntidade, sf::Vector2f intersecao) = 0; 
    };
}
