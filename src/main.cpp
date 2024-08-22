#pragma once

#include <SFML/Graphics.hpp>
#include "../include/Gerenciador/GerenciadorGrafico.h"
#include "../include/Gerenciador/GerenciadorEventos.h"
#include "../include/Jogador.h"
#include "../include/Obstaculos/Plataforma.h"

#include <iostream>
using namespace std;

int main()
{
    
    //sf::RenderWindow janela(sf::VideoMode(800, 600), "Jogo");
    
    Gerenciador::GerenciadorGrafico* pGGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
    //Gerenciador::GerenciadorEvento* pGEvento = Gerenciador::GerenciadorEvento::getGerenciadorEventos();
    
    while(pGGrafico->verificarJanelaAberta())
    {
        sf::Event evento;
        //Jogador* jogador;

        while(pGGrafico->getJanela()->pollEvent(evento))
        {   
            Plataforma* plat = new Plataforma();
            
            
            if(evento.type == sf::Event::Closed)
            {
                pGGrafico->fecharJanela();
            }   

            pGGrafico->limpaJanela();
            plat->imprimir(pGGrafico);
            //pGGrafico->desenhaEntidade(body);
            pGGrafico->monstraEntidade();
        }
    }
    
   
    return 0;
}