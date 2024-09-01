#include "../../../include/Entidades/Obstaculos/Plataforma.h"
#include "../../../include/Gerenciador/GerenciadorGrafico.h"


Obstaculos::Plataforma::Plataforma(float x, float y, float ww, float hh): 
Obstaculo(x, y, ww, hh, Entidades::plataforma)
{
    velocidade.x = 0.0f;
    velocidade.y = 0.0f;
    corpo.setFillColor(sf::Color::White);
}

Obstaculos::Plataforma::~Plataforma()
{

}

void Obstaculos::Plataforma::executar()
{
    atualizarPosicao();
}

void Obstaculos::Plataforma::desenhar(Gerenciador::GerenciadorGrafico *gG)
{
    gG->desenhaEntidade(corpo);
}

void Obstaculos::Plataforma::atualizarPosicao()
{
    velocidade.y += GRAVIDADE;
    velocidade.y += FORCA_SUSTENTACAO;
    corpo.move(velocidade.x, velocidade.y);
}



void Obstaculos::Plataforma::colide(Entidade *outraEntidade, sf::Vector2f intersecao)
{

}
void Obstaculos::Plataforma::obstacular(Personagens::Jogador* ponJogador)
{
    
}