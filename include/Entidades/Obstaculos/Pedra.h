#pragma once

#include "Obstaculo.h"

namespace Obstaculos
{
    class Pedra : public Obstaculo
    {
        private:
            int dureza;
        public:
            Pedra(float x = 0.f, float y = 0.f, float ww = 50.f, float hh = 50.f);
            ~Pedra();
            void executar();
            void atualizarPosicao();
            void imprimir(Gerenciador::GerenciadorGrafico *gG);
            void colide(Entidade *outraEntidade, sf::Vector2f intersecao);
            void obstacular(Personagens::Jogador *pontJogador);
    };
}