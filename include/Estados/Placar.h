//codigo usado de referencia proveniente de https://github.com/MatheusBurda/Desert/tree/master
#pragma once

#include "Menu.h"
#include "Estados.h"
#include "../RecursosGraficos/Texto.h"
#include <vector>

namespace Menus 
{

    class Placar : public Menu, public Estados::Estado 
    {
    private:
        std::vector<Texto*> pontos;
        std::vector<Texto*>::iterator itr;

    public:
        Placar(Estados::Mediator* pSM = nullptr);

        ~Placar();

        void atualizar();

        void render();

        void resetEstado();

        void executar();

        void construiPlacar();

    };

}