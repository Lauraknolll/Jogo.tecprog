#include "../../../include/Entidades/Obstaculos/Lava.h"


Obstaculos::Lava::Lava(float x, float y, float ww, float hh):
Obstaculo(x, y, ww, hh, Entidades::lava)
{
    corpo.setFillColor(sf::Color::Red);
}

Obstaculos::Lava::~Lava()
{

}

void Obstaculos::Lava::executar()
{

}

void Obstaculos::Lava::imprimir(Gerenciador::GerenciadorGrafico* gG){
    gG->desenhaEntidade(corpo);
}

unsigned int Obstaculos::Lava::tomarDano() const
{
    return danosidade;
}

void Obstaculos::Lava::colide(Entidade *outraEntidade, sf::Vector2f intersecao)
{

}

void Obstaculos::Lava::obstacular(Personagens::Jogador* ponJogador)
{
    
}