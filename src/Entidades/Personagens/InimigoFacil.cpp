#include "../../../include/Entidades/Personagens/InimigoFacil.h"

Personagens::InimigoFacil::InimigoFacil(float xx, float yy, float ww, float hh) :
    Inimigo(xx, yy, ww, hh, Entidades::inimigoFacil)
{
    corpo.setFillColor(sf::Color::Red);
    //corpo.setOrigin(sf::Vector2f(-150.0f, -400.0f));
    movimentoale = rand()%1;
}

Personagens::InimigoFacil::~InimigoFacil()
{

}

void Personagens::InimigoFacil::executar()
{
    moveAleatorio();
}

void Personagens::InimigoFacil::moveAleatorio()
{
    /*if(movimentoale == 0)
    {
        corpo.move(sf::Vector2f(0.1f, 0.0f));
    }
    else
    {
        corpo.move(sf::Vector2f(-0.1f, 0.0f));
    }

    float tempo = relogio.getElapsedTime().asSeconds();
    if(tempo >= 2.0f)
    {
        movimentoale = rand()%2;
        relogio.restart();
    }*/

   /*sf::Vector2f posIni = corpo.getPosition();
   if(posIni.x > -100.0)
   {
        corpo.move(sf::Vector2f(0.01f, 0.0f));
   }
   else if (posIni.x < -100.0)
   {
        corpo.move(sf::Vector2f(-0.01f, 0.0f));
   }
   posIni = corpo.getPosition();*/

   float tempo = relogio.getElapsedTime().asSeconds();
   if(tempo < 10.0f)
   {
        corpo.move(sf::Vector2f(0.01f, 0.0f));
   }
   else
   {
        corpo.move(sf::Vector2f(-0.01f, 0.0f));
   }
}

const sf::RectangleShape Personagens::InimigoFacil::getCorpo()
{
    return corpo;
}

void Personagens::InimigoFacil::imprimir(Gerenciador::GerenciadorGrafico *gG)
{
    gG->desenhaEntidade(corpo);
}

void Personagens::InimigoFacil::colide(Entidades::Entidade *outraEntidade, sf::Vector2f intersecao)
{

}