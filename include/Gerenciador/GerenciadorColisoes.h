#pragma once

#include <iostream>
#include <list>
#include <vector>
using namespace std;

#include "../Entidades/Entidade.h"
#include "../Entidades/Personagens/Personagem.h"
#include "../Entidades/Personagens/Inimigo.h"
#include "../Listas/ListaEntidade.h"

namespace Gerenciador
{
    class GerenciadorColisoes {
    private:
        list<Entidades::Entidade*> *Jogadores;
        list<Entidades::Entidade*> *Obstaculos;
        vector<Entidades::Entidade*> *Inimigos;

    public:
        GerenciadorColisoes(list<Entidades::Entidade*> *Jogador1, list<Entidades::Entidade*> *Obstaculos1, vector<Entidades::Entidade*> *Inimigos1);

        ~GerenciadorColisoes();

        void tratarColisoesJogadoresObstaculos();

        void tratarColisoesJogadoresInimigos();

        void colide();
    };
}
