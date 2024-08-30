#pragma once

#include "Fase.h"
#include "../Estados/Estados.h"
#include "../Gerenciador/GerenciadorEstados.h"
#include "../Gerenciador/GerenciadorInput.h"
#include "../../include/Controle/ControleJogador.h"

namespace Fases
{
    class Fase1 : public Fase, public Estados::Estado
    {
        private:
            bool esta_final;
            bool t_dois;
            const int maxInimigos;
            const int maxObstaculos;
        public:
            Fase1(Estados::GerenciadorEstado* gE);

            ~Fase1();

            void executar();

            virtual void atualizar();

            void render();

            void criar();

            virtual void resetEstado();

            void criarJogadores();

            void criarFantasmas(); //Inimigo fácil

            void criarPlataformas(); 

            void criarGalinhas(); // Inimigo médio

            void criarPedras(); //Obstáculo fácil
            
            void criarLava(); //Obstáculo médio

            virtual void sair();
            
            virtual void segundoJogador();
    };
}