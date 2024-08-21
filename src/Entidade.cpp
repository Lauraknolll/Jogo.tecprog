#pragma once
#include "../include/Entidade.h"

Entidade::Entidade(float xx, float yy) :
    Ente(), x(xx), y(yy), corpo(sf::Vector2f(100.f, 100.f))
{

}

Entidade::~Entidade()
{
    
}