#include "../../../include/Entidades/Personagens/Jogador.h"

#define VELJOG 1.f
#define GRAVIDADE 0.0001f
#define VELOCIDADE_JOGADOR 0.0001f
#define COOLDOWN_DANO 100.f

Personagens::Jogador::Jogador(float xx, float yy, float ww, float hh) :
    Personagem(xx, yy, ww, hh, Entidades::jogador), pPular(false), andando(false), emEsquerda(false), lentidao(1), Atacando(false)
{
    num_vidas = 50;
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


/*
void Personagens::Jogador::andaPraDireta()
{
    corpo.move(sf::Vector2f(VELJOG, 0.0f));
    x = corpo.getPosition().x;
}

void Personagens::Jogador::andaPraEsquerda()
{
    corpo.move(sf::Vector2f(-VELJOG, 0.0f));
    x = corpo.getPosition().x;
}
*/
void Personagens::Jogador::pular()
{
    if(pPular){
        velocidade.y = -sqrt(2.0f*GRAVIDADE*150.0f);
        pPular = false;
    }
   
}

void Personagens::Jogador::tratarEventoPressionar(const sf::Event &e) {
    /*if(e.type == sf::Event::KeyPressed){
        switch (e.key.code)
        {
            case sf::Keyboard::D:
                andar(false);
                break;
            
            case sf::Keyboard::A:
                andar(true);
                break;
            
            case sf::Keyboard::W:
                pular();
                break;
            
            
            default:
                break;
        }
    }*/
}

void Personagens::Jogador::tratarEventoSoltar(const sf::Event &e){
       /* if(e.type == sf::Event::KeyReleased){
        switch (e.key.code)
        {
            case sf::Keyboard::D:
                pararAndar();
                break;
            
            case sf::Keyboard::A:
                pararAndar();
                break;
            
            default:
                break;
        }
    }*/
}


void Personagens::Jogador::imprimir(Gerenciador::GerenciadorGrafico *gG)
{
    gG->desenhaEntidade(corpo);
    corpo.setTexture(gG->carregaTextura("src/teste.png"));
}

void Personagens::Jogador::colide(Entidades::Entidade *outraEntidade, sf::Vector2f intersecao)
{
    switch (outraEntidade->getID())
    {
    case Entidades::plataforma:
            moveColisao(outraEntidade, intersecao);
        break;
    case Entidades::inimigoFacil:
            recebaDano(1);
        break;
    case Entidades::inimigoMedio:
            recebaDano(2);
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
    /*if(outraEntidade->getID() == ){

    }*/
   //printf("\nx: %f | Y: %f", intersecao.x, intersecao.y);

    if(intersecao.x > intersecao.y) // colisao em x
    {
        if(x < posicaoOutro.x)
        {
            x = corpo.getPosition().x;
            x += intersecao.x;
            corpo.setPosition(x, corpo.getPosition().y);
            //printf("x1 %f\n", intersecao.x);
        }
        else
        {
            x = corpo.getPosition().x;
            x -= intersecao.x;
            corpo.setPosition(x, corpo.getPosition().y);
            //printf("x2 %f\n", intersecao.x);
        }
        velocidade.x = 0.0f;
    }

    else // colisao em y
    {
        if(y < posicaoOutro.y)
        {
            y = corpo.getPosition().y;
            //printf("y1 %f\n", intersecao.y);
            y += intersecao.y;
            corpo.setPosition(corpo.getPosition().x, y);
        }
        else
        {
            y = corpo.getPosition().y;
            //printf("y2 %f\n", intersecao.y);
            y -= intersecao.y;
            corpo.setPosition(corpo.getPosition().x, y);
        }
        velocidade.y = 0.0f;
        pPular = true;
    }
}


int Personagens::Jogador::getNumVidas(){
    return num_vidas;
}

void Personagens::Jogador::recebaDano(const int dano)
{
    //printf("%d\n", dano);
    if (cooldownDano > COOLDOWN_DANO) {
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