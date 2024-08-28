#pragma once

#include "Fase.h"

namespace Fases
{
    class Fase1 : public Fase
    {
        private:
            bool esta_final;
            bool t_dois;
        public:
            Fase1();
            ~Fase1();
            void executar();
            void cria();

            void criarJogadores();
            void criarPlataformas();

            void criarInimigosFaceis();
            void criarObstaculosFaceis();
            void criarInimigosMedios();
            void criarObstaculosMedios();
    };
}