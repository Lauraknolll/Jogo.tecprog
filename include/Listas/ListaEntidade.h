#include "Lista.h"
#include "../Entidade.h"

namespace Lista{
    class ListaEntidade{
        private:
        Lista<Entidade> list;

        public:
            ListaEntidade();

            ~ListaEntidade();

            void addEntidade(Entidade* pEntidade);

            Entidade* removeEntidade(Entidade* pEntidade);

            Entidade* removeEntidade(unsigned int index);

            void deleteEntidade(Entidade* pEntidade);

            void deleteEntidade(unsigned int index);

            unsigned int getSize();

            Entidade* operator[](int index);

            void cleanList();
    };
}