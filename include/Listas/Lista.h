#pragma once

#include <iostream>

namespace Lista 
{

    template <class TL>
    class Lista 
    {
    private:
        template <class TE>
        class Elemento 
        {
        private:
            Elemento<TE>* pProximo;
            TE* pInfo;

        public:
            Elemento() 
            {
                pProximo = nullptr;
                pInfo = nullptr;
            }

            ~Elemento() 
            {
                pProximo = nullptr;
                pInfo = nullptr;
            }

            void setProximo(Elemento<TE>* pProximo) 
            {   
                this->pProximo = pProximo; 
            }

            Elemento<TE>* getProximo() 
            { 
                return pProximo; 
            }

            void setInfo(TE* pInfo) 
            { 
                this->pInfo = pInfo; 
            }

            TE* getInfo() 
            { 
                return pInfo; 
            }
        }; // fim da class Elemento

        Elemento<TL>* pPrimeiro;
        Elemento<TL>* pUltimo;
        unsigned int tam;

    public:
        Lista();
        ~Lista();

        void clear();
        unsigned int getTam() { return tam; }
        TL* operator[](int x);
        void push(TL* pInfo);
        TL* pop(TL* pInfo);
        TL* pop(int index);

    private:
        void setElemento(Elemento<TL>* pElemento);
        Elemento<TL>* getpPrimeiro() { return pPrimeiro; }
        Elemento<TL>* getpUltimo() { return pUltimo; }
    }; // fim da class Lista

    template <class TL>
    Lista<TL>::Lista() :
        pPrimeiro(nullptr), pUltimo(nullptr), tam(0) 
    { }

    template <class TL>
    Lista<TL>::~Lista() 
    { }

    template <class TL>
    void Lista<TL>::clear() 
    {
        Elemento<TL>* paux1;
        Elemento<TL>* paux2;

        paux1 = pPrimeiro;
        paux2 = paux1;
        int i = 0;

        while (paux1 != nullptr && i < tam) 
        {
            delete (paux1->getInfo());
            paux2 = paux1->getProximo();
            delete (paux1);
            paux1 = paux2;
            i++;
        }

        pPrimeiro = nullptr;
        pUltimo = nullptr;
        tam = 0;
    }

    template <class TL>
    void Lista<TL>::setElemento(Elemento<TL>* pElemento) 
    {
        if (pElemento != nullptr) 
        {
            if (pPrimeiro == nullptr) 
            {
                pPrimeiro = pElemento;
                pUltimo = pElemento;
            } 
            else 
            {
                pUltimo->setProximo(pElemento);
                pUltimo = pElemento;
            }
            tam++;

        } 
        else 
        {
            std::cout << "ERRO: ponteiro nulo" << std::endl;
        }
    }

    template <class TL>
    TL* Lista<TL>::operator[](int index) 
    {
        if (index >= tam || index < 0) 
        {
            std::cout << "ERRO : Limite excedido. Index " << index << " de " << tam << " elementos." << std::endl;
            exit(1);
        }

        Elemento<TL>* pAux = pPrimeiro;
        for (int i = 0; i < index; i++) 
        {
            pAux = pAux->getProximo();
        }

        if (pAux == nullptr) 
        {
            std::cout << "ERRO : ponteiro nulo." << std::endl;
            exit(1);
        }
        return pAux->getInfo();
    }

    template <class TL>
    void Lista<TL>::push(TL* pInfo) 
    {
        if (pInfo != nullptr) 
        {
            Elemento<TL>* pElemento = nullptr;
            pElemento = new Elemento<TL>();
            pElemento->setInfo(pInfo);
            setElemento(pElemento);
        }

        else 
        {
            std::cout << "ERRO : ponteiro nulo." << std::endl;
        }
    }

    template <class TL>
    TL* Lista<TL>::pop(TL* pInfo) 
    {
        Elemento<TL>* pAux = pPrimeiro;
        Elemento<TL>* pAnte = nullptr;
        while (pAux != nullptr) 
        {
            if (pAux->getInfo() == pInfo) 
            {
                if (pAux == pPrimeiro) 
                {
                    pPrimeiro = pAux->getProximo();
                } //
                else if (pAux == pUltimo) 
                {
                    pUltimo = pAnte;
                    pAnte->setProximo(nullptr);
                } //
                else 
                {
                    pAnte->setProximo(pAux->getProximo());
                }

                delete (pAux);
                tam--;
                return pInfo;
            }

            pAnte = pAux;
            pAux = pAux->getProximo();
        }
        return nullptr;
    }

    template <class TL>
    TL* Lista<TL>::pop(int index) 
    {
        if (index >= tam || index < 0) 
        {
            std::cout << "ERRO : Limite excedido. Index " << index << " de " << tam << " elementos." << std::endl;
            exit(1);
        }

        Elemento<TL>* pAux = pPrimeiro;
        Elemento<TL>* pAnte = nullptr;

        for (int i = 0; i < index; i++) 
        {
            pAnte = pAux;
            pAux = pAux->getProximo();
        }

        if (pAux == pPrimeiro) 
        {
            pPrimeiro = pAux->getProximo();
        } //
        else if (pAux == pUltimo) 
        {
            pUltimo = pAnte;
            pAnte->setProximo(nullptr);
        } //
        else 
        {
            pAnte->setProximo(pAux->getProximo());
        }

        TL* pInfo = pAux->getInfo();

        delete (pAux);
        tam--;

        return pInfo;
    }

} 