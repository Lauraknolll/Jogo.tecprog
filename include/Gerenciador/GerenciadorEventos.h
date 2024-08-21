#pragma once

#include "GerenciadorGrafico.h"
//#include "../Jogador.h"

namespace Gerenciador
{
    class GerenciadorEvento
    {
        private:
        GerenciadorGrafico* pGGrafico;
        //Jogador* jogador;
        /* Usando o padrão de projeto Singleton para que haja apenas uma instancia do gerenciador gráfico */
        static GerenciadorEvento* pInstanciaGE;
        GerenciadorEvento();
        public:
        ~GerenciadorEvento();
        /* Parte do Singleton */
        //void setJogador(Jogador jog);
        static GerenciadorEvento* getGerenciadorEventos();
        void executar();
    };
}