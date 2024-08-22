#pragma once

#include "../Entidades/Entidade.h"
#include "../Listas/ListaEntidade.h"

namespace States {
    class Level;
} // namespace States



    class GerenciadorColisoes {
    private:
        Lista::ListaEntidade* movingEntities;
        Lista::ListaEntidade* staticEntities;
        States::Level* plvl;

    public:
        GerenciadorColisoes(Lista::ListaEntidade* movingEntities, Lista::ListaEntidade* staticEntities/*, States::Level* plvl*/);

        ~GerenciadorColisoes();

        void colide();

        //void clear();
    };

 // namespace Managers