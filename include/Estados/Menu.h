//codigo usado de referencia proveniente de https://github.com/MatheusBurda/Desert/tree/master
#pragma once

#include "../Ente.h"
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

    class Menu : public Ente
    {
    protected:
        std::vector<Botao*> vectorBotao;
        std::vector<Botao*>::iterator it;

        Controle::MenuControle control;

        sf::Sprite fundo;
        
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