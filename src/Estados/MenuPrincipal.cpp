//codigo usado de referencia proveniente de https://github.com/MatheusBurda/Desert/tree/master
#include "../../include/Estados/MenuPrincipal.h"

#define CAMINHO_FUNDO "imagens/fundo.png"

#include "../../include/Jogo.h"

namespace Menus {

    MenuPrincipal::MenuPrincipal(Estados::Mediator* pG) :
    Menu(),
    Estado(pG, Estados::EstadoID::mainMenu),
    titulo() {
        
        Ente::textura.loadFromFile(CAMINHO_FUNDO);
        
        fundo.setTexture(Ente::textura);
        Gerenciador::GerenciadorGrafico* GM = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
        Botao* bt = NULL;
        float w, h;

        // Obtenha o tamanho da janela
        w = GM->getJanela()->getSize().x;
        h = GM->getJanela()->getSize().y;

        bt = new Botao(sf::Vector2f(w / 2.0f, h / 2.0f + 50), "FASE 1");
        bt->selecionar(true);
        vectorBotao.push_back(bt);

        bt = new Botao(sf::Vector2f(w / 2.0f, h / 2.0f + 100), "FASE 2");
        vectorBotao.push_back(bt);

        bt = new Botao(sf::Vector2f(w / 2.0f, h / 2.0f + 150), "PLACAR");
        vectorBotao.push_back(bt);

        titulo.setTextoInfo("ANI++");
        titulo.setTamanhoFonte(140);
        titulo.setCorTexto(32, 79, 221);
        titulo.setAlinhamentoTexto(AlinhamentoTexto::centro);

        titulo.setPosicao(sf::Vector2f(w / 2.0f, h / 2.0f));

        max = 2;
    }

    MenuPrincipal::~MenuPrincipal() {
    }

    void MenuPrincipal::atualizar() {
        ativo = true;
        if (titulo.getPosicao().y < 200)
            titulo.setPosicao(sf::Vector2f(titulo.getPosicao().x, titulo.getPosicao().y + 1));
    }

    /* Menu operation to render all it's objects. */
    void MenuPrincipal::render() {
        Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()->getJanela()->draw(fundo);
        updateView();
        for (it = vectorBotao.begin(); it != vectorBotao.end(); ++it)
            (*it)->render();
        titulo.render();
    }

    void MenuPrincipal::executar() {
        if (ativo) {
            ativo = false;
            switch (selecionado) {
            case 0:
                changeEstado(Estados::EstadoID::fase1);
                break;
            case 1:
                changeEstado(Estados::EstadoID::fase2);
                break;
            case 2:
                changeEstado(Estados::EstadoID::placar);
                break;
            case 3:
                changeEstado(Estados::EstadoID::gameOver);
                break;
            default:
                break;
            }
        }
    }

    void MenuPrincipal::resetEstado() {
        vectorBotao[selecionado]->selecionar(false);
        selecionado = 0;
        vectorBotao[selecionado]->selecionar(true);
        titulo.setPosicao(sf::Vector2f(titulo.getPosicao().x, 0.0f - titulo.getTamanho().y / 2));
    }

}