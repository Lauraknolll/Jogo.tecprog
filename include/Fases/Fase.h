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
#include "../../include/RecursosGraficos/Botao.h"
#include "../../include/RecursosGraficos/Texto.h"

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
            
            sf::View camera;
            sf::Vector2f centro;

            Botao tela_pausado;

            Texto pausar;
            Texto mensagem;
            Texto mensagem2;
            Texto vida1;
            Texto vida2; 
            Texto ponto;

            int pontuacao;

            bool dois_jogadores;
            bool ativo;
            bool pausado;
           
        public:
            Fase();

            ~Fase();

            void executar();

            void gerenciarColisoes();

            void carregarMapa(std::string mapJson);
            
            sf::Vector2f lerMapa(std::string caminho_mapa, int* x, int* y, int* indice, long int num_entidade);

            virtual void sair() = 0;

            virtual void segundoJogador() = 0;

            void gerenciarMortos();

            bool todosMortos();

            void criarJogadores(std::string caminho_mapa);

            void criarPlataformas(std::string caminho_mapa);

            void criarGalinhas(std::string caminho_mapa, int maxIni); // Inimigo médio

            void criarLava(std::string caminho_mapa, int maxObs); // Obstáculo médio

            bool checarJogadores();

            int* getPontuacao();

            virtual void morreu() = 0;
            
            virtual void pause();

            void mensagemPausado();

            void hud();
    };
}
//bool Fases::Fase::dois_jogadores = false;