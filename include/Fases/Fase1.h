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
            Controle::ControleJogador *controle;
        public:
            Fase1(Estados::GerenciadorEstado* gE, Controle::ControleJogador* cont);
            ~Fase1();
            void executar();
            virtual void atualizar();
            void render();
            void criar();
            virtual void resetEstado();

            void criarJogadores();

            void criarInimigosFaceis();
            void criarPlataformas(); //Obstáculo Fácil
            void criarInimigosMedios();
            void criarLava(); //Obstáculo médio
    };
}