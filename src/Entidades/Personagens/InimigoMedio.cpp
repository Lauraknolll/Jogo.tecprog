#include "../../../include/Entidades/Personagens/InimigoMedio.h"

Personagens::InimigoMedio::InimigoMedio() :
    Inimigo()
{
    corpo.setFillColor(sf::Color::Yellow);
    corpo.setOrigin(sf::Vector2f(-150.0f, -400.0f));
}

Personagens::InimigoMedio::~InimigoMedio()
{

}

void Personagens::InimigoMedio::setJogador(Personagens::Jogador* pJ)
{
    if(pJ)
    {
        jogador = pJ;
    }
}

void Personagens::InimigoMedio::executar()
{
    sf::Vector2f posicaoJogador = jogador->getcorpo().getPosition();
    sf::Vector2f posicaoInimigo = corpo.getPosition();

    if(fabs(posicaoJogador.x - posicaoInimigo.x) <= RAIO_PERSEGUIR_X)
    {
        persegueJogador(posicaoJogador, posicaoInimigo);
    }
}

void Personagens::InimigoMedio::persegueJogador(sf::Vector2f posJog, sf::Vector2f posIni)
{
    float tempo = relogio.getElapsedTime().asSeconds();

    if((posJog.x - posIni.x) > 0.0f)
    {
        corpo.move((velocidade.x * tempo), 0.0f);
    }
    else
    {
        corpo.move(-velocidade.x, 0.0f);
    }
}

const sf::RectangleShape Personagens::InimigoMedio::getCorpo()
{
    return corpo;
}

void Personagens::InimigoMedio::colide(Entidades::Entidade *outraEntidade, CoordF intersepta)
{

}