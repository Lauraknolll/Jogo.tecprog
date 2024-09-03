//codigo usado de referencia proveniente de https://github.com/MatheusBurda/Desert/tree/master
#pragma once

#include "../Estados/Estados.h"
#include "../Estados/Mediator.h"
#include <map>


namespace Gerenciador
{

    class GerenciadorEstado : public Estados::Mediator
    {
    protected:
        Estados::EstadoID estadoAtualID;
        Estados::EstadoID ultEstadoID;

        std::map<Estados::EstadoID, Estados::Estado*> mapaEstado;

    public:
        GerenciadorEstado();

        virtual ~GerenciadorEstado();

        void mudarEstadoAtual(Estados::EstadoID id);

        void atualizarEstadoAtual();

        void renderEstadoAtual();

        Estados::EstadoID getEstadoAtualID() const;

        void inserirEstado(Estados::Estado* pestado);

        Estados::EstadoID getUltEstadoID() const;
    };

}