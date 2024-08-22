#pragma once
#include "../include/Entidade.h"

Entidade::Entidade(float xx, float yy, float w, float h) :
    Ente(), x(xx), y(yy), corpo(sf::Vector2f(w, h))
{
    corpo.setFillColor(sf::Color::Blue);
    
}

Entidade::~Entidade()
{
    
}
void Entidade::executar()
{

}
/*void Entidade::salvar()
{

}*/