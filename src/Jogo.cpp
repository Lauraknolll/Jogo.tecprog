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
    Personagens::Jogador* jog = new Personagens::Jogador(200.0, 340.0);
    pGEvento->setJogador(jog);
    Personagens::InimigoFacil* ini1 = new Personagens::InimigoFacil();
    //Personagens::InimigoMedio* ini2 = new Personagens::InimigoMedio();
    //ini2->setJogador(jog);
    Obstaculos::Plataforma *plat = new Obstaculos::Plataforma(300.0, 340.0);
    Obstaculos::Lava *lav = new Obstaculos::Lava();
    Lista::ListaEntidade* ListaEntidades = new Lista::ListaEntidade();
    Lista::ListaEntidade* ListaPlataforma = new Lista::ListaEntidade();


    /*  Colocando eles na lista para utilizar o polimorfismo    */
    Entidades::Entidade* e1 = static_cast<Entidades::Entidade*>(jog);
    Entidades::Entidade* e2 = static_cast<Entidades::Entidade*>(ini1);
    //Entidades::Entidade* e3 = static_cast<Entidades::Entidade*>(ini2);
    Entidades::Entidade* e4 = static_cast<Entidades::Entidade*>(plat);
    Entidades::Entidade* e5 = static_cast<Entidades::Entidade*>(lav);

    ListaEntidades->addEntidade(e1);
    ListaPlataforma->addEntidade(e4);
    ListaPlataforma->addEntidade(e5);
    

    Gerenciador::GerenciadorColisoes* pGColisoes = new Gerenciador::GerenciadorColisoes(ListaEntidades, ListaPlataforma);


    while (pGGrafico->verificarJanelaAberta())
    {
        sf::Event evento;

        pGEvento->executar(evento); //faz a verificação dos eventos
        pGGrafico->limpaJanela();

        ListaEntidades->percorrerLista(); //faz todos os elementos da lista executarem
        ListaEntidades->desenharEntidades(pGGrafico); //desenha todos os elementos da lista
        ListaPlataforma->percorrerLista();
        ListaPlataforma->desenharEntidades(pGGrafico);
        pGColisoes->colide();
        pGGrafico->monstraEntidade();
    }
}