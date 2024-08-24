#include "../../include/Gerenciador/GerenciadorEventos.h"

Gerenciador::GerenciadorEvento *Gerenciador::GerenciadorEvento::pInstanciaGE = nullptr;

Gerenciador::GerenciadorEvento::GerenciadorEvento() :
    pontJogador1(nullptr), pontJogador2(nullptr)
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
    if (jogador1)
    {
        pontJogador1 = jogador1;
    }
    if (jogador2)
    {
        pontJogador2 = jogador2;
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

            case sf::Keyboard::L:
                pontJogador2->andar(false);
                break;

            case sf::Keyboard::J:
                pontJogador2->andar(true);
                break;

            case sf::Keyboard::O:
                pontJogador2->pular();
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

            case sf::Keyboard::L:
                pontJogador2->pararAndar();
                break;

            case sf::Keyboard::J:
                pontJogador2->pararAndar();
                break;

            default:
                break;
            }
        }
    }
}