#include "../../include/Fases/Fase.h"
#define CAMINHO_MAPA "src/mapaJogo1.json"

Fases::Fase::Fase() :
    Ente(), ListaJogadores(), ListaInimigos(), ListaObstaculos(), pGColisoes(nullptr)
{
    Lista_Entidades = new Lista::ListaEntidade();
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
    ListaJogadores.clear();
    ListaInimigos.clear();
    ListaObstaculos.clear();
    Lista_Entidades->cleanList();
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
        ListaJogadores.push_back(static_cast<Entidades::Entidade *>(jogador1));
        ListaJogadores.push_back(static_cast<Entidades::Entidade *>(jogador2));
    }
}

void Fases::Fase::criarInimigosFaceis()
{
    for (int i = 0; i < 3; i++)
    {
        Personagens::InimigoFacil *ini1 = new Personagens::InimigoFacil(400.0 + 100*i, 450.0);

        if (ini1 != nullptr)
        {
            ListaInimigos.push_back(static_cast<Entidades::Entidade *>(ini1));
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
            ListaInimigos.push_back(static_cast<Entidades::Entidade *>(ini1));
            ini1->setJogador(jog1);
        }
    }
}

void Fases::Fase::criarPLataformas()
{
    Obstaculos::Plataforma *plataforma = new Obstaculos::Plataforma(100.0, 500.0, 1500.0, 25.0);
    if (plataforma != nullptr)
    {
        ListaObstaculos.push_back(static_cast<Entidades::Entidade *>(plataforma));
    }
    Obstaculos::Plataforma *plataforma2 = new Obstaculos::Plataforma(500.0, 375.0, 500.0, 25.0);
    if (plataforma2 != nullptr)
    {
        ListaObstaculos.push_back(static_cast<Entidades::Entidade *>(plataforma2));
    }
}

void Fases::Fase::executar()
{
    Gerenciador::GerenciadorGrafico *pontGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
    Lista_Entidades->percorrerLista();
    Lista_Entidades->desenharEntidades(pontGrafico);


    pGColisoes->colide();
    if(ListaJogadoresgetSize() > 1){
            pontGrafico->centralizarCamera(sf::Vector2f(((ListaJogadores->operator[](0)->getPosicao().x) + (ListaJogadores->operator[](1)->getPosicao().x))/2, 300.0));

    }else{
      pontGrafico->centralizarCamera(sf::Vector2f(((ListaJogadores->operator[](0)->getPosicao().x)), 300.0));
    }
}

void Fases::Fase::cria()
{
    /* enquanto não tem as fases filhas */
    gerador_mapa->criarMapa(ListaJogadores, ListaInimigos, ListaObstaculos);
    //printf("entrou aqui");
}