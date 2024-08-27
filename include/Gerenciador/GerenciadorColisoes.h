#pragma once

#include <iostream>

#include "../Entidades/Entidade.h"
#include "../Entidades/Personagens/Personagem.h"
#include "../Listas/ListaEntidade.h"

namespace States {
    class Level;
} // namespace States

namespace Gerenciador
{
    class GerenciadorColisoes {
    private:
        Lista::ListaEntidade* Jogador;
        Lista::ListaEntidade* Obstaculos;
        Lista::ListaEntidade* Inimigos;
        //States::Level* plvl;

    public:
        GerenciadorColisoes(Lista::ListaEntidade* Jogador1, Lista::ListaEntidade* Obstaculos1, Lista::ListaEntidade* Inimigos1/*, States::Level* plvl*/);

        ~GerenciadorColisoes();

        void colide();

        void clear();
    };
}
