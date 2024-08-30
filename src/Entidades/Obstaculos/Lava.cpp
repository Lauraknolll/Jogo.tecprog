#include "../../../include/Entidades/Obstaculos/Lava.h"


Obstaculos::Lava::Lava(float x, float y, float ww, float hh):
Obstaculo(x, y, ww, hh, Entidades::lava)
{
    corpo.setFillColor(sf::Color::Red);
    danosidade = rand()%35;
}

Obstaculos::Lava::~Lava()
{

}

void Obstaculos::Lava::executar()
{
    atualizarPosicao();
}

void Obstaculos::Lava::imprimir(Gerenciador::GerenciadorGrafico* gG){
    gG->desenhaEntidade(corpo);
}

unsigned int Obstaculos::Lava::tomarDano() const //pra que essa função?
{
    return danosidade;
}

void Obstaculos::Lava::colide(Entidade *outraEntidade, sf::Vector2f intersecao)
{
    if(outraEntidade->getID() == Entidades::ID::jogador)
    {
        obstacular(static_cast<Personagens::Jogador*>(outraEntidade));
    }
}

void Obstaculos::Lava::obstacular(Personagens::Jogador* pontJogador)
{
    pontJogador->recebaDano(danosidade);
}

void Obstaculos::Lava::atualizarPosicao()
{
    velocidade.y += GRAVIDADE;
    velocidade.y += FORCA_SUSTENTACAO;
    corpo.move(velocidade.x, velocidade.y);
}