#include "../../include/Estados/Estados.h"
#include "../../include/Gerenciador/GerenciadorEstados.h"

namespace Estados 
{

    Estado::Estado(GerenciadorEstado* pGEstado, EstadoID id) :
        pGEstado(pGEstado), id(id)
    {

    }

    Estado::~Estado()
    {
        pGEstado = nullptr;
    }

    void Estado::setGerenciadorEstados(GerenciadorEstado* pGEstado1)
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