//codigo usado de referencia proveniente de https://github.com/MatheusBurda/Desert/tree/master
#include "../../include/Estados/Estados.h"
#include "../../include/Estados/Mediator.h"

namespace Estados 
{

    Estado::Estado(Mediator* pGEstado, EstadoID id) :
        pGEstado(pGEstado), id(id)
    {

    }

    Estado::~Estado()
    {
        pGEstado = nullptr;
    }

    void Estado::setMediator(Mediator* pGEstado1)
    {
        this->pGEstado = pGEstado1;
    }

    void Estado::changeEstado(EstadoID id1)
    {
        pGEstado->mudarEstadoAtual(id1);
    }

    EstadoID Estado::getID() const
    {
        return id;
    }
} 