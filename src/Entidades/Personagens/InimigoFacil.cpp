#include "../../../include/Entidades/Personagens/InimigoFacil.h"

#define VELOCIDADE_INIMF 0.1f
#include <stdlib.h>

Personagens::InimigoFacil::InimigoFacil(float xx, float yy, float ww, float hh) :
    Inimigo(xx, yy, ww, hh, Entidades::inimigoFacil)
{
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
        corpo.move(sf::Vector2f(VELOCIDADE_INIMF, 0.0f));
    }
    else
    {
        corpo.move(sf::Vector2f(-VELOCIDADE_INIMF, 0.0f));
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

}

void Personagens::InimigoFacil::atualizarPosicao()
{
    x = corpo.getPosition().x;
    y = corpo.getPosition().y;
}
