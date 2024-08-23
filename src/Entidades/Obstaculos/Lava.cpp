#include "../../../include/Entidades/Obstaculos/Lava.h"

#define DANO_LAVA 10

Obstaculos::Lava::Lava(float x, float y, float ww, float hh):
Obstaculo(x, y, ww, hh, Entidades::lava)
{
    corpo.setFillColor(sf::Color::Red);
}

Obstaculos::Lava::~Lava()
{

}

void Obstaculos::Lava::executar()
{

}

void Obstaculos::Lava::imprimir(Gerenciador::GerenciadorGrafico* gG){
    gG->desenhaEntidade(corpo);
}

unsigned int Obstaculos::Lava::tomarDano() const
{
    return DANO_LAVA;
}