#pragma once 
#include "Personagem.h"

namespace Personagens
{
    class Jogador : public Personagem
    {
    private:
        int pontos;
    public:
        Jogador();
        ~Jogador();
        void executar();
        void andaPraDireta();
        void andaPraEsquerda();
        void imprimir(Gerenciador::GerenciadorGrafico *gG);
        void colide(Entidade *outraEntidade, sf::Vector2f intersecao); 
    };
}