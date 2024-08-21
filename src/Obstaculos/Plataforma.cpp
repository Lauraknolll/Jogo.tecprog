#pragma once

#include "../../include/Obstaculos/Plataforma.h"
#include "../../include/Gerenciador/GerenciadorGrafico.h"

Obstaculos::Plataforma::Plataforma(float x, float y): Obstaculo(x, y, 100, 100)
{

}

Obstaculos::Plataforma::~Plataforma()
{

}

void Obstaculos::Plataforma::executar(float dt)
{

}

void Obstaculos::Plataforma::imprimir(Gerenciador::GerenciadorGrafico *gG)
{
    
    //r.setTexture((*gG)[5]);
    corpo.setFillColor(sf::Color::Blue);
    corpo.setPosition(x, y);
    corpo.setSize(sf::Vector2f(w,y));
    gG->getJanela();
    gG->desenhaEntidade(corpo);
}

const int Obstaculos::Plataforma::getTipo() const
{
    return 0;
}

void Obstaculos::Plataforma::obstacular(Personagem* pP, int dir)
{

}