#include <SFML/Graphics.hpp>
#include "../include/Gerenciador/GerenciadorGrafico.h"
#include "../include/Gerenciador/GerenciadorEventos.h"
//#include "../include/Jogador.h"
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
            Obstaculos::Plataforma* plat;

            sf::RectangleShape body(sf::Vector2f(100.f, 100.f));
            body.setFillColor(sf::Color::Blue);
            if(evento.type == sf::Event::Closed)
            {
                pGGrafico->fecharJanela();
            }   

            pGGrafico->limpaJanela();
            plat->imprimir(pGGrafico);
            //pGGrafico->desenhaEntidade(body);
            pGGrafico->monstraEntidade();
            printf("%f", plat->x);
        }
    }
    
   
    return 0;
}