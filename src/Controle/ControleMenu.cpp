#include "../../include/Controle/ControleMenu.h"

#include "../../include/Estados/Menu.h"


namespace Controle {

    MenuControle::MenuControle(Menus::Menu* pM) :
    Observador() 
    {
        pMenu = pM;
    }

    MenuControle::~MenuControle() 
    {
        pMenu = NULL;
    }

    void MenuControle::anunciaPressionado(std::string key) 
    {
        if (pMenu == NULL) {
            std::cout << "ERRO ; ponteiro nulo." << std::endl;
            exit(1);
        }

        if (key == "Down")
            pMenu->selecionarBaixo();
        if (key == "Up")
            pMenu->selecionarCima();
        if (key == "Enter")
            pMenu->executar();
        /*if (key == "Escape")
            if (dynamic_cast<Menus::PauseMenuState*>(pMenu) != nullptr)
                dynamic_cast<Menus::PauseMenuState*>(pMenu)->TriggerPauseMenu();*/
    }

    void MenuControle::anunciaSolto(std::string key) { }

    void MenuControle::setMenu(Menus::Menu* p) {
        pMenu = p;
    }

} 