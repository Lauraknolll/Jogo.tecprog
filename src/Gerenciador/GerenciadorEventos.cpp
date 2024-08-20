#include "../../include/Gerenciador/GerenciadorEventos.h"

Gerenciador::GerenciadorEvento* Gerenciador::GerenciadorEvento::pInstanciaGE = nullptr;

Gerenciador::GerenciadorEventos::GerenciadorEvento() 
{
}

Gerenciador::GerenciadorEventos::~GerenciadorEvento()
{
}

Gerenciador::GerenciadorEvento* Gerenciador:GerenciadorEvento::getGerenciadorEventos()
{
    if(pInstanciaGE == pullptr) /*  primeira  vez que o método é chamado */
    {
        pIntanciaGE = new GerenciadorEventos();
    }
    return pInstanciaGE; /* todas as outras vezes  */
}

void Gerenciador::GerenciadorEvento::executar()
{
    sf::Event evento;
    while(pGGrafico->getJanela()->pollEvent(evento))
    {
        if(evento.type == sf::Event::Closed)
        {
            pGGrafico->fecharJanela();
        }
    }
}