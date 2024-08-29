#include "../include/Jogo.h"
#define CAMINHO_MAPA "mapaJogo1.json"
#include "../include/Estados/Menu.h"

Estados::Jogo::Jogo() :
    pontGGrafico(Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()),
    pontGEvento(Gerenciador::GerenciadorEvento::getGerenciadorEventos())
{
    pInput = Gerenciador::GerenciadorInput::getInstance();
    pontGEvento->setGerenciadosGrafico(pontGGrafico);

    control_menu = new Controle::MenuControle();
    control_jogador = new Controle::ControleJogador();

    Estados::Estado* estado = static_cast<Estados::Estado*>(new Fases::Fase1(this, control_jogador));
    inserirEstado(estado);
    estado = static_cast<Estados::Estado*>(new Fases::Fase2(this, control_jogador));
    inserirEstado(estado);

    estado = static_cast<Estados::Estado*>(new Menus::Menu(this, control_menu));
    inserirEstado(estado);
    control_menu->setMenu(static_cast<Menus::Menu*>(estado));
    
    changeAtualEstado(Estados::EstadoID::mainMenu);
    pInput->Attach(control_menu);

}

Estados::Jogo::~Jogo()
{
    if(pontGGrafico != nullptr)
    {
        delete pontGGrafico;
        pontGGrafico = nullptr;
    }
    if(pontGEvento != nullptr)
    {
        delete pontGEvento;
        pontGEvento = nullptr;
    }
    if(pontFaseProv != nullptr)
    {
        delete pontFaseProv;
        pontFaseProv = nullptr;
    }
}

void Estados::Jogo::executar()
{
    
    //pontFaseProv->render(); // cria todo mundo
    //Fases::Fase1 * fase = new Fases::Fase1(this, control_jogador);
    while (pontGGrafico->verificarJanelaAberta())
    {
        sf::Event evento;
        
        pontGEvento->executar(evento); 
        pontGGrafico->limpaJanela();
        renderAtualEstado();
        updateAtualEstado();
        
       //fase->atualizar();
        pontGGrafico->monstraEntidade();
    }
}