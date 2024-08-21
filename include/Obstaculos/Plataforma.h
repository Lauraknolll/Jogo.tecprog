#pragma once

#include "Obstaculo.h"
#include "../Personagem.h"

namespace Obstaculos{
    class Plataforma : public Obstaculo{
        private:
        public:
            Plataforma(float x = 0, float y = 0);
            ~Plataforma();
            virtual void executar(float dt);
            virtual void imprimir(Gerenciador::GerenciadorGrafico *gG);
            virtual const int getTipo() const;
            void obstacular(Personagem* pP, int dir);
    };
}