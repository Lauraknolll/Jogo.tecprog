#pragma once

#include "Menu.h"
#include "Estados.h"
#include "../RecursosGraficos/Texto.h"
#include <vector>

namespace Menus {

    class Placar : public Menu, public Estados::Estado {
    private:
        std::vector<Texto*> pontos;
        std::vector<Texto*>::iterator itr;

    public:
        Placar(Estados::GerenciadorEstado* pSM = nullptr);

        ~Placar();

        void atualizar();

        void render();

        void resetEstado();

        void executar();

        void construiPlacar();

    };

}