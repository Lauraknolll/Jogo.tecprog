#pragma once

#include "../Estados/Estados.h"
#include <map>

namespace Estados {

    class GerenciadorEstado {
    protected:
        EstadoID atualEstadoID;
        EstadoID ultEstadoID;

        std::map<EstadoID, Estado*> mapaEstado;

    public:
        GerenciadorEstado();

        virtual ~GerenciadorEstado();

        void changeAtualEstado(EstadoID id);

        void updateAtualEstado();

        void renderAtualEstado();

        EstadoID getAtualEstadoID() const;

        void inserirEstado(Estado* pestado);

        EstadoID getUltEstadoID() const;
    };

}