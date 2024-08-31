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


            /* padrão Singleton */
            static GerenciadorGrafico* pInstanciaGG;
            GerenciadorGrafico();
        public:
            ~GerenciadorGrafico();

            static GerenciadorGrafico* getGerenciadorGrafico(); 

            sf::RenderWindow* getJanela(); 

            void limpaJanela();

            void desenhaEntidade(sf::RectangleShape corpo);

            void desenhaTexto(sf::Text texto); 

            void monstraEntidade(); 

            void fecharJanela();

            const bool verificarJanelaAberta();

            sf::Texture* carregaTextura(std::string caminho);
            
            void centralizarCamera(sf::Vector2f centro);

            sf::View getCamera();            
    };
}