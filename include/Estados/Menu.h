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
    class Menu: public Estados::Estado 
    {
    protected:
        Estados::Jogo* pJogo;

        Texto titulo;

        std::vector<Botao*> vectorBotoes;
        std::vector<Botao*>::iterator it;
        int selecionado;
        int min;
        int max;
        Controle::MenuControle* controle;
        bool ativo;

    public:
        Menu(Estados::Jogo* jog = nullptr, Controle::MenuControle* cont = nullptr);

        virtual ~Menu();

        void atualizar();

        virtual void executar();

        virtual void render();

        virtual void resetEstado();

        void selecionarBaixo();

        void selecionarCima();
    };

} 
