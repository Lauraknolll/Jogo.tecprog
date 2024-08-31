#pragma once

#include "Estados.h"
#include "../Controle/ControleMenu.h"
#include "../RecursosGraficos/Botao.h"
#include "../Gerenciador/GerenciadorGrafico.h"
#include <vector>

namespace Estados
{
    class Jogo;
}

namespace Menus 
{

    class Menu 
    {
    protected:
        std::vector<Botao*> vectorBotao;
        std::vector<Botao*>::iterator it;

        Controle::MenuControle control;

        sf::Sprite fundo;
        sf::Texture textura_fundo;
        
        int selecionado;
        int min;
        int max;
        
        bool ativo;

    public:
        Menu();

        virtual ~Menu();

        virtual void executar() = 0;

        void updateView();

        void selecionarBaixo();

        void selecionarCima();
    };

}