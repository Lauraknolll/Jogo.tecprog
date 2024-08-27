#pragma once

#include "Observador.h"

namespace Menus {
    class Menu;
} // namespace Menus

namespace Controle {

    class MenuControle : public Observador {
    private:
        Menus::Menu* pMenu;

    public:
        MenuControle(Menus::Menu* pM = NULL);

        ~MenuControle();

        void anunciaPressionado(std::string key);
        
        void anunciaSolto(std::string key);

        void setMenu(Menus::Menu* p);
    };

} // namespace Control