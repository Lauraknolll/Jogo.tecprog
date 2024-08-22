#pragma once
#include "../../../include/Entidades/Personagens/Jogador.h"

Personagens::Jogador::Jogador()
{

}

Personagens::Jogador::~Jogador()
{

}

void Personagens::Jogador::executar()
{
    
}

void Personagens::Jogador::andaPraDireta()
{
    corpo.move(0.1f, 0.f);
}

void Personagens::Jogador::andaPraEsquerda()
{
    corpo.move(-0.1f, 0.f);
}

sf::RectangleShape Personagens::Jogador::getcorpo()
{
    return corpo;
}