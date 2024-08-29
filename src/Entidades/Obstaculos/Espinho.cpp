#include "../../../include/Entidades/Obstaculos/Espinho.h"

Obstaculos::Espinho::Espinho(float x, float y, float ww, float hh) :
    Obstaculo(x, y, ww, hh, Entidades::espinho)
{
    nivelEspinhosidade = rand()%65;
}

Obstaculos::Espinho::~Espinho()
{

}

void Obstaculos::Espinho::executar()
{
    atualizarPosicao();
}

void Obstaculos::Espinho::imprimir(Gerenciador::GerenciadorGrafico* gG)
{
    gG->desenhaEntidade(corpo);
    corpo.setTexture(gG->carregaTextura("src/espinho.png"));
}

void Obstaculos::Espinho::colide(Entidade *outraEntidade, sf::Vector2f intersecao)
{
    if(outraEntidade->getID() == Entidades::ID::jogador)
    {
        obstacular(static_cast<Personagens::Jogador*>(outraEntidade));
    }
}

void Obstaculos::Espinho::obstacular(Personagens::Jogador* pontJogador)
{
    pontJogador->recebaDano(nivelEspinhosidade);
}

unsigned int Obstaculos::Espinho::tomarDano() const
{
    return nivelEspinhosidade;
}

void Obstaculos::Espinho::atualizarPosicao()
{
    velocidade.y += GRAVIDADE;
    velocidade.y += FORCA_SUSTENTACAO;
    corpo.move(velocidade.x, velocidade.y);
}

