#pragma once

#include "Fase.h"
#include "../Estados/Estados.h"
#include "../Gerenciador/GerenciadorEstados.h"
#include "../Gerenciador/GerenciadorInput.h"
#include "../../include/Controle/ControleJogador.h"

namespace Fases
{
    class Fase2 : public Fase, public Estados::Estado
    {
        private:
            bool esta_final;
            bool t_dois;
            Controle::ControleJogador *controle;
        public:
            Fase2(Estados::GerenciadorEstado* gE, Controle::ControleJogador* cont);
            ~Fase2();
            void executar();
            virtual void atualizar();
            void render();
            void criar();
            virtual void resetEstado();

            void criarJogadores();

            void criarRinos(); //Inimigo dificil
            void criarEspinhos(); //Obstáculo difícil
            void criarGalinhas(); // Inimigo médio
            void criarPlataformas(); //Obstaculo médio
    };
}