#include "../../../include/Entidades/Personagens/Jogador.h"

Personagens::Jogador::Jogador() :
    Personagem()
{

}

Personagens::Jogador::~Jogador()
{

}

void Personagens::Jogador::executar()
{
    corpo.setFillColor(sf::Color::Magenta);
}

void Personagens::Jogador::andaPraDireta()
{
    corpo.move(sf::Vector2f(2.0f, 0.0f));
}

void Personagens::Jogador::andaPraEsquerda()
{
    corpo.move(sf::Vector2f(-2.0f, 0.0f));
}

const sf::RectangleShape Personagens::Jogador::getcorpo()
{
    return corpo;
}