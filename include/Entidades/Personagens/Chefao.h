#pragma once
#include "Inimigo.h"

namespace Personagens
{
    class Chefao : public Inimigo
    {
        private:
        public:
            Chefao(float xx = 0, float yy = 0, float ww = 50.0, float hh = 50.0);
            ~Chefao();
            void executar();
            void imprimir(Gerenciador::GerenciadorGrafico* gG);
            const sf::RectangleShape getCorpo();
            void colide(Entidade *outraEntidade, sf::Vector2f intersecao);
            void danificar(Personagens::Jogador* pontJogador);
            int getNumVidas();
    };
}