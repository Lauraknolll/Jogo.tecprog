#pragma once

#include "Obstaculo.h"
#include "../Personagens/Personagem.h"


    class Plataforma : public Obstaculo{
        private:
        public:
            Plataforma(float x = 0, float y = 0);
            ~Plataforma();
            virtual void executar(float dt);
            virtual void imprimir(Gerenciador::GerenciadorGrafico *gG);
            virtual const int getTipo() const;
            virtual void colide(Entidade* outraEntidade, CoordF intersepta);
            void obstacular(Personagem* pP, int dir);
    };
