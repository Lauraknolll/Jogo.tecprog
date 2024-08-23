#include "../../../include/Entidades/Personagens/Jogador.h"

#define VELJOG 1.f
#define GRAVIDADE 0.00005f
#define VELOCIDADE_JOGADOR 0.1f

Personagens::Jogador::Jogador(float xx, float yy, float ww, float hh) :
    Personagem(xx, yy, ww, hh, Entidades::jogador), podePular(false), podeAndarDireita(true), podeAndarEsquerda(true)
{

    corpo.setFillColor(sf::Color::Blue);
    //corpo.setPosition(200.0, 340.0);
    velocidade.x = 0.0f;
    velocidade.y = 0.0f;
}

Personagens::Jogador::~Jogador()
{

}

void Personagens::Jogador::executar()
{
    corpo.setFillColor(sf::Color::Magenta);
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
    if(podePular){
        velocidade.y = -sqrt(2.0f*GRAVIDADE*200.0f);
        podePular = false;
    }
   
}

void Personagens::Jogador::tratarEventoPrecionar(const sf::Event &e) {
    if(e.type == sf::Event::KeyPressed){
        switch (e.key.code)
        {
            case sf::Keyboard::D:
                if(podeAndarDireita){
                    podeAndarDireita = false;
                    velocidade.x += VELOCIDADE_JOGADOR;
                }
                break;
            
            case sf::Keyboard::A:
                if(podeAndarEsquerda){
                    podeAndarEsquerda = false;
                    velocidade.x -= VELOCIDADE_JOGADOR;
                }
                break;
            
            case sf::Keyboard::W:
                pular();
                break;
            
            
            default:
                break;
        }
    }
}

void Personagens::Jogador::tratarEventoSoltar(const sf::Event &e){
        if(e.type == sf::Event::KeyReleased){
        switch (e.key.code)
        {
            case sf::Keyboard::D:
                if(!podeAndarDireita){
                    podeAndarDireita = true;
                    velocidade.x -= VELOCIDADE_JOGADOR;
                }
                break;
            
            case sf::Keyboard::A:
                if(!podeAndarEsquerda){
                    podeAndarEsquerda = true;
                    velocidade.x += VELOCIDADE_JOGADOR;
                }   
                break;
            
            default:
                break;
        }
    }
}


void Personagens::Jogador::imprimir(Gerenciador::GerenciadorGrafico *gG)
{
    gG->desenhaEntidade(corpo);
}

void Personagens::Jogador::colide(Entidades::Entidade *outraEntidade, sf::Vector2f intersecao)
{
    sf::Vector2f posicaoOutro = outraEntidade->getCorpo().getPosition();
    /*if(outraEntidade->getID() == ){

    }*/

    if(intersecao.x > intersecao.y) // colisao em x
    {
        if(x < posicaoOutro.x)
        {
            x += intersecao.x;
            corpo.setPosition(x, corpo.getPosition().y);
        }
        else
        {
            x -= intersecao.x;
            corpo.setPosition(x, corpo.getPosition().y);
        }
        //velocidade.x = 0.0f;
    }

    else // colisao em y
    {
        if(y < posicaoOutro.y)
        {
            y += intersecao.y;
            corpo.setPosition(corpo.getPosition().x, y);
        }
        else
        {
            y -= intersecao.y;
            corpo.setPosition(corpo.getPosition().x, y);
        }
        velocidade.y = 0.0f;
        podePular = true;
    }
}

void Personagens::Jogador::atualizar()
{
    velocidade.y += GRAVIDADE;
    y = corpo.getPosition().y;
    corpo.move(sf::Vector2f(velocidade.x, velocidade.y));
}