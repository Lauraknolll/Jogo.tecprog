#include "../../include/Estados/Menu.h"

#include "../../include/Gerenciador/GerenciadorGrafico.h"

#define BACKGROUND_MENU "./assets/Background/BrickBackground.png"

namespace Menus {
    Menu::Menu(Jogo* jog) :
    pJogo(jog),
    selected(0),
    min(0),
    max(2),
    controle(this),
    ativo(false) {
        Gerenciador::GerenciadorGrafico* GM = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

        Botao* bt = NULL;

        float w, h;
        w = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()->getJanela()->getSize().x;
        h = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()->getJanela()->getSize().y;

        titulo.setTextoInfo("DESERT");
        titulo.setTamanhoFont(140);
        titulo.setCorTexto(77.6, 68.2, 44.3);
        titulo.setAlinhamentoTexto(TextoAlignment::centro);

        titulo.setPosicao(sf::Vector2f(w/2.0, h/2.0));

        bt = new Botao(sf::Vector2f(w/2.0, h/2.0), "PLAY GAME");
        bt->selecionar(true);
        vectorOfBotaos.push_back(bt);

        bt = new Botao(sf::Vector2f(w/2.0, h/2.0 + 100), "LEADERBOARD");
        vectorOfBotaos.push_back(bt);

        bt = new Botao(sf::Vector2f(w/2.0, h/2.0 + 200), "SETTINGS");
        vectorOfBotaos.push_back(bt);

        bt = new Botao(sf::Vector2f(w/2.0, h/2.0 + 300), "EXIT GAME");
        vectorOfBotaos.push_back(bt);

    }

    Menu::~Menu() {
        Botao* bt = NULL;
        while (vectorOfBotaos.size() != 0) {
            bt = vectorOfBotaos.back();
            delete (bt);
            vectorOfBotaos.pop_back();
        }
        vectorOfBotaos.clear();
    }

    void Menu::atualizar() {
        float w, h;
        w = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()->getJanela()->getSize().x;
        h = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()->getJanela()->getSize().y;
        Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()->centralizarCamera(sf::Vector2f(w/2.0, h/2.0));
        ativo = true;
    }
    void Menu::executar()
    {
        if (ativo) {
            ativo = false;
            switch (selected) {
            case 0:
                changeEstado(Estados::EstadoID::fase1);
                break;
            case 1:
                changeEstado(Estados::EstadoID::fase2);
                break;
            case 2:
                changeEstado(Estados::EstadoID::mainMenu);
                break;
            case 3:
                //pJogo->endGame();
                break;
            default:
                break;
            }
        }
    }

    void Menu::render()
    {   
        atualizar();
        //Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()
        for (it = vectorOfBotaos.begin(); it != vectorOfBotaos.end(); ++it)
            (*it)->render();
        titulo.render();
    }

    void Menu::resetEstado()
    {
        vectorOfBotaos[selected]->selecionar(false);
        selected = 0;
        vectorOfBotaos[selected]->selecionar(true);
        titulo.setPosicao(sf::Vector2f(titulo.getPosicao().x, 0.0f - titulo.getTamanho().y / 2));
    }

    /* Make the menu selection go Down */
    void Menu::selecionarBaixo() {
        if (ativo) {
            vectorOfBotaos[selected]->selecionar(false);
            selected++;
            if (selected > max)
                selected = min;
            vectorOfBotaos[selected]->selecionar(true);
        }
    }

    /* Make the menu selection go Up */
    void Menu::selecionarCima() {
        if (ativo) {
            vectorOfBotaos[selected]->selecionar(false);
            selected--;
            if (selected < min)
                selected = max;
            vectorOfBotaos[selected]->selecionar(true);
        }
    }

} // namespace Menus