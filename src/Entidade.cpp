#pragma once
#include "../include/Entidade.h"

Entidade::Entidade(float xx, float yy) :
    Ente(), x(xx), y(yy), corpo(sf::Vector2f(10.f, 10.f))
{
    corpo.setFillColor(sf::Color::Blue);
}

Entidade::~Entidade()
{
    
}