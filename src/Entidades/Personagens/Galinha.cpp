#include "../../../include/Entidades/Personagens/Galinha.h"

#define RAIO_PERSEGUIR_X 200.0f
#define VELOCIDADE_GALINHA 0.025f
#define VIDAS_GALINHA 3000

Personagens::Galinha::Galinha(float xx, float yy, float ww, float hh) :
    Inimigo(xx, yy, ww, hh, Entidades::galinha)
{
    bicada = rand()%20;
    num_vidas = VIDAS_GALINHA;
    corpo.setFillColor(sf::Color::White);
    velocidade.x = VELOCIDADE_GALINHA;
    velocidade.y = 0.0f;
    movAle = rand()%2;
}

Personagens::Galinha::~Galinha()
{

}

void Personagens::Galinha::moveAleatorio()
{
    if(movAle == 0)
    {
        corpo.move(sf::Vector2f(velocidade.x, velocidade.y));
    }
    else
    {
        corpo.move(sf::Vector2f(-velocidade.x, velocidade.y));
    }

    float tempo = relogio.getElapsedTime().asSeconds();
    if(tempo >= 4.0f)
    {
        movAle = rand()%2;
        relogio.restart();
    }
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
    else
    {
        moveAleatorio();
    }
}

void Personagens::Galinha::persegueJogador(sf::Vector2f posJog, sf::Vector2f posIni)
{
   if((posJog.x - posIni.x) > 0.0f)
    {
        corpo.move(VELOCIDADE_GALINHA, 0.0f);
    }
    else 
    {
        corpo.move(-VELOCIDADE_GALINHA, 0.0f);
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
    else
    {
        pontJogador->recebaDano(bicada);
    }
}

void Personagens::Galinha::atualizarPosicao()
{
    x = corpo.getPosition().x;
    y = corpo.getPosition().y;

    velocidade.y += GRAVIDADE;
    velocidade.y += FORCA_SUSTENTACAO;
}

int Personagens::Galinha::getNumVidas()
{
    return num_vidas;
}

