#include "../../include/Controle/Observador.h"

namespace Controle {

    Observador::Observador() {
        this->pIM = Gerenciador::GerenciadorInput::getGerenciadorInput();
        pIM->Attach(this);
    }

    Observador::~Observador() {
        pIM->Detach(this);
    }

}