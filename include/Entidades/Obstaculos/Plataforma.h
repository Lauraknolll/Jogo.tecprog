#pragma once

#include "Obstaculo.h"
#include "../Personagens/Personagem.h"

namespace Obstaculos
{
    class Plataforma : public Obstaculo
    {
        private:
        public:
            Plataforma(float x = 0.f, float y = 0.f, float ww = 100.f, float hh = 100.f);
            virtual ~Plataforma();
            void executar();
            virtual void imprimir(Gerenciador::GerenciadorGrafico *gG);
            void atualizar();
            virtual const int getTipo() const;
            virtual void colide(Entidade* outraEntidade, sf::Vector2f intersecao);
            void obstacular(Personagens::Jogador* ponJogador);
    };
}
