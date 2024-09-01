#include "../../include/Gerenciador/GerenciadorEventos.h"

Gerenciador::GerenciadorEvento *Gerenciador::GerenciadorEvento::pInstanciaGE = nullptr;

Gerenciador::GerenciadorEvento::GerenciadorEvento() :
    pInputM(Gerenciador::GerenciadorInput::getGerenciadorInput())
{
}

Gerenciador::GerenciadorEvento::~GerenciadorEvento()
{
    pGGrafico = nullptr;
    pInputM = nullptr;
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