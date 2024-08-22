#include "../../include/Entidades/Entidade.h"

Entidades::Entidade::Entidade(float xx, float yy, float ww, float hh) :
    Ente(), x(xx), y(yy), w(ww), h(hh), corpo(sf::Vector2f(w, h)), velocidade(sf::Vector2f(0.01f, 0.01f))
{
    corpo.setFillColor(sf::Color::Blue);
    corpo.setPosition(sf::Vector2f(x, y));
    
}

Entidades::Entidade::~Entidade()
{
    
}
void Entidades::Entidade::executar()
{

}
CoordF Entidades::Entidade::getPosicao() const
{
    CoordF posicao = CoordF(x, y);
    return posicao;
}

CoordF Entidades::Entidade::getTamanho() const
{
    CoordF tamanho = CoordF(w, h);
    return tamanho;
}



/*void Entidade::salvar()
{

}*/