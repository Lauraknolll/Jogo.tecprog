#include "../../include/Gerenciador/GerenciadorEventos.h"

Gerenciador::GerenciadorEvento *Gerenciador::GerenciadorEvento::pInstanciaGE = nullptr;

Gerenciador::GerenciadorEvento::GerenciadorEvento() :
    tem_jogador(false), pontJogador1(nullptr), pontJogador2(nullptr), pInputM(Gerenciador::GerenciadorInput::getGerenciadorInput())
{
}

Gerenciador::GerenciadorEvento::~GerenciadorEvento()
{
    pGGrafico = nullptr;
    pInputM = nullptr;
    pontJogador1 = nullptr;
    pontJogador2 = nullptr;
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

    if(!tem_jogador)
    {
        if(jogador1 != nullptr)
        {
            pontJogador1 = jogador1;
            tem_jogador = true;
        }
    }
    else
    {
        if(jogador2 != nullptr)
        {
            pontJogador2 = jogador1;
        }
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

}