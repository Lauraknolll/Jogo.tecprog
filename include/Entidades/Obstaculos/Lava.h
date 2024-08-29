#pragma once

#include "Obstaculo.h"

namespace Obstaculos
{
    class Lava : public Obstaculo
    {
    private:
        int danosidade;
        
    public:
        Lava(float x = 0.f, float y = 0.f, float ww = 100.f, float hh = 100.f);

        ~Lava();

        void executar();

        void atualizarPosicao();

        void imprimir(Gerenciador::GerenciadorGrafico *gG);

        void colide(Entidade *outraEntidade, sf::Vector2f intersecao);

        void obstacular(Personagens::Jogador* pontJogador);
        
        unsigned int tomarDano() const;
    };
}