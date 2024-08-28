#pragma once
#include "Inimigo.h"

namespace Personagens
{
    class Chefao : public Inimigo
    {
        private:
        public:
            Chefao();
            ~Chefao();
            void executar();
            void imprimir(Gerenciador::GerenciadorGrafico* gG);
            void colide();
            void danificar();
    };
}