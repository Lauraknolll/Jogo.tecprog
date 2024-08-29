#pragma once

#include "Gerenciador/GerenciadorGrafico.h"

class Ente
{
    protected:
        int id;
        //static Gerenciador::GerenciadorGrafico* pGGrafico;
    public:
        Ente();

        virtual ~Ente();

        virtual void executar() = 0;
        
        void desenhar();
};


