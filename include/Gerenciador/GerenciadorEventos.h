#pragma once

#include "GerenciadorGrafico.h"
#include "../Entidades/Personagens/Jogador.h"


namespace Gerenciador
{
    class GerenciadorEvento
    {
        private:
        GerenciadorGrafico* pGGrafico;
        Personagens::Jogador* pontJog1;
        /* Usando o padrão de projeto Singleton para que haja apenas uma instancia do gerenciador gráfico */
        static GerenciadorEvento* pInstanciaGE;
        GerenciadorEvento();
        public:
        ~GerenciadorEvento();
        /* Parte do Singleton */
        //void setJogador(Jogador jog);
        static GerenciadorEvento* getGerenciadorEventos();
        void setGerenciadosGrafico(GerenciadorGrafico* pGG);
        void setJogador(Personagens::Jogador* jog);
        void executar(sf::Event evento);
    };
}