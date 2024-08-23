#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciador/GerenciadorGrafico.h"
#include "Gerenciador/GerenciadorEventos.h"
#include "Gerenciador/GerenciadorColisoes.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/InimigoFacil.h"
#include "Entidades/Personagens/InimigoMedio.h"
#include "Entidades/Obstaculos/Plataforma.h"
#include "Entidades/Obstaculos/Lava.h"
#include "Listas/ListaEntidade.h"


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