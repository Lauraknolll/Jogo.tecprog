#include "../../../include/Entidades/Personagens/InimigoMedio.h"

#define VELOCIDADE_INIM 0.025f
#define VIDAS_INIM 3000

Personagens::InimigoMedio::InimigoMedio(float xx, float yy, float ww, float hh) :
    Inimigo(xx, yy, ww, hh, Entidades::inimigoMedio)
{
    num_vidas = VIDAS_INIM;
    corpo.setFillColor(sf::Color::Yellow);
    velocidade.x = 0.0f;
    velocidade.y = 0.0f;
}

Personagens::InimigoMedio::~InimigoMedio()
{

}

void Personagens::InimigoMedio::setJogador(Personagens::Jogador* pJ)
{
    if(pJ)
    {
        jogador = pJ;
    }
}

void Personagens::InimigoMedio::executar()
{
    sf::Vector2f posicaoJogador = jogador->getCorpo().getPosition();
    sf::Vector2f posicaoInimigo = corpo.getPosition();
    atualizarPosicao();

    if(fabs(posicaoJogador.x - posicaoInimigo.x) <= RAIO_PERSEGUIR_X)
    {
        persegueJogador(posicaoJogador, posicaoInimigo);
    }
}

void Personagens::InimigoMedio::persegueJogador(sf::Vector2f posJog, sf::Vector2f posIni)
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

const sf::RectangleShape Personagens::InimigoMedio::getCorpo()
{
    return corpo;
}

void Personagens::InimigoMedio::imprimir(Gerenciador::GerenciadorGrafico *gG)
{
    gG->desenhaEntidade(corpo);
}

void Personagens::InimigoMedio::colide(Entidades::Entidade *outraEntidade, sf::Vector2f intersecao)
{
    if(outraEntidade->getID() == Entidades::ID::jogador)
    {
        if((static_cast<Jogador*>(outraEntidade))->estaAtacando())
        {
            num_vidas--;
        }
    }
}

void Personagens::InimigoMedio::atualizarPosicao()
{
    x = corpo.getPosition().x;
    y = corpo.getPosition().y;
}

int Personagens::InimigoMedio::getNumVidas()
{
    return num_vidas;
}
