#pragma once

#include "Entidade.h"

namespace Entidades
{
    class Projetil : public Entidades::Entidade
    {
        private:
            bool colidiu;
            int dano;
            int dir;
        public:
            Projetil(float xx = 0, float yy = 0, float ww = 50.0, float hh = 50.0,  int direcao = 0);

            ~Projetil();

            void executar();

            void atualizarPosicao();

            void imprimir(Gerenciador::GerenciadorGrafico *gG);

            void colide(Entidade *outraEntidade, sf::Vector2f intersecao);

    };
}