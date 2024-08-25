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
sf::Vector2f Entidades::Entidade::getPosicao() const
{
    sf::Vector2f posicao = sf::Vector2f(corpo.getPosition().x, corpo.getPosition().y);
    return posicao;
}

sf::Vector2f Entidades::Entidade::getTamanho() const
{
    sf::Vector2f tamanho = sf::Vector2f(corpo.getSize().x, corpo.getSize().y);
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