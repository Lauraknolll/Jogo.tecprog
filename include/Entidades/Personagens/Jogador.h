#pragma once 
#include "Personagem.h"

namespace Personagens
{
    class Jogador : public Personagem
    {
    private:
        int pontos;
    public:
        Jogador(float xx = 0, float yy = 0, float ww = 50.0, float hh = 50.0);
        ~Jogador();
        void executar();
        void andaPraDireta();
        void andaPraEsquerda();
        void imprimir(Gerenciador::GerenciadorGrafico *gG);
        void colide(Entidade *outraEntidade, sf::Vector2f intersecao); 
    };
}