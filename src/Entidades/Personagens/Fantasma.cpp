#include "../../../include/Entidades/Personagens/Fantasma.h"

#define GRAVIDADE 0.0001f
#define FORÇA_SUSTENTAÇÃO -0.0001f
#define VELOCIDADE_INIMF 0.01f
#define VIDAS_INIMF 10000
#include <stdlib.h>
#include <iostream>

Personagens::Fantasma::Fantasma(float xx, float yy, float ww, float hh) :
    Inimigo(xx, yy, ww, hh, Entidades::fantasma)
{
    num_vidas = VIDAS_INIMF;
    corpo.setFillColor(sf::Color::White);
    velocidade.x = VELOCIDADE_INIMF;
    velocidade.y = 0.0f;
    movimentoale = rand()%1;
}

Personagens::Fantasma::~Fantasma()
{

}

void Personagens::Fantasma::executar()
{
    atualizarPosicao();
    moveAleatorio();
}

void Personagens::Fantasma::moveAleatorio()
{
    if(movimentoale == 0)
    {
        corpo.move(sf::Vector2f(velocidade.x, velocidade.y));
    }
    else
    {
        corpo.move(sf::Vector2f(-velocidade.x, velocidade.y));
    }

    float tempo = relogio.getElapsedTime().asSeconds();
    if(tempo >= 4.0f)
    {
        movimentoale = rand()%2;
        relogio.restart();
    }

}

const sf::RectangleShape Personagens::Fantasma::getCorpo()
{
    return corpo;
}

void Personagens::Fantasma::imprimir(Gerenciador::GerenciadorGrafico *gG)
{
    gG->desenhaEntidade(corpo);
    corpo.setTexture(gG->carregaTextura("src/fantasma.png"));
}

void Personagens::Fantasma::colide(Entidades::Entidade *outraEntidade, sf::Vector2f intersecao)
{
    if(outraEntidade->getID() == Entidades::ID::jogador)
    {
        danificar(static_cast<Jogador*>(outraEntidade));
    }

}


void Personagens::Fantasma::danificar(Personagens::Jogador* pontJogador)
{
    num_vidas--;   
}

void Personagens::Fantasma::atualizarPosicao()
{
    x = corpo.getPosition().x;
    y = corpo.getPosition().y;

    velocidade.y += GRAVIDADE;
    velocidade.y += FORÇA_SUSTENTAÇÃO;
}

int Personagens::Fantasma::getNumVidas()
{
    return num_vidas;
}
