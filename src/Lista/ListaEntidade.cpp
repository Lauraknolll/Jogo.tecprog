#include "../../include/Listas/ListaEntidade.h"

namespace Lista {

    ListaEntidade::ListaEntidade() { }

    ListaEntidade::~ListaEntidade() 
    {
        list.clear();
    }

    void ListaEntidade::addEntidade(Entidades::Entidade* pEntidade) 
    {
        if (pEntidade == nullptr)
            std::cout << "ERRO : ponteiro nulo." << std::endl;
        list.push(pEntidade);
    }

    Entidades::Entidade* ListaEntidade::removeEntidade(Entidades::Entidade* pEntidade) 
    {
        if (pEntidade == nullptr)
            std::cout << "ERRO : ponteiro nulo." << std::endl;
        return list.pop(pEntidade);
    }

    Entidades::Entidade* ListaEntidade::removeEntidade(unsigned int indice) 
    {
        return list.pop(indice);
    }

    void ListaEntidade::deleteEntidade(Entidades::Entidade* pEntidade) 
    {
        Entidades::Entidade* tmp = nullptr;

        tmp = list.pop(pEntidade);

        if (pEntidade)
            delete (pEntidade);
    }

    void ListaEntidade::deleteEntidade(unsigned int indice) 
    {
        Entidades::Entidade* tmp = nullptr;

        tmp = list.pop(indice);

        if (tmp)
            delete (tmp);
    }

    unsigned int ListaEntidade::getTam() 
    {
        return list.getTam();
    }

    Entidades::Entidade* ListaEntidade::operator[](int indice) 
    {
        return list[indice];
    }

    void ListaEntidade::cleanList()
    {
        list.clear();
    }

    void ListaEntidade::percorrerLista()
    {
        int tam = list.getTam();
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
        int tam = list.getTam();
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

} 