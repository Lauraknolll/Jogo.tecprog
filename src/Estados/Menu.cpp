#include "../../include/Estados/Menu.h"
#include "../../include/Gerenciador/GerenciadorGrafico.h"
#include "../../include/Jogo.h"

namespace Menus {

    Menu::Menu() :
    selecionado(0),
    min(0),
    max(2),
    control(this),
    ativo(false) {
        Gerenciador::GerenciadorGrafico* GM = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

        fundo.setScale(4, 4);
        fundo.setPosition(sf::Vector2f(-200, -100));
        
    }

    Menu::~Menu() {
        Botao* bt = NULL;
        while (vectorBotao.size() != 0) {
            bt = vectorBotao.back();
            delete (bt);
            vectorBotao.pop_back();
        }
        vectorBotao.clear();
    }

    void Menu::updateView() {
        auto* GG = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
        float w, h;
        w = GG->getJanela()->getSize().x;
        h = GG->getJanela()->getSize().y;
        GG->centralizarCamera(sf::Vector2f(w / 2.0f, h / 2.0f));
    }

    /* Make the menu selection go Down */
    void Menu::selecionarBaixo() {
        if (ativo) {
            vectorBotao[selecionado]->selecionar(false);
            selecionado++;
            if (selecionado > max)
                selecionado = min;
            vectorBotao[selecionado]->selecionar(true);
        }
    }

    /* Make the menu selection go Up */
    void Menu::selecionarCima() {
        if (ativo) {
            vectorBotao[selecionado]->selecionar(false);
            selecionado--;
            if (selecionado < min)
                selecionado = max;
            vectorBotao[selecionado]->selecionar(true);
        }
    }

} // namespace Menus