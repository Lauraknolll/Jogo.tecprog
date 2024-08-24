#include "../include/Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
    /*  Criando gerenciadores  */
    Gerenciador::GerenciadorGrafico *pGGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
    Gerenciador::GerenciadorEvento *pGEvento = Gerenciador::GerenciadorEvento::getGerenciadorEventos();
    
    /* Criando entidades */
    Personagens::Jogador* jog = new Personagens::Jogador(200.0, 340.0);
    Personagens::InimigoFacil* ini1 = new Personagens::InimigoFacil(125.0, 450.0);
    Personagens::InimigoMedio* ini2 = new Personagens::InimigoMedio(125.0, 450.0);
    Obstaculos::Plataforma *plat = new Obstaculos::Plataforma(100.0, 500.0, 600.0, 25.0);
    Obstaculos::Lava *lav = new Obstaculos::Lava();

    pGEvento->setGerenciadosGrafico(pGGrafico);
    pGEvento->setJogador(jog);
    ini2->setJogador(jog);

    /* Criando Listas */
    Lista::ListaEntidade* ListaJogadores = new Lista::ListaEntidade();
    Lista::ListaEntidade* ListaInimigos = new Lista::ListaEntidade();
    Lista::ListaEntidade* ListaPlataforma = new Lista::ListaEntidade();


    /*  Colocando eles na lista para utilizar o polimorfismo    */
    Entidades::Entidade* e1 = static_cast<Entidades::Entidade*>(jog);
    Entidades::Entidade* e2 = static_cast<Entidades::Entidade*>(ini1);
    Entidades::Entidade* e3 = static_cast<Entidades::Entidade*>(ini2);
    Entidades::Entidade* e4 = static_cast<Entidades::Entidade*>(plat);
    Entidades::Entidade* e5 = static_cast<Entidades::Entidade*>(lav);

    ListaJogadores->addEntidade(e1);
    ListaInimigos->addEntidade(e2);
    ListaInimigos->addEntidade(e3);
    ListaPlataforma->addEntidade(e4);
    ListaPlataforma->addEntidade(e5);
    

    Gerenciador::GerenciadorColisoes* pGColisoes = new Gerenciador::GerenciadorColisoes(ListaJogadores, ListaPlataforma, ListaInimigos);


    while (pGGrafico->verificarJanelaAberta())
    {
        sf::Event evento;

        pGEvento->executar(evento); //faz a verificação dos eventos
        pGGrafico->limpaJanela();

        ListaJogadores->percorrerLista(); //faz todos os elementos da lista executarem
        ListaJogadores->desenharEntidades(pGGrafico); //desenha todos os elementos da lista
        ListaInimigos->percorrerLista();
        ListaInimigos->desenharEntidades(pGGrafico);
        ListaPlataforma->percorrerLista();
        ListaPlataforma->desenharEntidades(pGGrafico);

        pGColisoes->colide();
        pGGrafico->monstraEntidade();
    }
}