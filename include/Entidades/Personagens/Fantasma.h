#pragma once

#include "Inimigo.h"
#include "Jogador.h"

namespace Personagens
{
    class Fantasma : public Inimigo
    {
        private:
            short movAle;
            int forcaEspiritual;
            
        public:
            Fantasma(float xx = 0, float yy = 0, float ww = 50.0, float hh = 50.0);

            ~Fantasma();

            void executar();

            void moveAleatorio();

            void atualizarPosicao();

            int getNumVidas();

            const sf::RectangleShape getCorpo();

            void imprimir(Gerenciador::GerenciadorGrafico *gG);

            void colide(Entidade *outraEntidade, sf::Vector2f intersecao); 
            
            void danificar(Personagens::Jogador* pontJogador);
    };
}