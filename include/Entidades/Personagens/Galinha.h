#pragma once

#include "Inimigo.h"
#include "Jogador.h"


namespace Personagens
{
    class Galinha : public Inimigo
    {
        private:
            Jogador* jogador;
            int bicada;
            short movAle;
        public:

            Galinha(float xx = 0, float yy = 0, float ww = 50.0, float hh = 50.0);

            ~Galinha();

            void setJogador(Jogador* pJ);

            void executar();

            void atualizarPosicao();

            void moveAleatorio();

            int getNumVidas();

            bool getVivo();

            void setVivo();

            void persegueJogador(sf::Vector2f posJog, sf::Vector2f posIni);

            const sf::RectangleShape getCorpo();

            void desenhar(Gerenciador::GerenciadorGrafico *gG);

            void colide(Entidade *outraEntidade, sf::Vector2f intersecao); 
            
            void danificar(Personagens::Jogador* pontJogador);
    };
}