#pragma once

#include "../Gerenciador/GerenciadorInput.h"

namespace Controle 
{

    class Observador 
    {
    private:
        Gerenciador::GerenciadorInput* pGInput;

    public:
        Observador();

        virtual ~Observador();
        
        virtual void anunciaPressionado(std::string key) = 0;

        virtual void anunciaSolto(std::string key) = 0;

    };

} 