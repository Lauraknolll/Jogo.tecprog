#include "../../../include/Entidades/Obstaculos/Lava.h"

#define CAMINHO_TEXTURA "imagens/chao.png"


Obstaculos::Lava::Lava(float x, float y, float ww, float hh):
Obstaculo(x, y, ww, hh, Entidades::lava)
{
    danosidade = rand()%35;

    textura.loadFromFile(CAMINHO_TEXTURA);
    textura.setRepeated(true);

    corpo.setTexture(&textura);
    corpo.setTextureRect(sf::IntRect(0, 0, 800, 800));
}

Obstaculos::Lava::~Lava()
{

}

void Obstaculos::Lava::executar()
{
    atualizarPosicao();
}

void Obstaculos::Lava::desenhar(Gerenciador::GerenciadorGrafico* gG)
{
    gG->desenhaEntidade(corpo);
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