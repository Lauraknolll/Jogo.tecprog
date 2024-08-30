#pragma once

#include "Menu.h"
#include "Estados.h"
#include "../Gerenciador/GerenciadorEstados.h"
#include "../RecursosGraficos/Texto.h"
#include "../Gerenciador/GerenciadorEstados.h"

namespace Menus{
    class GameOver: public Menu, public Estados::Estado{
        private:
            Texto titulo;
            Texto mensagem;
        public:
            GameOver(Estados::GerenciadorEstado* GE);
            ~GameOver();

            void atualizar();
            void render();
            void executar();
            void resetEstado();
    };
}