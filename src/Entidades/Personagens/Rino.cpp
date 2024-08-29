#include "../../../include/Entidades/Personagens/Rino.h"

#define GRAVIDADE 0.0001f
#define FORÇA_SUSTENTAÇÃO -0.0001f
#define VIDAS_RINO 5000
#define VELOCIDADE_INID 0.3f
#define RAIO_PERSEGUIR_X  200.0f

Personagens::Rino::Rino(float xx, float yy, float ww, float hh) :
    Inimigo(xx, yy, ww, hh, Entidades::rino)
{
    num_vidas = VIDAS_RINO;
    velocidade.x = 0.0f;
    velocidade.y = 0.0f;
    corpo.setFillColor(sf::Color::White);
}

Personagens::Rino::~Rino()
{

}

void Personagens::Rino::imprimir(Gerenciador::GerenciadorGrafico* gG)
{
    gG->desenhaEntidade(corpo);
    corpo.setTexture(gG->carregaTextura("src/rino.png"));
}

void Personagens::Rino::executar()
{
    sf::Vector2f posicaoJogador = jogador->getCorpo().getPosition();
    sf::Vector2f posicaoInimigo = corpo.getPosition();
    atualizarPosicao();

    if(fabs(posicaoJogador.x - posicaoInimigo.x) <= RAIO_PERSEGUIR_X)
    {
        persegueJogador(posicaoJogador, posicaoInimigo);
    }
}

void Personagens::Rino::setJogador(Jogador* pJ)
{
    if(pJ)
    {
        jogador = pJ;
    }
}

void Personagens::Rino::persegueJogador(sf::Vector2f posJog, sf::Vector2f posIni)
{
    if((posJog.x - posIni.x) > 0.0f)
    {
        corpo.move(VELOCIDADE_INID, 0.0f);
    }
    else 
    {
        corpo.move(-VELOCIDADE_INID, 0.0f);
    }
}

void Personagens::Rino::colide(Entidade *outraEntidade, sf::Vector2f intersecao)
{

}

void Personagens::Rino::danificar(Personagens::Jogador* pontJogador)
{

}

int Personagens::Rino::getNumVidas()
{
   return num_vidas;
}

void Personagens::Rino::atualizarPosicao()
{
    x = corpo.getPosition().x;
    y = corpo.getPosition().y;

    velocidade.y += GRAVIDADE;
    velocidade.y += FORÇA_SUSTENTAÇÃO;
}



