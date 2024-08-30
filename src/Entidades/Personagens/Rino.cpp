#include "../../../include/Entidades/Personagens/Rino.h"

#define VIDAS_RINO 5000
#define VELOCIDADE_RINO 0.04f
#define RAIO_PERSEGUIR_X  250.0f

Personagens::Rino::Rino(float xx, float yy, float ww, float hh) :
    Inimigo(xx, yy, ww, hh, Entidades::rino)
{
    chifrada = rand()%75;
    num_vidas = VIDAS_RINO;
    velocidade.x = VELOCIDADE_RINO;
    velocidade.y = 0.0f;
    corpo.setFillColor(sf::Color::White);
}

Personagens::Rino::~Rino()
{

}

void Personagens::Rino::imprimir(Gerenciador::GerenciadorGrafico* gG)
{
    if(vivo)
    {
        gG->desenhaEntidade(corpo);
        corpo.setTexture(gG->carregaTextura("imagens/rino.png"));
    }
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
    else
    {
        movimentoAleatorio();
    }
}

void Personagens::Rino::movimentoAleatorio()
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
        corpo.move(VELOCIDADE_RINO, 0.0f);
        lancaProjetil(1);
    }
    else 
    {
        corpo.move(-VELOCIDADE_RINO, 0.0f);
        lancaProjetil(-1);
    }
}

void Personagens::Rino::colide(Entidade *outraEntidade, sf::Vector2f intersecao)
{
    if(outraEntidade->getID() == Entidades::ID::jogador)
    {
        danificar(static_cast<Personagens::Jogador*>(outraEntidade));
    }
}

void Personagens::Rino::danificar(Personagens::Jogador* pontJogador)
{
    if(pontJogador->estaAtacando())
    {
        num_vidas--;
    }
    else
    {
        pontJogador->recebaDano(chifrada);
    }
}

int Personagens::Rino::getNumVidas()
{
   return num_vidas;
}

void Personagens::Rino::atualizarPosicao()
{
    if(vivo)
    {
        x = corpo.getPosition().x;
        y = corpo.getPosition().y;

        velocidade.y += GRAVIDADE;
        velocidade.y += FORCA_SUSTENTACAO;
    }
}

bool Personagens::Rino::getVivo()
{
    return vivo;
}

void Personagens::Rino::setVivo()
{
    vivo = false;
}

void Personagens::Rino::lancaProjetil(int direcao)
{
    proj = new Entidades::Projetil(corpo.getPosition().x, corpo.getPosition().y, 10.0f, 10.0f, Entidades::projetil, direcao);
}


