#include "../../include/Estados/Estados.h"
#include "../../include/Gerenciador/GerenciadorEstados.h"

namespace Estados {

    Estado::Estado(GerenciadorEstado* pSM, EstadoID id):
    pSM(pSM),
    id(id)
    {

    }

    Estado::~Estado()
    {
        pSM = nullptr;
    }

    void Estado::setGerenciadorEstados(GerenciadorEstado* pSM1)
    {
        this->pSM = pSM1;
    }

    void Estado::changeEstado(EstadoID id1)
    {
        pSM->changeAtualEstado(id1);
    }

    EstadoID Estado::getID() const
    {
        return id;
    }
} // namespace Estado