#include "../../../include/Entidades/Obstaculos/Espinho.h"

Obstaculos::Espinho::Espinho(float x, float y, float ww, float hh) :
    Obstaculo(x, y, ww, hh, Entidades::espinho)
{

}

Obstaculos::Espinho::~Espinho()
{

}

void Obstaculos::Espinho::executar()
{

}

void  Obstaculos::Espinho::imprimir(Gerenciador::GerenciadorGrafico* gG)
{
    gG->desenhaEntidade(corpo);
    corpo.setTexture(gG->carregaTextura("src/espinho.png"));
}

void Obstaculos::Espinho::colide(Entidade *outraEntidade, sf::Vector2f intersecao)
{

}

void Obstaculos::Espinho::obstacular(Personagens::Jogador* ponJogador)
{
    
}

unsigned int Obstaculos::Espinho::tomarDano() const
{
    return nivelEspinhosidade;
}

