#include "../../../include/Entidades/Personagens/Jogador.h"

#define VELJOG 1.f
#define VELOCIDADE_JOGADOR 0.0001f
#define COOLDOWN_DANO 100.f
#define VIDAS_JOGADOR 1000;


Personagens::Jogador::Jogador(float xx, float yy, float ww, float hh) :
    Personagem(xx, yy, ww, hh, Entidades::jogador), pPular(false), andando(false), emEsquerda(false), lentidao(1), Atacando(false), controle(this)
{
    num_vidas = VIDAS_JOGADOR;
    cooldownDano = 0;
    corpo.setFillColor(sf::Color::Blue);
    velocidade.x = 0.0f;
    velocidade.y = 0.0f;
}

Personagens::Jogador::~Jogador()
{
    
}

void Personagens::Jogador::executar()
{
    corpo.setFillColor(sf::Color::White);
    atualizar();
}

void Personagens::Jogador::pular()
{
    if(pPular){
        velocidade.y = -sqrt(2.0f*GRAVIDADE*150.0f);
        pPular = false;
    }
   
}

void Personagens::Jogador::imprimir(Gerenciador::GerenciadorGrafico *gG)
{
    gG->desenhaEntidade(corpo);
    corpo.setTexture(gG->carregaTextura("src/jogador.png"));
}

void Personagens::Jogador::colide(Entidades::Entidade *outraEntidade, sf::Vector2f intersecao)
{
    switch (outraEntidade->getID())
    {
    case Entidades::plataforma:
            moveColisao(outraEntidade, intersecao);
        break;
    case Entidades::lava:
            moveColisao(outraEntidade, intersecao);
        break;

    default:
        break;
    }
}

void Personagens::Jogador::atualizar()
{
    if (andando) {
        if (emEsquerda)
            velocidade.x -= VELOCIDADE_JOGADOR * lentidao;
        else
            velocidade.x += VELOCIDADE_JOGADOR * lentidao;
        //velocidade.x *= lentidao;
    } 
    else
        velocidade.x *= 0.05;
    
    velocidade.y += GRAVIDADE;

    corpo.move(sf::Vector2f(velocidade.x, velocidade.y));

    cooldownDano += 1;

    //std::cout << num_vidas << std::endl;
}

const bool Personagens::Jogador::estaNaEsquerda() const
{
    return emEsquerda;
}

void Personagens::Jogador::setEsquerda(const bool esquerda)
{
    emEsquerda = esquerda;
}

void Personagens::Jogador::setEsquerda()
{
    emEsquerda = velocidade.x >= 0.0f ? false : true;
}

void Personagens::Jogador::andar(bool esquerda)
{
    andando = true;
    setEsquerda(esquerda);
}

void Personagens::Jogador::pararAndar()
{
    andando = false;
}

unsigned int Personagens::Jogador::getPontos() const
{
    return pontos;
}

/*
void Personagens::Jogador::incrementaPontos(unsigned int pont) {
    this->pontos += pont;
}*/

void Personagens::Jogador::moveColisao(Entidades::Entidade* outraEnt, sf::Vector2f intersecao)
{
    sf::Vector2f posicaoOutro = outraEnt->getCorpo().getPosition();

    if(intersecao.x > intersecao.y) // colisao em x
    {
        if(x < posicaoOutro.x)
        {
            x = corpo.getPosition().x;
            x += intersecao.x;
            corpo.setPosition(x, corpo.getPosition().y);
        }
        else
        {
            x = corpo.getPosition().x;
            x -= intersecao.x;
            corpo.setPosition(x, corpo.getPosition().y);
        }
        velocidade.x = 0.0f;
    }

    else // colisao em y
    {
        if(y < posicaoOutro.y)
        {
            y = corpo.getPosition().y;
            y += intersecao.y;
            corpo.setPosition(corpo.getPosition().x, y);
        }
        else
        {
            y = corpo.getPosition().y;
            y -= intersecao.y;
            corpo.setPosition(corpo.getPosition().x, y);
        }
        velocidade.y = 0.0f;
        pPular = true;
    }
}


int Personagens::Jogador::getNumVidas()
{
    return num_vidas;
}

void Personagens::Jogador::recebaDano(const int dano) 
{
    //printf("%d\n", dano);
    if (cooldownDano > COOLDOWN_DANO) 
    {
        num_vidas -= dano;
        /*if (num_vidas <= 0)
            active = false;*/
        cooldownDano = 0;
    }
}

void Personagens::Jogador::atacar()
{
    Atacando = true;
}

void Personagens::Jogador::paraAtacar()
{
    Atacando = false;
}

const bool Personagens::Jogador::estaAtacando()
{
    return Atacando;
}

Controle::ControleJogador* Personagens::Jogador::getControle()
{
    return &controle;
}