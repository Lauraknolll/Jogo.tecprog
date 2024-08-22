#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciador/GerenciadorGrafico.h"
#include "Gerenciador/GerenciadorEventos.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Obstaculos/Plataforma.h"
#include "Entidades/Obstaculos/Lava.h"

#include <iostream>
using namespace std;

class Jogo
{
    private:
    public:
        Jogo();
        ~Jogo();
        void executar();
};