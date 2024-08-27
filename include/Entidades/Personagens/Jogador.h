#pragma once 
#include "Personagem.h"
#include "math.h"

namespace Personagens
{
    class Jogador : public Personagem
    {
    private:
        int pontos;

        bool Atacando;

        bool vivo;
        bool emEsquerda;
        bool andando;
        bool pPular;
        
        float lentidao;
        float cooldownDano;

    public:
        Jogador(float xx = 0, float yy = 0, float ww = 50.0, float hh = 50.0);
        ~Jogador();
        void executar();
        void pular();
        void tratarEventoPressionar(const sf::Event &e);
        void tratarEventoSoltar(const sf::Event &e);
        void atualizar();
        void imprimir(Gerenciador::GerenciadorGrafico *gG);
        void colide(Entidade *outraEntidade, sf::Vector2f intersecao); 
        
        const bool estaNaEsquerda() const;
        void setEsquerda(const bool esquerda);
        void setEsquerda();

        void andar(bool esquerda);
        void pararAndar();
        unsigned int getPontos() const;

        void moveColisao(Entidades::Entidade* outraEnt, sf::Vector2f intersecao);
        int getNumVidas();
        void atacar();
        void paraAtacar();
        const bool estaAtacando();

        void recebaDano(const int dano);
    };
}