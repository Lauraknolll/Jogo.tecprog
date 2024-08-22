#pragma once

#include "../../../include/Entidades/Obstaculos/Lava.h"

#define DANO_LAVA 10

Lava::Lava(float x, float y):
Obstaculo(x, y)
{
    corpo.setFillColor(sf::Color::Red);
}

Lava::~Lava()
{

}

void Lava::imprimir(Gerenciador::GerenciadorGrafico* gG){
    gG->desenhaEntidade(corpo);
}

unsigned int Lava::tomarDano() const
{
    return DANO_LAVA;
}