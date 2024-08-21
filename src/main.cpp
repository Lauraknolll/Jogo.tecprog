#include <SFML/Graphics.hpp>
#include "../include/Gerenciador/GerenciadorGrafico.h"
#include "../include/Gerenciador/GerenciadorEventos.h"
#include "../include/Jogador.h"

#include <iostream>
using namespace std;

int main()
{
    
    sf::RenderWindow janela(sf::VideoMode(800, 600), "Jogo");
    
    Gerenciador::GerenciadorGrafico* pGGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
    //Gerenciador::GerenciadorEvento* pGEvento = Gerenciador::GerenciadorEvento::getGerenciadorEventos();

    while(pGGrafico->verificarJanelaAberta())
    {
        sf::Event evento;
        Jogador* jogador;
        while(pGGrafico->getJanela()->pollEvent(evento))
        {
            if(evento.type == sf::Event::Closed)
            {
                pGGrafico->fecharJanela();
            }   

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                jogador->andaPraDireta();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                jogador->andaPraEsquerda();
            }
            pGGrafico->desenhaEntidade(jogador->getcorpo());
            pGGrafico->monstraEntidade();
            pGGrafico->limpaJanela();
            pGGrafico->monstraEntidade();
        }
    }
    
   
    return 0;
}