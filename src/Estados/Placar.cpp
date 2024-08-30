#include "../../include/Estados/Placar.h"

#include <fstream>

#define CAMINHO_PLACAR "placar.txt"

namespace Menus {

    Placar::Placar(Estados::GerenciadorEstado* pSM) :
    Menu(),
    Estado(pSM, Estados::EstadoID::placar) {
        Gerenciador::GerenciadorGrafico* GM = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
        Botao* bt = NULL;
         float w, h;

        // Obtenha o tamanho da janela
        w = GM->getJanela()->getSize().x;
        h = GM->getJanela()->getSize().y;

        bt = new Botao(sf::Vector2f(w / 2.0f, h / 2.0f + 300), "MENU");
        bt->selecionar(true);
        vectorBotao.push_back(bt);

        max = 0;
    }

    Placar::~Placar() {
    }

    void Placar::atualizar() {
        ativo = true;
    }

    /* Menu operation to render all it's objects. */
    void Placar::render() {
        updateView();
        for (it = vectorBotao.begin(); it != vectorBotao.end(); ++it)
            (*it)->render();

        for (itr = pontos.begin(); itr != pontos.end(); ++itr)
            (*itr)->render();
    }

    void Placar::executar() {
        if (ativo) {
            ativo = false;
            changeEstado(Estados::EstadoID::mainMenu);
        }
    }

    void Placar::resetEstado() {
        vectorBotao[0]->selecionar(true);
        for (itr = pontos.begin(); itr != pontos.end(); ++itr)
            delete (*itr);
        pontos.clear();
        construiPlacar();
    }

    void Placar::construiPlacar() {
        std::ifstream file;

        file.open(CAMINHO_PLACAR, std::ios::binary | std::ios::in);

        if (!file) {
            std::ofstream writeFile(CAMINHO_PLACAR, std::ios::out | std::ios::trunc);
            writeFile.close();
        }

        int ponto;
        std::string name;
        std::string textString;
        std::string pontoString;

        Texto* txt;

        for (int i = 0; i < 10; i++) {
            name = "";
            ponto = 0;
            pontoString = "";

            std::getline(file, pontoString);
            std::getline(file, name);

            textString = std::to_string((i + 1) / 10) + std::to_string((i + 1) % 10) + " - " + name + " ";

            if (pontoString.length() > 0) {

                ponto = std::stoi(pontoString);

                pontoString = std::to_string(ponto / 1000000);
                ponto %= 1000000;

                pontoString += std::to_string(ponto / 100000);
                ponto %= 100000;

                pontoString += std::to_string(ponto / 10000);
                ponto %= 10000;

                pontoString += std::to_string(ponto / 1000);
                ponto %= 1000;

                pontoString += std::to_string(ponto / 100);
                ponto %= 100;

                pontoString += std::to_string(ponto / 10);
                ponto %= 10;

                pontoString += std::to_string(ponto);
            }

            while (textString.length() + pontoString.length() < 50) {
                textString += ".";
            }
            Gerenciador::GerenciadorGrafico* GM = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
            
            float w;

            // Obtenha o tamanho da janela
            w = GM->getJanela()->getSize().x;

            txt = new Texto(sf::Vector2f(w / 2.0f, 100 + 40 * i), textString + pontoString);
            txt->setTamanhoFonte(48);
            txt->setAlinhamentoTexto(AlinhamentoTexto::centro);
            txt->setCorTexto(77.6, 68.2, 44.3);
            pontos.push_back(txt);
        }

        file.close();
    }

}