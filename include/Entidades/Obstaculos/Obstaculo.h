#pragma once

#include "../Entidade.h"
#include "../Personagens/Jogador.h"
#include "../../Gerenciador/GerenciadorGrafico.h"

namespace Obstaculos
{
    class Obstaculo : public Entidades::Entidade
    {
    protected:
        //tem que colocar algum atributo
    public:
        Obstaculo(float xxx = 0.f, float y = 0.f, float ww = 100.f, float hh = 100.f, Entidades::ID id = Entidades::vazio);

        virtual ~Obstaculo();

        virtual void executar() = 0;

        virtual void imprimir(Gerenciador::GerenciadorGrafico *gG) = 0;

        virtual int const getTipo() const;

        virtual void colide(Entidade *outraEntidade, sf::Vector2f intersecao) = 0;
        
        virtual void obstacular(Personagens::Jogador* pontJogador) = 0;
    };
}
