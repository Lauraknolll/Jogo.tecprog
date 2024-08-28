#include "../../include/Listas/ListaEntidade.h"

namespace Lista {

    ListaEntidade::ListaEntidade() { }

    ListaEntidade::~ListaEntidade() {
        list.clear();
    }

    void ListaEntidade::addEntidade(Entidades::Entidade* pEntidade) {
        if (pEntidade == nullptr)
            std::cout << "Pointer to Entidade nullptr on addEntidade" << std::endl;

        list.push(pEntidade);
    }

    Entidades::Entidade* ListaEntidade::removeEntidade(Entidades::Entidade* pEntidade) {
        if (pEntidade == nullptr)
            std::cout << "Pointer to Entidade nullptr on removeEntidade" << std::endl;

        return list.pop(pEntidade);
    }

    Entidades::Entidade* ListaEntidade::removeEntidade(unsigned int index) {
        return list.pop(index);
    }

    void ListaEntidade::deleteEntidade(Entidades::Entidade* pEntidade) {
        Entidades::Entidade* tmp = nullptr;

        tmp = list.pop(pEntidade);

        if (pEntidade)
            delete (pEntidade);
    }

    void ListaEntidade::deleteEntidade(unsigned int index) {
        Entidades::Entidade* tmp = nullptr;

        tmp = list.pop(index);

        if (tmp)
            delete (tmp);
    }

    unsigned int ListaEntidade::getSize() {
        return list.getSize();
    }

    Entidades::Entidade* ListaEntidade::operator[](int index) {
        return list[index];
    }

    void ListaEntidade::cleanList(){
        list.clear();
    }

    void ListaEntidade::percorrerLista()
    {
        int tam = list.getSize();
        Entidades::Entidade* paux = nullptr;
        for(int i = 0; i < tam; i++)
        {
            paux = list.operator[](i);
            if(paux)
            {
                paux->executar();
            }
        }
    }

    void ListaEntidade::desenharEntidades(Gerenciador::GerenciadorGrafico* pGG)
    {
        int tam = list.getSize();
        Entidades::Entidade* paux = nullptr;
        for(int i = 0; i < tam; i++)
        {
            paux = list.operator[](i);
            if(paux)
            {
                paux->imprimir(pGG);
            }
        }
    }


} // namespace List