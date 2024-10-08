#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciador/GerenciadorGrafico.h"
#include "Gerenciador/GerenciadorEventos.h"
#include "Gerenciador/GerenciadorEstados.h"
#include "Fases/Fase1.h"
#include "Fases/Fase2.h"
#include "Estados/Estados.h"
#include "Controle/ControleMenu.h"
#include "Controle/ControleJogador.h"
#include "Gerenciador/GerenciadorInput.h"

#include <iostream>
using namespace std;

namespace Estados
{
    class Jogo
    {
    private:
        Gerenciador::GerenciadorGrafico *pontGGrafico;
        Gerenciador::GerenciadorEvento *pontGEvento;
        Gerenciador::GerenciadorColisoes *pColisao;
        Gerenciador::GerenciadorEstado pEst;
        Estados::Estado *estado;

    public:
        Jogo();

        ~Jogo();
        
        void executar();
    };
}
