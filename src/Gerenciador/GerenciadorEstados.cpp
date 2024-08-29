#include "../../include/Gerenciador/GerenciadorEstados.h"

Estados::GerenciadorEstado::GerenciadorEstado()
{
    ultEstadoID = EstadoID::desconhecido;
    estadoAtualID = EstadoID::desconhecido;
}

Estados::GerenciadorEstado::~GerenciadorEstado()
{
    std::map<EstadoID, Estado*>::iterator it;

    for (it = mapaEstado.begin(); it != mapaEstado.end(); ++it) {
        delete (it->second);
    }
}

void Estados::GerenciadorEstado::mudarEstadoAtual(EstadoID id)
{
    ultEstadoID = estadoAtualID;
    estadoAtualID = id;
    
    mapaEstado[estadoAtualID]->resetEstado();
}

void Estados::GerenciadorEstado::atualizarEstadoAtual()
{
    mapaEstado[estadoAtualID]->atualizar();
}

void Estados::GerenciadorEstado::renderEstadoAtual()
{
    mapaEstado[estadoAtualID]->render();
}

Estados::EstadoID Estados::GerenciadorEstado::getEstadoAtualID() const
{
    return estadoAtualID;
}

void Estados::GerenciadorEstado::inserirEstado(Estado* pEstado)
{
    mapaEstado.insert(std::make_pair(pEstado->getID(), pEstado));
}

Estados::EstadoID Estados::GerenciadorEstado::getUltEstadoID() const
{
    return ultEstadoID;
}