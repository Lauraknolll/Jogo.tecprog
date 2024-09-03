//codigo usado de referencia proveniente de https://github.com/MatheusBurda/Desert/tree/master
#include "../../include/Controle/ControleJogador.h"

#include "../../include/Entidades/Personagens/Jogador.h"

namespace Controle {

    ControleJogador::ControleJogador(Personagens::Jogador* pJ) :
    Observador(),
    pJogador(pJ),
    teclasPrecionadas(),
    pul("W"),
    esq("A"),
    dir("D"),
    ata("S") 
    {
        teclasPrecionadas.insert(std::pair<std::string, bool>(pul, false));
        teclasPrecionadas.insert(std::pair<std::string, bool>(ata, false));
        teclasPrecionadas.insert(std::pair<std::string, bool>(dir, false));
        teclasPrecionadas.insert(std::pair<std::string, bool>(esq, false));
    }

    ControleJogador::~ControleJogador() {
        pJogador = nullptr;
    }

    void ControleJogador::anunciaPressionado(std::string key) 
    {
        if (pJogador == nullptr) 
        {
            std::cout << "ERROR: pointer to JopJogador nullptr on ControleJogador::notify()." << std::endl;
            exit(7);
        }

        if (key == ata) 
        {
            teclasPrecionadas[ata] = true;
            pJogador->atacar();
        }

        else if (key == pul) 
        {
            teclasPrecionadas[pul] = true;
            pJogador->pular();
        }

        else if (key == dir) 
        {
            teclasPrecionadas[dir] = true;
            pJogador->andar(false);
        }

        else if (key == esq) 
        {
            teclasPrecionadas[esq] = true;
            pJogador->andar(true);
        }
    }

    void ControleJogador::anunciaSolto(std::string key) 
    {
        if (pJogador == nullptr) 
        {
            std::cout << "ERRO : ponteiro nulo" << std::endl;
            exit(7);
        }

        if(key == ata) 
        {
            teclasPrecionadas[ata] = false;
            pJogador->paraAtacar();
        }

        else if (key == pul) 
        {
            teclasPrecionadas[pul] = false;
        }

        else if (key == dir) 
        {
            teclasPrecionadas[dir] = false;
            pJogador->pararAndar();
        }

        else if (key == esq) 
        {
            teclasPrecionadas[esq] = false;
            pJogador->pararAndar();
        }
    }

    void ControleJogador::setJogador(Personagens::Jogador* pJ) {
        pJogador = pJ;
    }

    void ControleJogador::setKeys(std::string pul, std::string esq, std::string dir, std::string ata) {
        this->pul = pul;
        this->esq = esq;
        this->dir = dir;
        this->ata = ata;
    }

} 