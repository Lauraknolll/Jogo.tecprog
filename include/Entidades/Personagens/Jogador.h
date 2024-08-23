#pragma once 
#include "Personagem.h"
#include "math.h"

namespace Personagens
{
    class Jogador : public Personagem
    {
    private:
        int pontos;
        bool podePular;
        bool podeAndarDireita;
        bool podeAndarEsquerda;
    public:
        Jogador(float xx = 0, float yy = 0, float ww = 50.0, float hh = 50.0);
        ~Jogador();
        void executar();
        void andaPraDireta();
        void andaPraEsquerda();
        void pular();
        void tratarEventoPrecionar(const sf::Event &e);
        void tratarEventoSoltar(const sf::Event &e);
        void atualizar();
        void imprimir(Gerenciador::GerenciadorGrafico *gG);
        void colide(Entidade *outraEntidade, sf::Vector2f intersecao); 
    };
}