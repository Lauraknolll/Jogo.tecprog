#pragma once

#include "Obstaculo.h"

namespace Obstaculos
{
    class Espinho : public Obstaculo
    {
    private:
        int nivelEspinhosidade;

    public:
        Espinho(float x = 0.f, float y = 0.f, float ww = 50.f, float hh = 50.f);

        ~Espinho();

        void executar();

        void atualizarPosicao();

        void desenhar(Gerenciador::GerenciadorGrafico *gG);

        void colide(Entidade *outraEntidade, sf::Vector2f intersecao);

        void obstacular(Personagens::Jogador *pontJogador);
    };
}