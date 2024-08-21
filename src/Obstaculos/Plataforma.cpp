#include "../../include/Obstaculos/Plataforma.h"
#include "../../include/Gerenciador/GerenciadorGrafico.h"

Obstaculos::Plataforma::Plataforma(float x, float y): Obstaculo(x, y, 1920, 320)
{

}

Obstaculos::Plataforma::~Plataforma()
{

}

void Obstaculos::Plataforma::imprimir(Gerenciador::GerenciadorGrafico &gG)
{
    //sf::RectangleShape r;
    //r.setTexture((*gG)[5]);
    corpo.setFillColor(sf::Color::Blue);
    //r.setPosition(x, y);
    //r.setSize(sf::Vector2f(w,y));
    gG.getJanela();
    gG.desenhaEntidade(corpo);
}

/*int const Obstaculos::Plataforma::getTipo()
{
    return Plataforma;
}*/

void Obstaculos::Plataforma::obstacular(Personagem* pP, int dir)
{

}