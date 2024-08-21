#pragma once
#include "../include/Entidade.h"

Entidade::Entidade(float xx, float yy, float ww, float hh) :
    Ente(), x(xx), y(yy), corpo(sf::Vector2f(100.f, 100.f))
{
    corpo.setFillColor(sf::Color::Blue);
    corpo.setSize(sf::Vector2f(200.0f, 200.f));
    corpo.setOrigin(corpo.getSize() / 2.0f);
}

Entidade::~Entidade()
{
    
}

void Entidade::salvar()
{

}