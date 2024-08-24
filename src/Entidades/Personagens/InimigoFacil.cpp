#include "../../../include/Entidades/Personagens/InimigoFacil.h"

#define VELOCIDADE_INIMF 0.01f
#define VIDAS_INIMF 10000
#include <stdlib.h>
#include <iostream>

Personagens::InimigoFacil::InimigoFacil(float xx, float yy, float ww, float hh) :
    Inimigo(xx, yy, ww, hh, Entidades::inimigoFacil)
{
    num_vidas = VIDAS_INIMF;
    corpo.setFillColor(sf::Color::Red);
    velocidade.x = VELOCIDADE_INIMF;
    velocidade.y = 0.0f;
    movimentoale = rand()%1;
}

Personagens::InimigoFacil::~InimigoFacil()
{

}

void Personagens::InimigoFacil::executar()
{
    atualizarPosicao();
    moveAleatorio();
}

void Personagens::InimigoFacil::moveAleatorio()
{
    if(movimentoale == 0)
    {
        corpo.move(sf::Vector2f(velocidade.x, 0.0f));
    }
    else
    {
        corpo.move(sf::Vector2f(-velocidade.x, 0.0f));
    }

    float tempo = relogio.getElapsedTime().asSeconds();
    if(tempo >= 4.0f)
    {
        movimentoale = rand()%2;
        relogio.restart();
    }

}

const sf::RectangleShape Personagens::InimigoFacil::getCorpo()
{
    return corpo;
}

void Personagens::InimigoFacil::imprimir(Gerenciador::GerenciadorGrafico *gG)
{
    gG->desenhaEntidade(corpo);
}

void Personagens::InimigoFacil::colide(Entidades::Entidade *outraEntidade, sf::Vector2f intersecao)
{
    if(outraEntidade->getID() == Entidades::ID::jogador)
    {
        num_vidas--;
    }
}

void Personagens::InimigoFacil::atualizarPosicao()
{
    x = corpo.getPosition().x;
    y = corpo.getPosition().y;
}

int Personagens::InimigoFacil::getNumVidas()
{
    return num_vidas;
}
