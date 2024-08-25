#include "../../include/Fases/Fase.h"

Fases::Fase::Fase() :
    Ente(), ListaJogadores(), ListaInimigos(), ListaObstaculos(), pGColisoes(nullptr)
{
    ListaJogadores = new Lista::ListaEntidade();
    ListaInimigos = new Lista::ListaEntidade();
    ListaObstaculos = new Lista::ListaEntidade();
    pGColisoes = new Gerenciador::GerenciadorColisoes(ListaJogadores, ListaObstaculos, ListaInimigos);
}

Fases::Fase::~Fase()
{
    if (pGColisoes != nullptr)
    {
        delete pGColisoes;
        pGColisoes = nullptr;
    }
    ListaJogadores->cleanList();
    ListaInimigos->cleanList();
    ListaObstaculos->cleanList();
}

void Fases::Fase::criarJogadores()
{
    Personagens::Jogador *jogador1 = new Personagens::Jogador(200.0, 340.0);
    jog = jogador1;
    Personagens::Jogador *jogador2 = new Personagens::Jogador(200.0, 350.0);
    // Como tem o sigleton então é o msm da principal
    Gerenciador::GerenciadorEvento *pGEvento = Gerenciador::GerenciadorEvento::getGerenciadorEventos();

    /*se for selecionado apenas um jogador no menu
    pGEvento->setJogador(jogador1);
    ListaJogadores->addEntidade(jogador1); */

    /* se for selecionado dois jogadores no menu*/
    if ((jogador1 != nullptr) && (jogador2 != nullptr)) //mudar dps pra se for nulo ai msg de erro
    {
        pGEvento->setJogador(jogador1, jogador2);
        ListaJogadores->addEntidade(static_cast<Entidades::Entidade *>(jogador1));
        ListaJogadores->addEntidade(static_cast<Entidades::Entidade *>(jogador2));
    }
}
void Fases::Fase::criarInimigos()
{
    Personagens::InimigoFacil *ini1 = new Personagens::InimigoFacil(200.0, 450.0);
    Personagens::InimigoMedio *ini2 = new Personagens::InimigoMedio(200.0, 450.0);

    if(ini1 != nullptr && ini2 != nullptr)
    {
        ListaInimigos->addEntidade(static_cast<Entidades::Entidade*>(ini1));
        ListaInimigos->addEntidade(static_cast<Entidades::Entidade*>(ini2));
        ini2->setJogador(jog);
    }
}

void Fases::Fase::criarPLataformas()
{
    Obstaculos::Plataforma* plataforma = new Obstaculos::Plataforma(100.0, 500.0, 600.0, 25.0);
    if(plataforma != nullptr)
    {
        ListaObstaculos->addEntidade(static_cast<Entidades::Entidade*>(plataforma));
    }
}

void Fases::Fase::executar()
{
    Gerenciador::GerenciadorGrafico* pontGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
    ListaJogadores->percorrerLista();
    ListaJogadores->desenharEntidades(pontGrafico);
    ListaInimigos->percorrerLista();
    ListaInimigos->desenharEntidades(pontGrafico);
    ListaObstaculos->percorrerLista();
    ListaObstaculos->desenharEntidades(pontGrafico);

    pGColisoes->colide();
}

void Fases::Fase::cria()
{
    /* enquanto não tem as fases filhas */
    criarJogadores();
    criarInimigos();
    criarPLataformas();
}