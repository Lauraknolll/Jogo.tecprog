#pragma once
#include "../include/Entidade.h"

Entidade::Entidade(float xx, float yy, float ww, float hh) :
    Ente(), x(xx), y(yy), w(ww), h(hh), corpo(sf::Vector2f(w, h))
{
    corpo.setFillColor(sf::Color::Blue);
    corpo.setPosition(sf::Vector2f(x, y));
    
}

Entidade::~Entidade()
{
    
}
void Entidade::executar()
{

}
CoordF Entidade::getPosicao() const
{
    CoordF posicao = CoordF(x, y);
    return posicao;
}

CoordF Entidade::getTamanho() const
{
    CoordF tamanho = CoordF(w, h);
    return tamanho;
}

void Entidade::colide(Entidade* outraEntidade, CoordF intersepta)
{
    
}
/*void Entidade::salvar()
{

}*/