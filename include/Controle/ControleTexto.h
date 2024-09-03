//codigo usado de referencia proveniente de https://github.com/MatheusBurda/Desert/tree/master
#pragma once

#include "Observador.h"

namespace Controle {
    
    class ControleTexto : public Observador {
    private:
        std::string texto;

    public:
        ControleTexto();

        ~ControleTexto();

        void anunciaPressionado(std::string key);

        void anunciaSolto(std::string key);

        std::string getString() const;

        void reset();

    };

} 