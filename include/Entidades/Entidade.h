#pragma once
#include "../Ente.h"

#include <SFML/Graphics.hpp>

#define GRAVIDADE 0.0001f
#define FORCA_SUSTENTACAO -0.0001f

namespace Entidades
{

    enum ID
    {
        vazio = 0,
        jogador,
        plataforma,
        projetil,
        pedra,
        lava,
        espinho,
        fantasma,
        galinha, 
        rino
    };

    class Entidade : public Ente
    {
    protected:
        float x;
        float y;
        float w, h;
        ID id;
        sf::RectangleShape corpo;
        sf::Vector2f velocidade;

    public:
        Entidade();

        Entidade(float xx = 0, float yy = 0, float ww = 50.0, float hh = 50.0, ID idd = vazio);

        virtual ~Entidade();

        sf::Vector2f getPosicao() const;

        sf::Vector2f getTamanho() const;

        ID getID() const;

        sf::RectangleShape getCorpo() const;

        virtual void executar() = 0;

        virtual void desenhar(Gerenciador::GerenciadorGrafico *gG) = 0;
        
        virtual void colide(Entidade *outraEntidade, sf::Vector2f intersecao) = 0; 
    };
}