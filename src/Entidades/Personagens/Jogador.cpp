#pragma once
#include "../../../include/Entidades/Personagens/Jogador.h"

Jogador::Jogador()
{

}

Jogador::~Jogador()
{

}

void Jogador::executar()
{
    
}

void Jogador::andaPraDireta()
{
    corpo.move(0.1f, 0.f);
}

void Jogador::andaPraEsquerda()
{
    corpo.move(-0.1f, 0.f);
}

sf::RectangleShape Jogador::getcorpo()
{
    return corpo;
}