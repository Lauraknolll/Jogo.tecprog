#pragma once

#include "Fase.h"

namespace Fases
{
    class Fase1 : public Fase
    {
        private:
        public:
            Fase1();
            ~Fase1();
            void criarInimigosFaceis();
            void criarObstaculosFaceis();
    };
}