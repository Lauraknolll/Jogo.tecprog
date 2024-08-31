#pragma once

#include "Gerenciador/GerenciadorGrafico.h"

class Ente
{
    protected:
        int id;
        static Gerenciador::GerenciadorGrafico* pPrincipalGGrafico;
    public:
        Ente();

        virtual ~Ente();

        virtual void executar() = 0;
        
        virtual void imprimir();
};


