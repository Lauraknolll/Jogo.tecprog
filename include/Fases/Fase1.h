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
            const int maxInimigos;
            const int maxObstaculos;
        public:
            Fase1(Estados::Mediator* gE);

            ~Fase1();

            void executar();

            virtual void atualizar();

            void render();

            void criar();

            virtual void resetEstado();

            void criarFantasmas(); //Inimigo fácil

            void criarPedras(); //Obstáculo fácil

            virtual void sair();
            
            virtual void segundoJogador();

            void morreu();

            void vaiPraProximoFase();
    };
}