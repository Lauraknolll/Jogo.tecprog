#include "../include/Jogo.h"
#include "../include/Estados/MenuPrincipal.h"
#include "../include/Estados/GameOver.h"
#include "../include/Estados/Placar.h"
#include "../include/Estados/TelaFim.h"

Estados::Jogo::Jogo() :
    pontGGrafico(Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()),
    pontGEvento(Gerenciador::GerenciadorEvento::getGerenciadorEventos())
    
{
    pontGEvento->setGerenciadosGrafico(pontGGrafico);

    Estados::Estado* estado1 = static_cast<Estados::Estado*>(new Fases::Fase1(&pEst));
    pEst.inserirEstado(estado1);
    
    Estados::Estado* estado2 = static_cast<Estados::Estado*>(new Fases::Fase2(&pEst));
    pEst.inserirEstado(estado2);

    Estados::Estado* estado = static_cast<Estados::Estado*>(new Menus::GameOver(&pEst, static_cast<Fases::Fase1*>(estado1)->getPontuacao(), static_cast<Fases::Fase2*>(estado2)->getPontuacao()));
    pEst.inserirEstado(estado);

    estado = static_cast<Estados::Estado*>(new Menus::TelaFim(&pEst, static_cast<Fases::Fase1*>(estado1)->getPontuacao(), static_cast<Fases::Fase2*>(estado2)->getPontuacao()));
    pEst.inserirEstado(estado);

    estado = static_cast<Estados::Estado*>(new Menus::MenuPrincipal(&pEst));
    pEst.inserirEstado(estado);

    estado = static_cast<Estados::Estado*>(new Menus::Placar(&pEst));
    pEst.inserirEstado(estado);
    
    pEst.mudarEstadoAtual(Estados::EstadoID::mainMenu);

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
    if(estado != nullptr)
    {
        delete estado;
        estado = nullptr;
    }
}

void Estados::Jogo::executar()
{
    while (pontGGrafico->verificarJanelaAberta())
    {
        sf::Event evento;
        
        pontGEvento->executar(evento); 
        pontGGrafico->limpaJanela();
        pEst.renderEstadoAtual();
        pEst.atualizarEstadoAtual();
        pontGGrafico->monstraEntidade();
    }
}