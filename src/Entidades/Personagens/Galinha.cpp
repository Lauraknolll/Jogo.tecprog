#include "../../../include/Entidades/Personagens/Galinha.h"

#define GRAVIDADE 0.0001f
#define FORÇA_SUSTENTAÇÃO -0.0001f
#define VELOCIDADE_INIM 0.025f
#define VIDAS_INIM 3000

Personagens::Galinha::Galinha(float xx, float yy, float ww, float hh) :
    Inimigo(xx, yy, ww, hh, Entidades::galinha)
{
    num_vidas = VIDAS_INIM;
    corpo.setFillColor(sf::Color::White);
    velocidade.x = 0.0f;
    velocidade.y = 0.0f;
}

Personagens::Galinha::~Galinha()
{

}

void Personagens::Galinha::setJogador(Personagens::Jogador* pJ)
{
    if(pJ)
    {
        jogador = pJ;
    }
}

void Personagens::Galinha::executar()
{
    sf::Vector2f posicaoJogador = jogador->getCorpo().getPosition();
    sf::Vector2f posicaoInimigo = corpo.getPosition();
    atualizarPosicao();

    if(fabs(posicaoJogador.x - posicaoInimigo.x) <= RAIO_PERSEGUIR_X)
    {
        persegueJogador(posicaoJogador, posicaoInimigo);
    }
}

void Personagens::Galinha::persegueJogador(sf::Vector2f posJog, sf::Vector2f posIni)
{
   if((posJog.x - posIni.x) > 0.0f)
    {
        corpo.move(VELOCIDADE_INIM, 0.0f);
    }
    else 
    {
        corpo.move(-VELOCIDADE_INIM, 0.0f);
    }
}

const sf::RectangleShape Personagens::Galinha::getCorpo()
{
    return corpo;
}

void Personagens::Galinha::imprimir(Gerenciador::GerenciadorGrafico *gG)
{
    gG->desenhaEntidade(corpo);
    corpo.setTexture(gG->carregaTextura("src/galinha.png"));
}

void Personagens::Galinha::colide(Entidades::Entidade *outraEntidade, sf::Vector2f intersecao)
{

    if(outraEntidade->getID() == Entidades::ID::jogador)
    {
        danificar(static_cast<Personagens::Jogador*>(outraEntidade));
    }
}

void Personagens::Galinha::danificar(Personagens::Jogador* pontJogador)
{
    if(pontJogador->estaAtacando())
    {
        num_vidas--;
    }
}

void Personagens::Galinha::atualizarPosicao()
{
    x = corpo.getPosition().x;
    y = corpo.getPosition().y;

    velocidade.y += GRAVIDADE;
    velocidade.y += FORÇA_SUSTENTAÇÃO;
}

int Personagens::Galinha::getNumVidas()
{
    return num_vidas;
}

