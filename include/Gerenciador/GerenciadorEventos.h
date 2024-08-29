#pragma once

#include "GerenciadorGrafico.h"
#include "GerenciadorInput.h"
#include "../Entidades/Personagens/Jogador.h"


namespace Gerenciador
{
    class GerenciadorEvento
    {
        private:
        bool tem_jogador;

        Gerenciador::GerenciadorInput* pInputM;

        GerenciadorGrafico* pGGrafico;
        Personagens::Jogador* pontJogador1;
        Personagens::Jogador* pontJogador2;

        /* padrão Singleton */
        static GerenciadorEvento* pInstanciaGE;
        GerenciadorEvento();
        
        public:
        ~GerenciadorEvento();

        //void setJogador(Jogador jog);
        
        static GerenciadorEvento* getGerenciadorEventos();

        void setGerenciadosGrafico(GerenciadorGrafico* pGG);

        void setJogador(Personagens::Jogador* jogador1, Personagens::Jogador* jogador2 = nullptr);
        
        void executar(sf::Event evento);
    };
}