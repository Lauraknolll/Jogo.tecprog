#include "../../include/Gerenciador/GerenciadorEventos.h"

Gerenciador::GerenciadorEvento *Gerenciador::GerenciadorEvento::pInstanciaGE = nullptr;

Gerenciador::GerenciadorEvento::GerenciadorEvento() :
    tem_jogador(false), pontJogador1(nullptr), pontJogador2(nullptr), pInputM(Gerenciador::GerenciadorInput::getGerenciadorInput())
{
}

Gerenciador::GerenciadorEvento::~GerenciadorEvento()
{
}

Gerenciador::GerenciadorEvento *Gerenciador::GerenciadorEvento::getGerenciadorEventos()
{
    if (pInstanciaGE == nullptr) /*  primeira  vez que o método é chamado */
    {
        pInstanciaGE = new GerenciadorEvento();
    }
    return pInstanciaGE; /* todas as outras vezes  */
}

void Gerenciador::GerenciadorEvento::setGerenciadosGrafico(GerenciadorGrafico *pGG)
{
    pGGrafico = pGG;
}

void Gerenciador::GerenciadorEvento::setJogador(Personagens::Jogador *jogador1, Personagens::Jogador *jogador2)
{
    /*if (jogador1)
    {
        pontJogador1 = jogador1;
    }
    if (jogador2)
    {
        pontJogador2 = jogador2;
    }*/
    if(!tem_jogador){
        pontJogador1 = jogador1;
        tem_jogador = true;
    }else{
        pontJogador2 = jogador1;
    }
}

void Gerenciador::GerenciadorEvento::executar(sf::Event evento)
{
    while (pGGrafico->getJanela()->pollEvent(evento))
    {
        if (evento.type == sf::Event::Closed)
        {
            pGGrafico->fecharJanela();
        }
        if (evento.type == sf::Event::KeyPressed)
        {
            pInputM->lidarTeclaPressionada(evento.key.code);
        }
        if (evento.type == sf::Event::KeyReleased)
        {
            pInputM->lidarTeclaSolta(evento.key.code);
        }
    }

    /*while (pGGrafico->getJanela()->pollEvent(evento))
    {
        if (evento.type == sf::Event::Closed)
        {
            pGGrafico->fecharJanela();
        }
        if (evento.type == sf::Event::KeyPressed)
        {
            // pontJogador1->tratarEventoPressionar(evento);
            switch (evento.key.code)
            {
            case sf::Keyboard::D:
                pontJogador1->andar(false);
                break;

            case sf::Keyboard::A:
                pontJogador1->andar(true);
                break;

            case sf::Keyboard::W:
                pontJogador1->pular();
                break;

            case sf::Keyboard::S:
                pontJogador1->atacar();
                break;

            case sf::Keyboard::L:
                pontJogador2->andar(false);
                break;

            case sf::Keyboard::J:
                pontJogador2->andar(true);
                break;

            case sf::Keyboard::O:
                pontJogador2->pular();
                break;

            case sf::Keyboard::K:
                pontJogador2->atacar();
                break;

            default:
                break;
            }
        }
        if (evento.type == sf::Event::KeyReleased)
        {
            // pontJogador1->tratarEventoSoltar(evento);
            switch (evento.key.code)
            {
            case sf::Keyboard::D:
                pontJogador1->pararAndar();
                break;

            case sf::Keyboard::A:
                pontJogador1->pararAndar();
                break;

            case sf::Keyboard::S:
                pontJogador1->paraAtacar();
                break;

            case sf::Keyboard::L:
                pontJogador2->pararAndar();
                break;

            case sf::Keyboard::J:
                pontJogador2->pararAndar();
                break;

            case sf::Keyboard::K:
                pontJogador2->paraAtacar();
                break;

            default:
                break;
            }
        }
    }*/
}