#include "../../../include/Entidades/Personagens/Jogador.h"

Personagens::Jogador::Jogador() :
    Personagem()
{
    corpo.setFillColor(sf::Color::Blue);
    corpo.setOrigin(sf::Vector2f(-100.0f, -400.0f));
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
}

void Personagens::Jogador::andaPraEsquerda()
{
    corpo.move(sf::Vector2f(-velocidade.x, 0.0f));
}

const sf::RectangleShape Personagens::Jogador::getcorpo()
{
    return corpo;
}

void Personagens::Jogador::imprimir(Gerenciador::GerenciadorGrafico *gG)
{
    gG->desenhaEntidade(corpo);
}

void Personagens::Jogador::colide(Entidades::Entidade *outraEntidade, CoordF intersecao)
{
    CoordF posicaoOutro = outraEntidade->getPosicao();

    if(intersecao.x > intersecao.y) // colisao em x
    {
        if(x < posicaoOutro.x)
        {
            x += intersecao.x;
            corpo.setPosition(x, y);
        }
        else
        {
            x -= intersecao.x;
            corpo.setPosition(x, y);
        }
        velocidade.x = 0.0f;
    }

    else // colisao em y
    {
        if(y < posicaoOutro.y)
        {
            y += intersecao.y;
            corpo.setPosition(x, y);
        }
        else
        {
            y -= intersecao.y;
            corpo.setPosition(x, y);
        }
        velocidade.y = 0.0f;
    }
}