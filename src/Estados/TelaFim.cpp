#include "../../include/Estados/TelaFim.h"

#define LEADERBOARD_PATH "placar.txt"
#define CAMINHO_FUNDO "imagens/fundo.png"
#include <fstream>
#include <map>

namespace Menus {

    TelaFim::TelaFim(Estados::Mediator* pSM, int* fase1, int* fase2) :
    Menu(),
    Estado(pSM, Estados::EstadoID::telaFim),
    titulo(sf::Vector2f(0, 0), "PARABENS!!"),
    pontos(),
    nome(sf::Vector2f(0, 0), ""),
    nameLabel(sf::Vector2f(0, 0), "nome:"),
    input(),
    fase_1(fase1),
    fase_2(fase2){
        Ente::textura.loadFromFile(CAMINHO_FUNDO);
        
        fundo.setTexture(Ente::textura);
        Gerenciador::GerenciadorGrafico* GM = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

        pontuacao = 0;

        Botao* bt = NULL;
        pontuacao = 100;
        float w, h;

        // Obtenha o tamanho da janela
        w = GM->getJanela()->getSize().x;
        h = GM->getJanela()->getSize().y;

        bt = new Botao(sf::Vector2f(w / 2.0f, h - 100), "MAIN MENU");
        vectorBotao.push_back(bt);

        selecionado = 0;
        max = 0;

        titulo.setPosicao(sf::Vector2f(w / 2.0f, h / 2 - 200));
        titulo.setTamanhoFonte(100);
        titulo.setAlinhamentoTexto(AlinhamentoTexto::centro);
        titulo.setCorTexto(32, 79, 221);

        pontos.setPosicao(sf::Vector2f(w / 2.0f - 100, h / 2));
        pontos.setTamanhoFonte(40);
        pontos.setCorTexto(32, 79, 221);
        pontos.setAlinhamentoTexto(AlinhamentoTexto::centro);

        nameLabel.setPosicao(sf::Vector2f(w / 2.0f - 200, h / 2 + 100));
        nameLabel.setTamanhoFonte(40);
        nameLabel.setCorTexto(32, 79, 221);
        nameLabel.setAlinhamentoTexto(AlinhamentoTexto::centro);

        nome.setPosicao(sf::Vector2f(w / 2.0f + nameLabel.getTamanho().x - 200, h / 2 + 100 - nameLabel.getTamanho().y));
        nome.setTamanhoFonte(40);
        nome.setCorTexto(32, 79, 221);
        nome.setAlinhamentoTexto(AlinhamentoTexto::centro);

    }

    TelaFim::~TelaFim() { }

    void TelaFim::atualizar() {
        nome.setTextoInfo(input.getString());
        //if (pontuacao < plvl->getPlayerpontos())
            //pontuacao += 10;
        //pontos.setTextoInfo("pontos: " + std::to_string(plvl->getPlayerpontos()));
    }

    /* Menu operation to render all it's objects. */
    void TelaFim::render() {
        Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()->getJanela()->draw(fundo);
        updateView();
        for (it = vectorBotao.begin(); it != vectorBotao.end(); ++it)
            (*it)->render();

        titulo.render();
        pontos.render();
        nome.render();
        nameLabel.render();
    }

    void TelaFim::executar() {
        irPlacar();
    }

    void TelaFim::resetEstado() {
        for (it = vectorBotao.begin(); it != vectorBotao.end(); ++it)
            (*it)->selecionar(false);
        selecionado = 0;
        vectorBotao[selecionado]->selecionar(true);
        ativo = true;
        input.reset();
    }

    void TelaFim::escreverNoPlacar() {

        pontuacao = *fase_1 + *fase_2;

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

        if (pontuacao != 0 && input.getString().length() > 1)
            pontosEnomes.insert(std::pair<int, std::string>(pontuacao, input.getString()));

        std::ofstream escreverArquivo;

        escreverArquivo.open(LEADERBOARD_PATH, std::ios::out | std::ios::trunc);

        if (!escreverArquivo) {
            std::cout << "ERROR writing to file on TelaFim" << std::endl;
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

    void TelaFim::irPlacar()
    {   
        changeEstado(Estados::EstadoID::placar);
    }

}