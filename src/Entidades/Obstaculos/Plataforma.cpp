#include "../../../include/Entidades/Obstaculos/Plataforma.h"
#include "../../../include/Gerenciador/GerenciadorGrafico.h"

#define GRAVIDADE 0.0001f
#define FORÇA_SUSTENTAÇÃO -0.0001f

Obstaculos::Plataforma::Plataforma(float x, float y, float ww, float hh): 
Obstaculo(x, y, ww, hh, Entidades::plataforma)
{
    velocidade.x = 0.0f;
    velocidade.y = 0.0f;
}

Obstaculos::Plataforma::~Plataforma()
{

}

void Obstaculos::Plataforma::executar()
{
    atualizar();
}

void Obstaculos::Plataforma::imprimir(Gerenciador::GerenciadorGrafico *gG)
{
    //sf::RectangleShape r(sf::Vector2f(100.f, 100.f));
    //r.setFillColor(sf::Color::Blue);
    //r.setTexture((*gG)[5]);
    gG->desenhaEntidade(corpo);
    corpo.setTexture(gG->carregaTextura("src/chao.png"));
}

void Obstaculos::Plataforma::atualizar()
{
    velocidade.y += GRAVIDADE;
    velocidade.y += FORÇA_SUSTENTAÇÃO;
    corpo.move(velocidade.x, velocidade.y);
}

const int Obstaculos::Plataforma::getTipo() const
{
    return 0;
}

void Obstaculos::Plataforma::colide(Entidade *outraEntidade, sf::Vector2f intersecao)
{

}
void Obstaculos::Plataforma::obstacular(Personagens::Jogador* ponJogador)
{
    
}