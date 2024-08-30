#include "../../include/Controle/Observador.h"

namespace Controle {

    Observador::Observador()
    {
        this->pGInput = Gerenciador::GerenciadorInput::getGerenciadorInput();
        pGInput->Attach(this);
    }

    Observador::~Observador() 
    {
        pGInput->Detach(this);
    }

}