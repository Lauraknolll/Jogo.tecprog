#pragma once

#include "Fase.h"
#include "../Estados/Estados.h"
#include "../Gerenciador/GerenciadorEstados.h"
#include "../Gerenciador/GerenciadorInput.h"
#include "../../include/Controle/ControleJogador.h"

namespace Fases
{
    class Fase2 : public Fase, public Estados::Estado
    {
        private:
            bool esta_final;
            bool t_dois;
            const int maxInimigos;
            const int maxObstaculos;
        public:
            Fase2(Estados::GerenciadorEstado* gE);

            ~Fase2();

            void executar();

            virtual void atualizar();

            void render();

            void criar();

            virtual void resetEstado();

            void criarJogadores();

            void criarPlataformas();

            void criarRinos(); //Inimigo dificil

            void criarEspinhos(); //Obstáculo difícil

            void criarGalinhas(); // Inimigo médio

            void criarLava(); //Obstáculo médio
            
            void gerenciarMortos();
    };
}