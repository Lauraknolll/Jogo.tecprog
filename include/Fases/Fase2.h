#pragma once

#include "Fase.h"

namespace Fases
{
    class Fase2 : public Fase
    {
        private:
        public:
            Fase2();
            ~Fase2();
            void executar();
            void cria();

            void criarJogadores();

            void criarChefao(); //Inimigo dificil
            void criarObstaculosDificeis();
            void criarInimigosMedios();
            void criarPlataformas(); //Obstaculo médio
    };
}