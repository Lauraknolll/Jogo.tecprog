#pragma once
#include <SFML/Graphics.hpp>

namespace Gerenciador
{
    class GerenciadorGrafico
    {
        private:
            sf::RenderWindow *janela;

            //usando o padrão Singleton para que haja apenas uma instancia do gerenciador grafico
            static GerenciadorGrafico* pInstanciaGG;
            GerenciadorGrafico(); //constutora privada
        public:
            ~GerenciadorGrafico();
            //parte do Singleton
            static GerenciadorGrafico* getGerenciadorGrafico(); 
            //retorna a janela
            sf::RenderWindow* getJanela(); 
            void limpaJanela();
            //chama o draw
            void desenhaEntidade(sf::RectangleShape corpo); 
            //chama o display
            void monstraEntidade(); 
            void fecharJanela();
            const bool verificarJanelaAberta();
            //faltam métodos pra setar texturas
    };
}