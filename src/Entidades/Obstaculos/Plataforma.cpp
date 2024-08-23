#include "../../../include/Entidades/Obstaculos/Plataforma.h"
#include "../../../include/Gerenciador/GerenciadorGrafico.h"

Obstaculos::Plataforma::Plataforma(float x, float y, float ww, float hh): 
Obstaculo(x, y, ww, hh, Entidades::plataforma)
{

}

Obstaculos::Plataforma::~Plataforma()
{

}

void Obstaculos::Plataforma::executar()
{

}

void Obstaculos::Plataforma::imprimir(Gerenciador::GerenciadorGrafico *gG)
{
    //sf::RectangleShape r(sf::Vector2f(100.f, 100.f));
    //r.setFillColor(sf::Color::Blue);
    //r.setTexture((*gG)[5]);
    gG->desenhaEntidade(corpo);
}

const int Obstaculos::Plataforma::getTipo() const
{
    return 0;
}

void Obstaculos::Plataforma::colide(Entidades::Entidade* outraEntidade, sf::Vector2f intersecao)
{

}

void Obstaculos::Plataforma::obstacular(Personagens::Personagem* pP, int dir)
{

}