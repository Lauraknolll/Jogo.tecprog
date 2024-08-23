#pragma once
#include "../Ente.h"
#include "../CoordTl.h"

#include <SFML/Graphics.hpp>

namespace Entidades
{

    enum ID
    {
        jogador = 0,
        plataforma,
        inimigoFacil,
        inimigoMedio
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
        Entidade(float xx = 0, float yy = 0, float ww = 50.0, float hh = 50.0);
        ~Entidade();
        virtual void executar() = 0;
        CoordF getPosicao() const;
        CoordF getTamanho() const;
        sf::RectangleShape getCorpo();
        virtual void imprimir(Gerenciador::GerenciadorGrafico *gG) = 0;
        virtual void colide(Entidade *outraEntidade, CoordF intersecao) = 0; 
        // virtual void salvar(); //tem que ser virtual pura
    };
}