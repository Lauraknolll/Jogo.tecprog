#include "../include/Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
    /*  Criando gerenciadores, jogador, inimigos e obstáculos   */
    Gerenciador::GerenciadorGrafico *pGGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
    Gerenciador::GerenciadorEvento *pGEvento = Gerenciador::GerenciadorEvento::getGerenciadorEventos();
    pGEvento->setGerenciadosGrafico(pGGrafico);
    Personagens::Jogador* jog = new Personagens::Jogador();
    pGEvento->setJogador(jog);
    Personagens::InimigoFacil* ini1 = new Personagens::InimigoFacil();
    Personagens::InimigoMedio* ini2 = new Personagens::InimigoMedio();
    ini2->setJogador(jog);
    Obstaculos::Plataforma *plat = new Obstaculos::Plataforma(300.0, 350.0);
    Obstaculos::Lava *lav = new Obstaculos::Lava();
    Lista::ListaEntidade ListaDeEntidades;
    Lista::ListaEntidade ListaJogador;
    Lista::ListaEntidade ListaPlataforma;


    /*  Colocando eles na lista para utilizar o polimorfismo    */
    Entidades::Entidade* e1 = static_cast<Entidades::Entidade*>(jog);
    Entidades::Entidade* e2 = static_cast<Entidades::Entidade*>(ini1);
    Entidades::Entidade* e3 = static_cast<Entidades::Entidade*>(ini2);
    Entidades::Entidade* e4 = static_cast<Entidades::Entidade*>(plat);
    Entidades::Entidade* e5 = static_cast<Entidades::Entidade*>(lav);

    ListaJogador.addEntidade(e1);
    ListaPlataforma.addEntidade(e4);
    

    Gerenciador::GerenciadorColisoes* pGColisoes = new Gerenciador::GerenciadorColisoes(&ListaJogador, &ListaPlataforma);


    ListaDeEntidades.addEntidade(e1);
    ListaDeEntidades.addEntidade(e2);
    ListaDeEntidades.addEntidade(e3);
    ListaDeEntidades.addEntidade(e4);
    ListaDeEntidades.addEntidade(e5);

    while (pGGrafico->verificarJanelaAberta())
    {
        sf::Event evento;

        pGEvento->executar(evento); //faz a verificação dos eventos
        pGGrafico->limpaJanela();

        ListaDeEntidades.percorrerLista(); //faz todos os elementos da lista executarem
        ListaDeEntidades.desenharEntidades(pGGrafico); //desenha todos os elementos da lista
        pGColisoes->colide();
        pGGrafico->monstraEntidade();
    }
}