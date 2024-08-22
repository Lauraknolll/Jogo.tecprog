#pragma once
#include "../Ente.h"
#include "../CoordTl.h"

#include <SFML/Graphics.hpp>

namespace Entidades
{
    class Entidade : public Ente
    {
    protected:
        float x;
        float y;
        float w, h;
        sf::RectangleShape corpo;
        sf::Vector2f velocidade;

    public:
        Entidade(float xx = 0, float yy = 0, float ww = 10.0, float hh = 10.0);
        ~Entidade();
        virtual void executar() = 0;
        CoordF getPosicao() const;
        CoordF getTamanho() const;
        virtual void colide(Entidade *outraEntidade, CoordF intersepta) = 0; 
        // virtual void salvar(); //tem que ser virtual pura
    };
}