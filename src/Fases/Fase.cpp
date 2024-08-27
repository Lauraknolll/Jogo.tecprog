#include "../../include/Fases/Fase.h"
#define CAMINHO_MAPA "src/mapaJogo1.json"

Fases::Fase::Fase() : Ente(), ListaJogadores(), ListaInimigos(), ListaObstaculos(), pGColisoes(nullptr)
{
    ListaJogadores = new Lista::ListaEntidade();
    ListaInimigos = new Lista::ListaEntidade();
    ListaObstaculos = new Lista::ListaEntidade();
    pGColisoes = new Gerenciador::GerenciadorColisoes(ListaJogadores, ListaObstaculos, ListaInimigos);

    std::string caminho = CAMINHO_MAPA;

    std::cout << caminho;

    gerador_mapa = new Tilemap(caminho);
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
    jog1 = jogador1;
    Personagens::Jogador *jogador2 = new Personagens::Jogador(200.0, 350.0);
    jog2 = jogador2;
    // Como tem o sigleton então é o msm da principal
    Gerenciador::GerenciadorEvento *pGEvento = Gerenciador::GerenciadorEvento::getGerenciadorEventos();
    Gerenciador::GerenciadorGrafico *pGGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

    /*se for selecionado apenas um jogador no menu
    pGEvento->setJogador(jogador1);
    ListaJogadores->addEntidade(jogador1); */

    /* se for selecionado dois jogadores no menu*/
    if ((jogador1 != nullptr) && (jogador2 != nullptr)) // mudar dps pra se for nulo ai msg de erro
    {
        pGEvento->setJogador(jogador1, jogador2);
        ListaJogadores->addEntidade(static_cast<Entidades::Entidade *>(jogador1));
        ListaJogadores->addEntidade(static_cast<Entidades::Entidade *>(jogador2));
    }
}

void Fases::Fase::criarInimigosFaceis()
{
    for (int i = 0; i < 3; i++)
    {
        Personagens::InimigoFacil *ini1 = new Personagens::InimigoFacil(400.0 + 100*i, 450.0);

        if (ini1 != nullptr)
        {
            ListaInimigos->addEntidade(static_cast<Entidades::Entidade *>(ini1));
        }
    }
}

void Fases::Fase::criarInimigosMedios()
{
    for (int i = 0; i < 2; i++)
    {
        Personagens::InimigoMedio *ini1 = new Personagens::InimigoMedio(300.0 + 100*i, 450.0);
        if (ini1 != NULL)
        {
            ListaInimigos->addEntidade(static_cast<Entidades::Entidade *>(ini1));
            ini1->setJogador(jog1);
        }
    }
}

void Fases::Fase::criarPLataformas()
{
    Obstaculos::Plataforma *plataforma = new Obstaculos::Plataforma(100.0, 500.0, 1500.0, 25.0);
    if (plataforma != nullptr)
    {
        ListaObstaculos->addEntidade(static_cast<Entidades::Entidade *>(plataforma));
    }
    Obstaculos::Plataforma *plataforma2 = new Obstaculos::Plataforma(500.0, 375.0, 500.0, 25.0);
    if (plataforma2 != nullptr)
    {
        ListaObstaculos->addEntidade(static_cast<Entidades::Entidade *>(plataforma2));
    }
}

void Fases::Fase::executar()
{
    Gerenciador::GerenciadorGrafico *pontGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
    ListaJogadores->percorrerLista();
    ListaJogadores->desenharEntidades(pontGrafico);
    ListaInimigos->percorrerLista();
    ListaInimigos->desenharEntidades(pontGrafico);
    ListaObstaculos->percorrerLista();
    ListaObstaculos->desenharEntidades(pontGrafico);

    pGColisoes->colide();
    pontGrafico->centralizarCamera(sf::Vector2f(((jog1->getPosicao().x + jog2->getPosicao().x)/2), 300.0));
}

void Fases::Fase::cria()
{
    /* enquanto não tem as fases filhas */
    gerador_mapa->criarMapa(ListaJogadores, ListaInimigos, ListaObstaculos);
    printf("entrou aqui");
}