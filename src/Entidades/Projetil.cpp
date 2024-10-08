#include "../../include/Entidades/Projetil.h"

#define VELOCIDADE_PROJ 0.05f

Entidades::Projetil::Projetil(float xx, float yy, float ww, float hh, int direcao) :
    Entidade(xx, yy, ww, hh, Entidades::ID::projetil), colidiu(false)
{
    velocidade.x = VELOCIDADE_PROJ;
    dano = rand()%10;
    dir = direcao;
}

Entidades::Projetil::~Projetil()
{

}

void Entidades::Projetil::executar()
{
    atualizarPosicao();
}

void Entidades::Projetil::desenhar(Gerenciador::GerenciadorGrafico* gG)
{
    if(!colidiu)
    {
        gG->desenhaEntidade(corpo);
        corpo.setTexture(gG->carregaTextura("imagens/projetil.png"));
    }
}

void Entidades::Projetil::atualizarPosicao()
{
    velocidade.y += GRAVIDADE;
    velocidade.y += FORCA_SUSTENTACAO;
    if(dir == 1)
        corpo.move(velocidade.x, 0.0f);
    else
        corpo.move(-velocidade.x, 0.0f);
}

void Entidades::Projetil::colide(Entidade *outraEntidade, sf::Vector2f intersecao)
{
    if(outraEntidade->getID() == Entidades::jogador)
    {
        colidiu = true;
    }
}

