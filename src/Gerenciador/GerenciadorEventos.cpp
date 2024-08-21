#include "../../include/Gerenciador/GerenciadorEventos.h"

Gerenciador::GerenciadorEvento* Gerenciador::GerenciadorEvento::pInstanciaGE = nullptr;

Gerenciador::GerenciadorEvento::GerenciadorEvento() 
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

//void Gerenciador::GerenciadorEvento::setJogador(Jogador jog)
//{
    //jogador = &jog;
//}

void Gerenciador::GerenciadorEvento::executar()
{
    sf::Event evento;
    while(pGGrafico->getJanela()->pollEvent(evento))
    {
        if(evento.type == sf::Event::Closed)
        {
            pGGrafico->fecharJanela();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            //jogador->andaPraDireta();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            //jogador->andaPraEsquerda();
        }
    }
}