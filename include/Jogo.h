#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciador/GerenciadorGrafico.h"
#include "Gerenciador/GerenciadorEventos.h"
#include "Fases/Fase.h"
//#include "Tilemap.h"


#include <iostream>
using namespace std;

class Jogo
{
    private:
        Gerenciador::GerenciadorGrafico* pontGGrafico;
        Gerenciador::GerenciadorEvento* pontGEvento;
        Gerenciador::GerenciadorColisoes* pColisao;
        Fases::Fase* pontFaseProv;
        //Tilemap* abrir_mapa;
    public:
        Jogo();
        ~Jogo();
        void executar();
};