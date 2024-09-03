//codigo usado de referencia proveniente de https://github.com/MatheusBurda/Desert/tree/master
#pragma once

#include "Observador.h"

namespace Fases 
{
    class Fase;
} 

namespace Controle
{

    class ControleFase : public Observador 
    {
    private:
        Fases::Fase* pFase;

    public:
        ControleFase(Fases::Fase* pF = NULL);

        ~ControleFase();

        void anunciaPressionado(std::string key);
        
        void anunciaSolto(std::string key);

        void setFase(Fases::Fase* p);
    };

} 