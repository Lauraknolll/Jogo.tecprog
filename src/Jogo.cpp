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
    //ini2->setJogador(jog);
    Obstaculos::Plataforma *plat = new Obstaculos::Plataforma(300.0, 200.0);
    Obstaculos::Lava *lav = new Obstaculos::Lava();

    /*  Colocando eles na lista para utilizar o polimorfismo    */
    Entidades::Entidade* e1 = static_cast<Entidades::Entidade*>(jog);
    Entidades::Entidade* e2 = static_cast<Entidades::Entidade*>(ini1);
    Entidades::Entidade* e3 = static_cast<Entidades::Entidade*>(ini2);
    Entidades::Entidade* e4 = static_cast<Entidades::Entidade*>(plat);
    Entidades::Entidade* e5 = static_cast<Entidades::Entidade*>(lav);




    while (pGGrafico->verificarJanelaAberta())
    {
        sf::Event evento;

        pGEvento->executar(evento); //faz a verificação dos eventos
        pGGrafico->limpaJanela();
        
        pGGrafico->desenhaEntidade(jog->getcorpo());
        pGGrafico->desenhaEntidade(ini1->getCorpo());
        pGGrafico->desenhaEntidade(ini2->getCorpo());

        plat->imprimir(pGGrafico);
        lav->imprimir(pGGrafico);
        pGGrafico->monstraEntidade();
    }
}