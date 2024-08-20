#include "../../include/Obstaculos/Plataforma.h"
#include "../../include/Gerenciador/GerenciadorGrafico.h"

Obstaculos::Plataforma::Plataforma(float x, float y): Obstaculo(x, y, 1920, 320)
{

}

Obstaculos::Plataforma::~Plataforma()
{

}

void Obstaculos::Plataforma::imprimir()
{
    sf::RectangleShape y;
    //r.setTexture((*gG)[5]);
    r.setPosition(x, y);
    r.setSize(sf::Vector2f(w,h));
    //gG->getJanela();
    //gG->desenhaEntidade(r);
}

int const Obstaculos::Plataforma::getTipo()
{
    return Plataforma;
}

void Obstaculos::Plataforma::obstacular(Personagem* pP, int dir)
{

}