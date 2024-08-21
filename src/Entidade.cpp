#pragma once
#include "../include/Entidade.h"

Entidade::Entidade(float xx, float yy, float ww, float hh) :
    Ente(), x(xx), y(yy), corpo(sf::Vector2f(ww, hh))
{
    corpo.setFillColor(sf::Color::Blue);
}

Entidade::~Entidade()
{
    
}

void Entidade::salvar()
{

}