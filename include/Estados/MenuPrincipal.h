#pragma once

#include "Menu.h"
#include "Estados.h"

namespace Estados 
{
    class Jogo;
}

namespace Menus 
{

    class MenuPrincipal : public Menu, public Estados::Estado 
    {
    private:
        Texto titulo;

    public:
        MenuPrincipal(Estados::Mediator* pG = nullptr);

        ~MenuPrincipal();

        void atualizar();

        void render();
        
        void resetEstado();

        void executar();
    };

}