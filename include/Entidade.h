#pragma once
#include "Ente.h"

#include <SFML/Graphics.hpp>

class Entidade : public Ente
{
    public: //absurdo porém só pra teste
        float x;
        float y;
        sf::RectangleShape corpo;

    public:
        Entidade(float xx = 0, float yy = 0, float ww = 10.0, float hh = 10.0);
        ~Entidade();
        virtual void executar() = 0;
        virtual void salvar(); //tem que ser virtual pura
};