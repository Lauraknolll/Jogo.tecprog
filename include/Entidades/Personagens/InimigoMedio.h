#pragma once

#include "Inimigo.h"
#include "Jogador.h"

#define RAIO_PERSEGUIR_X 200.0f

namespace Personagens
{
    class InimigoMedio : public Inimigo
    {
        private:
            Jogador* jogador;
        public:
            InimigoMedio(float xx = 0, float yy = 0, float ww = 50.0, float hh = 50.0);
            ~InimigoMedio();
            void setJogador(Jogador* pJ);
            void executar();
            void atualizarPosicao();
            int getNumVidas();
            void persegueJogador(sf::Vector2f posJog, sf::Vector2f posIni);
            const sf::RectangleShape getCorpo();
            void imprimir(Gerenciador::GerenciadorGrafico *gG);
            void colide(Entidade *outraEntidade, sf::Vector2f intersecao); 
            void danificar(Personagens::Jogador* pontJogador);
    };
}