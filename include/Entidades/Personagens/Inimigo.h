#pragma once

#include "Personagem.h"
#include "Jogador.h"

#include <cmath>

namespace Personagens
{
    class Inimigo : public Personagem
    {
        protected:
            sf::Clock relogio;
        public:
            Inimigo(float xx = 0, float yy = 0, float ww = 50.0, float hh = 50.0, Entidades::ID id = Entidades::vazio);
            virtual ~Inimigo();
            virtual void executar() = 0;
            virtual int getNumVidas() = 0;
            virtual void imprimir(Gerenciador::GerenciadorGrafico *gG) = 0;
            virtual void colide(Entidade *outraEntidade, sf::Vector2f intersecao) = 0;
            virtual void danificar(Personagens::Jogador* pontJogador) = 0;
    };
}
