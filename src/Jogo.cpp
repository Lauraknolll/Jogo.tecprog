#include "../include/Jogo.h"
#define CAMINHO_MAPA "mapaJogo1.json"

Estados::Jogo::Jogo() :
    pontGGrafico(Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()),
    pontGEvento(Gerenciador::GerenciadorEvento::getGerenciadorEventos()),
    pontFaseProv(new Fases::Fase())
{
    pontGEvento->setGerenciadosGrafico(pontGGrafico);
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
    pontFaseProv->cria(); // cria todo mundo

    while (pontGGrafico->verificarJanelaAberta())
    {
        sf::Event evento;

        pontGEvento->executar(evento); 
        //printf("Funciona depois daqui");
        pontGGrafico->limpaJanela();
        //printf("Funciona depois daqui");
        pontFaseProv->executar();
        //printf("Funciona depois daqui");
        pontGGrafico->monstraEntidade();
        //printf("Funciona depois daqui");
    }
}