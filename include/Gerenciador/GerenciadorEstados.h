#pragma once

#include "../Estados/Estados.h"
#include "../Estados/Mediator.h"
#include <map>

namespace Estados 
{

    class GerenciadorEstado : public Mediator
    {
    protected:
        EstadoID estadoAtualID;
        EstadoID ultEstadoID;

        std::map<EstadoID, Estado*> mapaEstado;

    public:
        GerenciadorEstado();

        virtual ~GerenciadorEstado();

        void mudarEstadoAtual(EstadoID id);

        void atualizarEstadoAtual();

        void renderEstadoAtual();

        EstadoID getEstadoAtualID() const;

        void inserirEstado(Estado* pestado);

        EstadoID getUltEstadoID() const;
    };

}