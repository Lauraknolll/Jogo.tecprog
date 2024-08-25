#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciador/GerenciadorGrafico.h"
#include "Gerenciador/GerenciadorEventos.h"
#include "Fases/Fase.h"


#include <iostream>
using namespace std;

class Jogo
{
    private:
        Gerenciador::GerenciadorGrafico* pontGGrafico;
        Gerenciador::GerenciadorEvento* pontGEvento;
        Fases::Fase* pontFaseProv;
    public:
        Jogo();
        ~Jogo();
        void executar();
};