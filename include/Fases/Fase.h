#pragma once

#include <fstream>
#include <string>
#include <stdlib.h>
#include "../Ente.h"
#include "../Gerenciador/GerenciadorColisoes.h"
#include "../Gerenciador/GerenciadorEventos.h"
#include "../Entidades/Personagens/Jogador.h"
#include "../Entidades/Personagens/Fantasma.h"
#include "../Entidades/Personagens/Galinha.h"
#include "../Entidades/Personagens/Rino.h"
#include "../Entidades/Obstaculos/Plataforma.h"
#include "../Entidades/Obstaculos/Lava.h"
#include "../Entidades/Obstaculos/Espinho.h"
#include "../Entidades/Obstaculos/Pedra.h"
#include "../Gerenciador/GerenciadorEventos.h"
#include "../json.hpp"
#include "../Gerenciador/GerenciadorInput.h"
#include "../Controle/ControleFase.h"

namespace Fases
{
    class Fase : public Ente
    {   
        protected:
            list<Entidades::Entidade*> ListaJogadores;
            list<Entidades::Entidade*> ListaObstaculos;
            vector<Entidades::Entidade*> ListaInimigos;
            Lista::ListaEntidade* Lista_Entidades;
            Gerenciador::GerenciadorColisoes* pGColisoes;
            Gerenciador::GerenciadorEvento* pEventos;
            Gerenciador::GerenciadorInput* pInput;
            nlohmann::json mapa; 
            Controle::ControleFase control;

            bool dois_jogadores;
            bool ativo;
           
        public:
            Fase();

            ~Fase();

            void cria();

            void executar();

            void gerenciarColisoes();

            void carregarMapa(std::string mapJson);
            
            sf::Vector2f lerMapa(std::string caminho_mapa, int* x, int* y, int* indice, long int num_entidade);

            virtual void sair() = 0;

            virtual void segundoJogador() = 0;

            void gerenciarMortos();
    };
}
//bool Fases::Fase::dois_jogadores = false;