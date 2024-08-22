#include "../../../include/Entidades/Obstaculos/Lava.h"

#define DANO_LAVA 10

Obstaculos::Lava::Lava(float x, float y):
Obstaculo(x, y)
{
    corpo.setFillColor(sf::Color::Red);
}

Obstaculos::Lava::~Lava()
{

}

void Obstaculos::Lava::imprimir(Gerenciador::GerenciadorGrafico* gG){
    gG->desenhaEntidade(corpo);
}

unsigned int Obstaculos::Lava::tomarDano() const
{
    return DANO_LAVA;
}