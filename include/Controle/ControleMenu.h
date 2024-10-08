//codigo usado de referencia proveniente de https://github.com/MatheusBurda/Desert/tree/master
#pragma once

#include "Observador.h"

namespace Menus 
{
    class Menu;
} 


namespace Controle 
{

    class MenuControle : public Observador 
    {
    private:
        Menus::Menu* pMenu;

    public:
        MenuControle(Menus::Menu* pM = NULL);

        ~MenuControle();

        void anunciaPressionado(std::string key);
        
        void anunciaSolto(std::string key);

        void setMenu(Menus::Menu* p);
    };

} 
