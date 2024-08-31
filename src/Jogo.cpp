#include "../include/Jogo.h"
#define CAMINHO_MAPA "mapaJogo1.json"
#include "../include/Estados/MenuPrincipal.h"
#include "../include/Estados/GameOver.h"
#include "../include/Estados/Placar.h"

Estados::Jogo::Jogo() :
    pontGGrafico(Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()),
    pontGEvento(Gerenciador::GerenciadorEvento::getGerenciadorEventos())
{
    pontGEvento->setGerenciadosGrafico(pontGGrafico);

    Estados::Estado* estado = static_cast<Estados::Estado*>(new Fases::Fase1(this));
    inserirEstado(estado);
    
    Estados::Estado* estado2 = static_cast<Estados::Estado*>(new Fases::Fase2(this));
    inserirEstado(estado2);

    estado = static_cast<Estados::Estado*>(new Menus::GameOver(this, static_cast<Fases::Fase1*>(estado)->getPontuacao(), static_cast<Fases::Fase2*>(estado2)->getPontuacao()));
    inserirEstado(estado);

    estado = static_cast<Estados::Estado*>(new Menus::MenuPrincipal(this));
    inserirEstado(estado);

    estado = static_cast<Estados::Estado*>(new Menus::Placar(this));
    inserirEstado(estado);
    
    mudarEstadoAtual(Estados::EstadoID::mainMenu);

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
        renderEstadoAtual();
        atualizarEstadoAtual();
        
       //fase->atualizar();
        pontGGrafico->monstraEntidade();
    }
}