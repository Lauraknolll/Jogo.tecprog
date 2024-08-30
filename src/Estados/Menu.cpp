#include "../../include/Estados/Menu.h"
#include "../../include/Gerenciador/GerenciadorGrafico.h"
#include "../../include/Jogo.h"

namespace Menus 
{

    Menu::Menu(Estados::Jogo* jog) :
    Estado(static_cast<Estados::GerenciadorEstado*>(jog), Estados::EstadoID::mainMenu),
    pJogo(jog),
    selecionado(0),
    min(0),
    max(2),
    controle(this),
    ativo(false)
    {
        // Armazene o GerenciadorGrafico em uma variável local
        auto* GG = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
        float w, h;

        // Obtenha o tamanho da janela
        w = GG->getJanela()->getSize().x;
        h = GG->getJanela()->getSize().y;

        // Configuração do título
        titulo.setTextoInfo("JOGO");
        titulo.setTamanhoFonte(140);
        titulo.setCorTexto(77.6f, 68.2f, 44.3f); 
        titulo.setAlinhamentoTexto(AlinhamentoTexto::centro);
        titulo.setPosicao(sf::Vector2f(w / 2.0f, h / 2.0f));

        // Adicione botões
        Botao* bt = nullptr;

        bt = new Botao(sf::Vector2f(w / 2.0f, h / 2.0f), "PLAY GAME");
        bt->selecionar(true);
        vectorBotoes.push_back(bt);

        bt = new Botao(sf::Vector2f(w / 2.0f, h / 2.0f + 100), "LEADERBOARD");
        vectorBotoes.push_back(bt);

        bt = new Botao(sf::Vector2f(w / 2.0f, h / 2.0f + 200), "SETTINGS");
        vectorBotoes.push_back(bt);
    }

    Menu::~Menu() 
    {
        // Limpeza dos botões
        printf("limpou o menu");
        
        while (!vectorBotoes.empty()) 
        {
            Botao* bt = vectorBotoes.back();
            delete bt;
            vectorBotoes.pop_back();
        }
        vectorBotoes.clear();
    }

    void Menu::atualizar() 
    {
        auto* GG = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
        float w, h;
        w = GG->getJanela()->getSize().x;
        h = GG->getJanela()->getSize().y;
        GG->centralizarCamera(sf::Vector2f(w / 2.0f, h / 2.0f));
        ativo = true;
    }

    void Menu::executar() 
    {
        if (ativo) 
        {
            ativo = false;
            switch (selecionado) 
            {
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

    void Menu::render() 
    {   
        atualizar();

        // Declare o iterador aqui
        for (auto it = vectorBotoes.begin(); it != vectorBotoes.end(); ++it) 
        {
            (*it)->render();
        }
        titulo.render();
    }

    void Menu::resetEstado() 
    {
        /*std::cout<<"puto";
        if (!vectorBotoes.empty()) {
            std::cout<<"puto40";
            vectorBotoes[selecionado]->selecionar(false);
            selecionado = 2;
            vectorBotoes[selecionado]->selecionar(true);
            titulo.setPosicao(sf::Vector2f(titulo.getPosicao().x, 0.0f - titulo.getTamanho().y / 2));
        }*/
    }

    void Menu::selecionarBaixo() 
    {
        if (ativo) 
        {
            vectorBotoes[selecionado]->selecionar(false);
            selecionado++;
            if (selecionado > max)
            {
                selecionado = min;
            }
            vectorBotoes[selecionado]->selecionar(true);
        }
    }

    void Menu::selecionarCima() 
    {
        if (ativo) 
        {
            vectorBotoes[selecionado]->selecionar(false);
            selecionado--;
            if (selecionado < min)
            {
                selecionado = max;
            }
            vectorBotoes[selecionado]->selecionar(true);
        }
    }
} 
