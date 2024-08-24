#include "../../include/Gerenciador/GerenciadorEventos.h"

Gerenciador::GerenciadorEvento* Gerenciador::GerenciadorEvento::pInstanciaGE = nullptr;

Gerenciador::GerenciadorEvento::GerenciadorEvento() :
    pontJog1(nullptr)
{
}

Gerenciador::GerenciadorEvento::~GerenciadorEvento()
{
}

Gerenciador::GerenciadorEvento* Gerenciador::GerenciadorEvento::getGerenciadorEventos()
{
    if(pInstanciaGE == nullptr) /*  primeira  vez que o método é chamado */
    {
        pInstanciaGE = new GerenciadorEvento();
    }
    return pInstanciaGE; /* todas as outras vezes  */
}

void Gerenciador::GerenciadorEvento::setGerenciadosGrafico(GerenciadorGrafico* pGG)
{
    pGGrafico = pGG;
}

void Gerenciador::GerenciadorEvento::setJogador(Personagens::Jogador* jog)
{
    pontJog1 = jog;
}

void Gerenciador::GerenciadorEvento::executar(sf::Event evento)
{
    while(pGGrafico->getJanela()->pollEvent(evento))
    {
        if(evento.type == sf::Event::Closed)
        {
            pGGrafico->fecharJanela();
        }
        if(evento.type == sf::Event::KeyPressed)
        {
            pontJog1->tratarEventoPressionar(evento);
        }
        if(evento.type == sf::Event::KeyReleased)
        {
            pontJog1->tratarEventoSoltar(evento);
        }
    }
}