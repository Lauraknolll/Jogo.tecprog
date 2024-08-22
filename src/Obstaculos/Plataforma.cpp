#pragma once

#include "../../include/Obstaculos/Plataforma.h"
#include "../../include/Gerenciador/GerenciadorGrafico.h"

Plataforma::Plataforma(float x, float y): Obstaculo(x, y)
{

}

Plataforma::~Plataforma()
{

}

void Plataforma::executar(float dt)
{

}

void Plataforma::imprimir(Gerenciador::GerenciadorGrafico *gG)
{
    //sf::RectangleShape r(sf::Vector2f(100.f, 100.f));
    //r.setFillColor(sf::Color::Blue);
    //r.setTexture((*gG)[5]);
    gG->desenhaEntidade(corpo);
}

const int Plataforma::getTipo() const
{
    return 0;
}

void Plataforma::obstacular(Personagem* pP, int dir)
{

}