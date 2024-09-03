//codigo usado de referencia proveniente de https://github.com/MatheusBurda/Desert/tree/master
#pragma once

#include "Menu.h"
#include "Estados.h"
#include "../Gerenciador/GerenciadorEstados.h"
#include "../RecursosGraficos/Texto.h"
#include "../Gerenciador/GerenciadorEstados.h"
#include "../Controle/ControleTexto.h"
#include "../Fases/Fase1.h"
#include "../Fases/Fase2.h"

namespace Menus
{
    class TelaFim: public Menu, public Estados::Estado
    {
        private:
            Texto titulo;
            Texto pontos;
            Texto nome;
            Texto nameLabel;
            Controle::ControleTexto input;
            int pontuacao;
            int *fase_1, *fase_2;
        
        public:
            TelaFim(Estados::Mediator* GE, int* fase1, int* fase2);
            
            ~TelaFim();

            void atualizar();

            void render();

            void executar();

            void resetEstado();

            void escreverNoPlacar();

            void irPlacar();
    };
}