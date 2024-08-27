#pragma once

#include "Estados.h"
#include "../Controle/ControleMenu.h"
#include "../RecursosGraficos/Botao.h"
#include "../Gerenciador/GerenciadorGrafico.h"
#include "../Jogo.h"
#include <vector>

namespace Menus {
    class Menu: public Estados::Estado {
    protected:
        Jogo* pJogo;

        Texto titulo;

        std::vector<Botao*> vectorOfBotaos;
        std::vector<Botao*>::iterator it;
        int selected;
        int min;
        int max;
        Controle::MenuControle controle;
        bool ativo;

    public:
        Menu(Jogo* jog = nullptr);

        virtual ~Menu();

        void atualizar();

        virtual void executar();

        virtual void render();

        virtual void resetEstado();

        void selecionarBaixo();

        void selecionarCima();
    };

} // namespace Menus