#pragma once
#include "Lista.h"
#include "../Entidades/Entidade.h"

namespace Lista{
    class ListaEntidade{
        private:
        Lista<Entidades::Entidade> list;

        public:
            ListaEntidade();

            ~ListaEntidade();

            void addEntidade(Entidades::Entidade* pEntidade);

            Entidades::Entidade* removeEntidade(Entidades::Entidade* pEntidade);

            Entidades::Entidade* removeEntidade(unsigned int index);

            void deleteEntidade(Entidades::Entidade* pEntidade);

            void deleteEntidade(unsigned int index);

            unsigned int getSize();

            Entidades::Entidade* operator[](int index);

            void cleanList();

            void percorrerLista();

            void desenharEntidades(Gerenciador::GerenciadorGrafico* pGG);

    };
}