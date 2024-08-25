#include "../include/Jogo.h"

Jogo::Jogo() :
    pontGGrafico(Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()),
    pontGEvento(Gerenciador::GerenciadorEvento::getGerenciadorEventos()),
    pontFaseProv(new Fases::Fase())
{
    pontGEvento->setGerenciadosGrafico(pontGGrafico);
}

Jogo::~Jogo()
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

void Jogo::executar()
{
    pontFaseProv->cria(); // cria todo mundo

    while (pontGGrafico->verificarJanelaAberta())
    {
        sf::Event evento;

        pontGEvento->executar(evento); //faz a verificação dos eventos
        pontGGrafico->limpaJanela();

        pontFaseProv->executar();

        pontGGrafico->monstraEntidade();
    }
}