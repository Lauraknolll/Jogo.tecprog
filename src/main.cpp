#include <SFML/Graphics.hpp>
#include "../include/Gerenciador/GerenciadorGrafico.h"
#include <iostream>
using namespace std;

int main()
{
    
    sf::RenderWindow janela(sf::VideoMode(800, 600), "Jogo");
/*
    while(janela.isOpen())
    {
        sf::Event evento;
        while(janela.pollEvent(evento))
        {
            if(evento.type == sf::Event::Closed)
            {
                janela.close();
            }
        }
    }
    */
    
    Gerenciador::GerenciadorGrafico* pGGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

    

    while(pGGrafico->verificarJanelaAberta())
    {
        sf::Event evento;
        while(pGGrafico->getJanela()->pollEvent(evento))
        {
            if(evento.type == sf::Event::Closed)
            {
                pGGrafico->fecharJanela();
            }
        }
        
        pGGrafico->limpaJanela();
        pGGrafico->monstraEntidade();
    }
    
   
    return 0;
}