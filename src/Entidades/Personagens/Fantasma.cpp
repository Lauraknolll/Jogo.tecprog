#include "../../../include/Entidades/Personagens/Fantasma.h"

#define VELOCIDADE_FANTASMA 0.01f
#define VIDAS_FANTASMA 1000
#include <stdlib.h>
#include <iostream>

Personagens::Fantasma::Fantasma(float xx, float yy, float ww, float hh) :
    Inimigo(xx, yy, ww, hh, Entidades::fantasma)
{
    forcaEspiritual = rand()%5;
    num_vidas = VIDAS_FANTASMA;
    corpo.setFillColor(sf::Color::White);
    velocidade.x = VELOCIDADE_FANTASMA;
    velocidade.y = 0.0f;
    movAle = rand()%2;
}

Personagens::Fantasma::~Fantasma()
{

}

void Personagens::Fantasma::executar()
{
    if(vivo){
        atualizarPosicao();
        moveAleatorio();
    }
}

void Personagens::Fantasma::moveAleatorio()
{
    if(movAle == 0)
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
        movAle = rand()%2;
        relogio.restart();
    }

}

const sf::RectangleShape Personagens::Fantasma::getCorpo()
{
    return corpo;
}

void Personagens::Fantasma::desenhar(Gerenciador::GerenciadorGrafico *gG)
{
    if(vivo)
    {
        gG->desenhaEntidade(corpo);
        corpo.setTexture(gG->carregaTextura("imagens/fantasma.png"));
    }
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
    if(pontJogador->estaAtacando())
    {
        num_vidas--;
    }
        else
    {
        pontJogador->recebaDano(forcaEspiritual);
    }
}

void Personagens::Fantasma::atualizarPosicao()
{
    if(vivo)
    {
        x = corpo.getPosition().x;
        y = corpo.getPosition().y;

        velocidade.y += GRAVIDADE;
        velocidade.y += FORCA_SUSTENTACAO;
    }
}

int Personagens::Fantasma::getNumVidas()
{
    return num_vidas;
}

bool Personagens::Fantasma::getVivo()
{
    return vivo;
}

void Personagens::Fantasma::setVivo()
{
    vivo = false;
}
