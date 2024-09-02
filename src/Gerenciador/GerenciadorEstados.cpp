#include "../../include/Gerenciador/GerenciadorEstados.h"

Gerenciador::GerenciadorEstado::GerenciadorEstado()
{
    ultEstadoID = Estados::EstadoID::desconhecido;
    estadoAtualID = Estados::EstadoID::desconhecido;
}

Gerenciador::GerenciadorEstado::~GerenciadorEstado()
{
    std::map<Estados::EstadoID, Estados::Estado*>::iterator it;

    for (it = mapaEstado.begin(); it != mapaEstado.end(); ++it) {
        delete (it->second);
    }
}

void Gerenciador::GerenciadorEstado::mudarEstadoAtual(Estados::EstadoID id)
{
    ultEstadoID = estadoAtualID;
    estadoAtualID = id;
    
    mapaEstado[estadoAtualID]->resetEstado();
}

void Gerenciador::GerenciadorEstado::atualizarEstadoAtual()
{
    mapaEstado[estadoAtualID]->atualizar();
}

void Gerenciador::GerenciadorEstado::renderEstadoAtual()
{
    mapaEstado[estadoAtualID]->render();
}

Estados::EstadoID Gerenciador::GerenciadorEstado::getEstadoAtualID() const
{
    return estadoAtualID;
}

void Gerenciador::GerenciadorEstado::inserirEstado(Estados::Estado* pEstado)
{
    mapaEstado.insert(std::make_pair(pEstado->getID(), pEstado));
}

Estados::EstadoID Gerenciador::GerenciadorEstado::getUltEstadoID() const
{
    return ultEstadoID;
}