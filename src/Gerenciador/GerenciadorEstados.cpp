#include "../../include/Gerenciador/GerenciadorEstados.h"

Estados::GerenciadorEstado::GerenciadorEstado()
{
    ultEstadoID = EstadoID::unknown;
    atualEstadoID = EstadoID::unknown;
}

Estados::GerenciadorEstado::~GerenciadorEstado()
{
    std::map<EstadoID, Estado*>::iterator it;

    for (it = mapaEstado.begin(); it != mapaEstado.end(); ++it) {
        delete (it->second);
    }
}

void Estados::GerenciadorEstado::changeAtualEstado(EstadoID id)
{
    ultEstadoID = atualEstadoID;
    atualEstadoID = id;
    mapaEstado[atualEstadoID]->resetEstado();
}

void Estados::GerenciadorEstado::updateAtualEstado()
{
    mapaEstado[atualEstadoID]->atualizar();
}

void Estados::GerenciadorEstado::renderAtualEstado()
{
    mapaEstado[atualEstadoID]->render();
}

Estados::EstadoID Estados::GerenciadorEstado::getAtualEstadoID() const
{
    return atualEstadoID;
}

void Estados::GerenciadorEstado::inserirEstado(Estado* pEstado)
{
    //mapaEstado.insert(pEstado->getID(), pEstado);
}

Estados::EstadoID Estados::GerenciadorEstado::getUltEstadoID() const
{
    return ultEstadoID;
}