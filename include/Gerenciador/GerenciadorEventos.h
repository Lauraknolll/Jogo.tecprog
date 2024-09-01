#pragma once

#include "GerenciadorGrafico.h"
#include "GerenciadorInput.h"
#include "../Entidades/Personagens/Jogador.h"


namespace Gerenciador
{
    class GerenciadorEvento
    {
        private:

        Gerenciador::GerenciadorInput* pInputM;
        GerenciadorGrafico* pGGrafico;

        /* padrão Singleton */
        static GerenciadorEvento* pInstanciaGE;
        GerenciadorEvento();
        
        public:
        ~GerenciadorEvento();
        
        static GerenciadorEvento* getGerenciadorEventos();

        void setGerenciadosGrafico(GerenciadorGrafico* pGG);
        
        void executar(sf::Event evento);
    };
}