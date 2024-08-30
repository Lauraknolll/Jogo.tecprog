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
        Estados::Jogo* pJogo;
        Texto titulo;

    public:
        MenuPrincipal(Estados::Jogo* pG = nullptr);

        ~MenuPrincipal();

        void atualizar();

        void render();
        
        void resetEstado();

        void executar();
    };

}