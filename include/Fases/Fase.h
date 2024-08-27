#pragma once

#include "../Ente.h"
#include "../Gerenciador/GerenciadorColisoes.h"
#include "../Gerenciador/GerenciadorEventos.h"
#include "../Entidades/Personagens/Jogador.h"
#include "../Entidades/Personagens/InimigoFacil.h"
#include "../Entidades/Personagens/InimigoMedio.h"
#include "../Entidades/Obstaculos/Plataforma.h"
#include "../Entidades/Obstaculos/Lava.h"
#include "../Tilemap.h"

namespace Fases
{
    class Fase : public Ente
    {   
        protected:
            Lista::ListaEntidade* ListaJogadores;
            Lista::ListaEntidade* ListaInimigos;
            Lista::ListaEntidade* ListaObstaculos;
            Gerenciador::GerenciadorColisoes* pGColisoes;
            Personagens::Jogador* jog1;
            Personagens::Jogador* jog2;
            Tilemap* gerador_mapa;
            //a fins de que o inimigo precisa conhecer o jogador, mas tem que pensar num jeito melhor
           
        public:
            Fase();
            ~Fase();
            void criarJogadores();
            void criarInimigosFaceis();
            void criarInimigosMedios();
            void criarPLataformas();
            void cria();
            void executar();
    };
}