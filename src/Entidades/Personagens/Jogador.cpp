#include "../../../include/Entidades/Personagens/Jogador.h"
#include <iostream>
using namespace std;

Personagens::Jogador::Jogador() :
    Personagem()
{
    corpo.setFillColor(sf::Color::Blue);
    corpo.setPosition(200.0, 340.0);
    velocidade.x = 1.0f;
    velocidade.y = 0.0f;
}

Personagens::Jogador::~Jogador()
{

}

void Personagens::Jogador::executar()
{
    corpo.setFillColor(sf::Color::Magenta);
}

void Personagens::Jogador::andaPraDireta()
{
    corpo.move(sf::Vector2f(velocidade.x, 0.0f));
    x = corpo.getPosition().x;
}

void Personagens::Jogador::andaPraEsquerda()
{
    corpo.move(sf::Vector2f(-velocidade.x, 0.0f));
    x = corpo.getPosition().x;
}


void Personagens::Jogador::imprimir(Gerenciador::GerenciadorGrafico *gG)
{
    gG->desenhaEntidade(corpo);
}

void Personagens::Jogador::colide(Entidades::Entidade *outraEntidade, sf::Vector2f intersecao)
{
    sf::Vector2f posicaoOutro = outraEntidade->getCorpo().getPosition();

    if(intersecao.x > intersecao.y) // colisao em x
    {
        if(x < posicaoOutro.x)
        {
            x += intersecao.x;
            corpo.setPosition(x, corpo.getPosition().y);
        }
        else
        {
            x -= intersecao.x;
            corpo.setPosition(x, corpo.getPosition().y);
        }
        velocidade.x = 0.0f;
    }

    else // colisao em y
    {
        if(y < posicaoOutro.y)
        {
            y += intersecao.y;
            corpo.setPosition(corpo.getPosition().x, y);
        }
        else
        {
            y -= intersecao.y;
            corpo.setPosition(corpo.getPosition().x, y);
        }
        velocidade.y = 0.0f;
    }
}