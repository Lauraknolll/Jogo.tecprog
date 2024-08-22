#include "../../include/Listas/ListaEntidade.h"

namespace Lista {

    ListaEntidade::ListaEntidade() { }

    ListaEntidade::~ListaEntidade() {
        list.clear();
    }

    void ListaEntidade::addEntidade(Entidade* pEntidade) {
        if (pEntidade == nullptr)
            std::cout << "Pointer to Entidade nullptr on addEntidade" << std::endl;

        list.push(pEntidade);
    }

    Entidade* ListaEntidade::removeEntidade(Entidade* pEntidade) {
        if (pEntidade == nullptr)
            std::cout << "Pointer to Entidade nullptr on removeEntidade" << std::endl;

        return list.pop(pEntidade);
    }

    Entidade* ListaEntidade::removeEntidade(unsigned int index) {
        return list.pop(index);
    }

    void ListaEntidade::deleteEntidade(Entidade* pEntidade) {
        Entidade* tmp = nullptr;

        tmp = list.pop(pEntidade);

        if (pEntidade)
            delete (pEntidade);
    }

    void ListaEntidade::deleteEntidade(unsigned int index) {
        Entidade* tmp = nullptr;

        tmp = list.pop(index);

        if (tmp)
            delete (tmp);
    }

    unsigned int ListaEntidade::getSize() {
        return list.getSize();
    }

    Entidade* ListaEntidade::operator[](int index) {
        return list[index];
    }

    void ListaEntidade::cleanList(){
        list.clear();
    }

} // namespace List