#include "../../include/Estados/GameOver.h"

#define LEADERBOARD_PATH "placar.txt"

#include <fstream>
#include <map>

namespace Menus {

    GameOver::GameOver(Estados::GerenciadorEstado* pSM, int* fase1, int* fase2) :
    Menu(),
    Estado(pSM, Estados::EstadoID::gameOver),
    titulo(sf::Vector2f(0, 0), "GAME OVER"),
    pontos(),
    nome(sf::Vector2f(0, 0), ""),
    nameLabel(sf::Vector2f(0, 0), "nome:"),
    input(),
    fase_1(fase1),
    fase_2(fase2){
        Gerenciador::GerenciadorGrafico* GM = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

        pontuacao = 0;

        Botao* bt = NULL;
        pontuacao = 100;
        float w, h;

        // Obtenha o tamanho da janela
        w = GM->getJanela()->getSize().x;
        h = GM->getJanela()->getSize().y;

        bt = new Botao(sf::Vector2f(w / 2.0f - 200, h - 100), "PLAY AGAIN");
        bt->selecionar(true);
        vectorBotao.push_back(bt);

        bt = new Botao(sf::Vector2f(w / 2.0f + 200, h - 100), "MAIN MENU");
        vectorBotao.push_back(bt);

        selecionado = 0;
        max = 1;

        titulo.setPosicao(sf::Vector2f(w / 2.0f, h / 2 - 200));
        titulo.setTamanhoFonte(100);
        titulo.setAlinhamentoTexto(AlinhamentoTexto::centro);
        titulo.setCorTexto(77.6, 68.2, 44.3);

        pontos.setPosicao(sf::Vector2f(w / 2.0f - 100, h / 2));
        pontos.setTamanhoFonte(40);
        pontos.setCorTexto(77.6, 68.2, 44.3);
        pontos.setAlinhamentoTexto(AlinhamentoTexto::centro);

        nameLabel.setPosicao(sf::Vector2f(w / 2.0f - 200, h / 2 + 100));
        nameLabel.setTamanhoFonte(40);
        nameLabel.setCorTexto(77.6, 68.2, 44.3);
        nameLabel.setAlinhamentoTexto(AlinhamentoTexto::centro);

        nome.setPosicao(sf::Vector2f(w / 2.0f + nameLabel.getTamanho().x - 200, h / 2 + 100 - nameLabel.getTamanho().y));
        nome.setTamanhoFonte(40);
        nome.setCorTexto(77.6, 68.2, 44.3);
        nome.setAlinhamentoTexto(AlinhamentoTexto::centro);

    }

    GameOver::~GameOver() { }

    void GameOver::atualizar() {
        nome.setTextoInfo(input.getString());
        //if (pontuacao < plvl->getPlayerpontos())
            //pontuacao += 10;
        //pontos.setTextoInfo("pontos: " + std::to_string(plvl->getPlayerpontos()));
    }

    /* Menu operation to render all it's objects. */
    void GameOver::render() {
        updateView();
        for (it = vectorBotao.begin(); it != vectorBotao.end(); ++it)
            (*it)->render();

        titulo.render();
        pontos.render();
        nome.render();
        nameLabel.render();
    }

    void GameOver::executar() {
        if (ativo) {
            ativo = false;
            switch (selecionado) {
            case 0:
                changeEstado(Estados::EstadoID::fase1);
                break;
            case 1:
                changeEstado(Estados::EstadoID::mainMenu);
                break;
            default:
                break;
            }

            escreverNoPlacar();
        }
    }

    void GameOver::resetEstado() {
        for (it = vectorBotao.begin(); it != vectorBotao.end(); ++it)
            (*it)->selecionar(false);
        selecionado = 0;
        vectorBotao[selecionado]->selecionar(true);
        ativo = true;
        input.reset();
    }

    void GameOver::escreverNoPlacar() {
        //unsigned int playerpontos = plvl->getPlayerpontos();
        //printf("fase1: %d | Fase 2: %d", *fase_1, *fase_2);
        pontuacao = *fase_1 + *fase_2;

        /* ================================= Reading File ================================= */
        std::ifstream readFile;

        readFile.open(LEADERBOARD_PATH, std::ios::in);

        std::multimap<int, std::string> pontosEnomes;

        if (readFile) {

            unsigned int ponto;
            std::string nome;
            std::string pontosString;

            for (int i = 0; i < 10; i++) {
                std::getline(readFile, pontosString);
                std::getline(readFile, nome);
                if (pontosString.length() > 0)
                    pontosEnomes.insert(std::pair<int, std::string>(std::stoi(pontosString), nome));
            }

            readFile.close();
        }

        /* ================================= Writing File ================================= */
        if (pontuacao != 0 && input.getString().length() > 1)
            pontosEnomes.insert(std::pair<int, std::string>(pontuacao, input.getString()));

        std::ofstream escreverArquivo;

        escreverArquivo.open(LEADERBOARD_PATH, std::ios::out | std::ios::trunc);

        if (!escreverArquivo) {
            std::cout << "ERROR writing to file on GameOver" << std::endl;
            exit(1);
        }

        while (pontosEnomes.size() > 10)
            pontosEnomes.erase(pontosEnomes.begin());

        for (auto itr = pontosEnomes.rbegin(); itr != pontosEnomes.rend(); ++itr) {
            escreverArquivo << (*itr).first << std::endl;
            escreverArquivo << (*itr).second << std::endl;
        }

        escreverArquivo.close();
    }

}