#pragma once
#include "../Ente.h"

#include <SFML/Graphics.hpp>

namespace Entidades
{

    enum ID
    {
        vazio = 0,
        jogador,
        plataforma,
        lava,
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
        Entidade(float xx = 0, float yy = 0, float ww = 50.0, float hh = 50.0, ID idd = vazio);
        virtual ~Entidade();
        virtual void executar() = 0;
        sf::Vector2f getPosicao() const;
        sf::Vector2f getTamanho() const;
        ID getID();
        sf::RectangleShape getCorpo();
        virtual void imprimir(Gerenciador::GerenciadorGrafico *gG) = 0;
        virtual void colide(Entidade *outraEntidade, sf::Vector2f intersecao) = 0; 
        // virtual void salvar(); //tem que ser virtual pura
    };
}