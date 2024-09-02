#pragma once

#include "Obstaculo.h"
#include "../Personagens/Personagem.h"

namespace Obstaculos
{
    class Plataforma : public Obstaculo
    {
    private:
        int nivel_obstacularidade;
    public:
        Plataforma(float x = 0.f, float y = 0.f, float ww = 100.f, float hh = 100.f);

        virtual ~Plataforma();

        void executar();
        
        void atualizarPosicao();

        virtual void desenhar(Gerenciador::GerenciadorGrafico *gG);

        virtual void colide(Entidade *outraEntidade, sf::Vector2f intersecao);

        void obstacular(Personagens::Jogador *ponJogador);
    };
}
