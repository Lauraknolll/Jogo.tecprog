#pragma once
#include "Ente.h"
#include "CoordTl.h"

#include <SFML/Graphics.hpp>

class Entidade : public Ente
{
    protected: 
        float x;
        float y;
        float w, h;
        sf::RectangleShape corpo;

    public:
        Entidade(float xx = 0, float yy = 0, float ww = 10.0, float hh = 10.0);
        ~Entidade();
        virtual void executar();
        CoordF getPosicao() const;
        CoordF getTamanho() const;
        void colide(Entidade* outraEntidade, CoordF intersepta);
        //virtual void salvar(); //tem que ser virtual pura
};