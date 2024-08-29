#include "../../../include/Entidades/Personagens/Chefao.h"

Personagens::Chefao::Chefao(float xx, float yy, float ww, float hh) :
    Inimigo(xx, yy, ww, hh, Entidades::chefao)
{
    velocidade.x = 0.0f;
    velocidade.y = 0.0f;
    corpo.setFillColor(sf::Color::Green);
}

Personagens::Chefao::~Chefao()
{

}

void Personagens::Chefao::imprimir(Gerenciador::GerenciadorGrafico* gG)
{
    gG->desenhaEntidade(corpo);
}

void Personagens::Chefao::executar()
{
    
}

void Personagens::Chefao::colide(Entidade *outraEntidade, sf::Vector2f intersecao)
{

}

void Personagens::Chefao::danificar(Personagens::Jogador* pontJogador)
{

}

int Personagens::Chefao::getNumVidas()
{
   return num_vidas;
}



