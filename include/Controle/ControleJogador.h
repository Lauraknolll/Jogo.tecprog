#pragma once

#include "Observador.h"
#include <map>

namespace Personagens {
    class Jogador;
}

namespace Controle {

    class ControleJogador : public Observador {
    private:
        Personagens::Jogador* pJogador;
        std::map<std::string, bool> teclasPrecionadas;
        std::string pul;
        std::string esq;
        std::string dir;
        std::string ata;

    public:
        ControleJogador(Personagens::Jogador* pP = nullptr);

        ~ControleJogador();

        void anunciaPressionado(std::string key);

        void anunciaSolto(std::string key);

        void setJogador(Personagens::Jogador* p);

        void setKeys(std::string pular, std::string direita, std::string esquerda, std::string ataque);
    };

} // namespace Control