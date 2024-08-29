#pragma once
#include "Inimigo.h"

namespace Personagens
{
    class Rino : public Inimigo
    {
        private:
            Jogador* jogador;
            int chifrada;
            short movAle;
        public:
            Rino(float xx = 0, float yy = 0, float ww = 50.0, float hh = 50.0);
            ~Rino();
            void executar();
            void atualizarPosicao();
            int getNumVidas();
            void movimentoAleatorio();
            void imprimir(Gerenciador::GerenciadorGrafico* gG);
            const sf::RectangleShape getCorpo();
            void setJogador(Jogador* pJ);
            void persegueJogador(sf::Vector2f posJog, sf::Vector2f posIni);
            void colide(Entidade *outraEntidade, sf::Vector2f intersecao);
            void danificar(Personagens::Jogador* pontJogador);
    };
}