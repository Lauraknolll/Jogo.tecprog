#include "../../include/Estados/Menu.h"
#include "../../include/Gerenciador/GerenciadorGrafico.h"
#include "../../include/Jogo.h"

namespace Menus {

    Menu::Menu(Estados::Jogo* jog, Controle::MenuControle* cont) :
    Estado(static_cast<Estados::GerenciadorEstado*>(jog), Estados::EstadoID::mainMenu),
    pJogo(jog),
    selected(0),
    min(0),
    max(2),
    controle(cont),
    ativo(false)
    {
        // Armazene o GerenciadorGrafico em uma variável local
        auto* GM = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
        float w, h;
        controle->setMenu(this);

        // Obtenha o tamanho da janela
        w = GM->getJanela()->getSize().x;
        h = GM->getJanela()->getSize().y;

        // Configuração do título
        titulo.setTextoInfo("JOGO");
        titulo.setTamanhoFont(140);
        titulo.setCorTexto(77.6f, 68.2f, 44.3f); // Use f para literais de ponto flutuante
        titulo.setAlinhamentoTexto(TextoAlignment::centro);
        titulo.setPosicao(sf::Vector2f(w / 2.0f, h / 2.0f));

        // Adicione botões
        Botao* bt = nullptr;

        bt = new Botao(sf::Vector2f(w / 2.0f, h / 2.0f), "PLAY GAME");
        bt->selecionar(true);
        vectorOfBotaos.push_back(bt);

        bt = new Botao(sf::Vector2f(w / 2.0f, h / 2.0f + 100), "LEADERBOARD");
        vectorOfBotaos.push_back(bt);

        bt = new Botao(sf::Vector2f(w / 2.0f, h / 2.0f + 200), "SETTINGS");
        vectorOfBotaos.push_back(bt);
    }

    Menu::~Menu() {
        // Limpeza dos botões
        printf("limpou o menu");
        
        while (!vectorOfBotaos.empty()) {
            Botao* bt = vectorOfBotaos.back();
            delete bt;
            vectorOfBotaos.pop_back();
        }
        vectorOfBotaos.clear();
    }

    void Menu::atualizar() {
        auto* GM = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
        float w, h;
        w = GM->getJanela()->getSize().x;
        h = GM->getJanela()->getSize().y;
        GM->centralizarCamera(sf::Vector2f(w / 2.0f, h / 2.0f));
        ativo = true;
    }

    void Menu::executar() {
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
            default:
                break;
            }
        }
    }

    void Menu::render() {   
        atualizar();

        // Declare o iterador aqui
        for (auto it = vectorOfBotaos.begin(); it != vectorOfBotaos.end(); ++it) {
            (*it)->render();
        }
        titulo.render();
    }

    void Menu::resetEstado() {
        /*std::cout<<"puto";
        if (!vectorOfBotaos.empty()) {
            std::cout<<"puto40";
            vectorOfBotaos[selected]->selecionar(false);
            selected = 2;
            vectorOfBotaos[selected]->selecionar(true);
            titulo.setPosicao(sf::Vector2f(titulo.getPosicao().x, 0.0f - titulo.getTamanho().y / 2));
        }*/
    }

    void Menu::selecionarCima() {
        if (ativo) {
            vectorOfBotaos[selected]->selecionar(false);
            selected++;
            if (selected > max){
                selected = min;}
            vectorOfBotaos[selected]->selecionar(true);
        }
    }

    void Menu::selecionarBaixo() {
        if (ativo) {
            vectorOfBotaos[selected]->selecionar(false);
            selected--;
            if (selected < min){
                selected = max;}
            vectorOfBotaos[selected]->selecionar(true);
        }
    }

} // namespace Menus
