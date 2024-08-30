#pragma once

#include "Observador.h"

namespace Fases {
    class Fase;
} // namespace Fase

namespace Controle {

    class ControleFase : public Observador {
    private:
        Fases::Fase* pFase;

    public:
        ControleFase(Fases::Fase* pM = NULL);

        ~ControleFase();

        void anunciaPressionado(std::string key);
        
        void anunciaSolto(std::string key);

        void setFase(Fases::Fase* p);
    };

} // namespace Control