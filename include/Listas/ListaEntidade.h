#pragma once
#include "Lista.h"
#include "../Entidades/Entidade.h"

namespace Lista
{
    class ListaEntidade
    {
        private:
        Lista<Entidades::Entidade> list;

        public:
            ListaEntidade();

            ~ListaEntidade();

            void addEntidade(Entidades::Entidade* pEntidade);

            Entidades::Entidade* removeEntidade(Entidades::Entidade* pEntidade);

            Entidades::Entidade* removeEntidade(unsigned int indice);

            void deleteEntidade(Entidades::Entidade* pEntidade);

            void deleteEntidade(unsigned int indice);

            unsigned int getTam();

            Entidades::Entidade* operator[](int indice);

            void cleanList();

            void percorrerLista();

            void desenharEntidades(Gerenciador::GerenciadorGrafico* pGG);
    };
}