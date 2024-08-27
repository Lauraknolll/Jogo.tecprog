#pragma once

#include "SFML/Graphics.hpp"
#include <cstring>
#include <iostream>

namespace Gerenciador
{
    class GerenciadorGrafico
    {
        private:
            sf::RenderWindow *janela;
            sf::View camera;
            std::map<std::string, sf::Texture*> MapaTexturas;


            //Usando o padrão de projeto Singleton para que haja apenas uma instancia do gerenciador gráfico
            static GerenciadorGrafico* pInstanciaGG;
            GerenciadorGrafico(); //Constutora privada
        public:
            ~GerenciadorGrafico();
            //Parte do Singleton
            static GerenciadorGrafico* getGerenciadorGrafico(); 
            //Retorna a janela
            sf::RenderWindow* getJanela(); 
            void limpaJanela();
            //Chama o draw
            void desenhaEntidade(sf::RectangleShape corpo); 
            //Chama o display
            void monstraEntidade(); 
            void fecharJanela();
            const bool verificarJanelaAberta();
            //Retorna a textura 
            sf::Texture* carregaTextura(std::string caminho);
            void centralizarCamera(sf::Vector2f centro);
    };
}