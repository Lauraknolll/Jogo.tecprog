#include "../../include/Entidades/Entidade.h"

Entidades::Entidade::Entidade(float xx, float yy, float ww, float hh, ID idd) :
    Ente(), x(xx), y(yy), w(ww), h(hh), id(idd)
{
    corpo.setSize(sf::Vector2f(w, h));
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
    Coord posicao = CoordF(corpo.getPosition().x, corpo.getPosition().y);
    return posicao;
}

CoordF Entidades::Entidade::getTamanho() const
{
    CoordF tamanho = CoordF(corpo.getSize().x, corpo.getSize().y);
    return tamanho;
}

Entidades::ID Entidades::Entidade::getID()
{
    return id;
}

sf::RectangleShape Entidades::Entidade::getCorpo()
{
    return corpo;
}



/*void Entidade::salvar()
{

}*/