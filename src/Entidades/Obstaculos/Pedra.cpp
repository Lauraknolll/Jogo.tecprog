#include "../../../include/Entidades/Obstaculos/Pedra.h"

Obstaculos::Pedra::Pedra(float x, float y, float ww, float hh) :
    Obstaculo(x, y, ww, hh, Entidades::pedra)
{
    lentidao = 0;
    dureza = rand()%15;
}

Obstaculos::Pedra::~Pedra()
{

}

void Obstaculos::Pedra::executar()
{
    atualizarPosicao();
}

void Obstaculos::Pedra::desenhar(Gerenciador::GerenciadorGrafico* gG)
{
    gG->desenhaEntidade(corpo);
    corpo.setTexture(gG->carregaTextura("imagens/pedra.png"));
}

void Obstaculos::Pedra::colide(Entidade *outraEntidade, sf::Vector2f intersecao)
{
    if(outraEntidade->getID() == Entidades::ID::jogador)
    {
        obstacular(static_cast<Personagens::Jogador*>(outraEntidade));
    }
}

void Obstaculos::Pedra::obstacular(Personagens::Jogador* pontJogador)
{
    pontJogador->recebaDano(dureza);
}

void Obstaculos::Pedra::atualizarPosicao()
{
    velocidade.y += GRAVIDADE;
    velocidade.y += FORCA_SUSTENTACAO;
    corpo.move(velocidade.x, velocidade.y);
}