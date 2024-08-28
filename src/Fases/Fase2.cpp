#include "../../include/Fases/Fase2.h"

#define CAMINHO_MAPA //caminho para o mapa da fase 2

Fases::Fase2::Fase2() :
    Fase()
{

}

Fases::Fase2::~Fase2()
{
    
}

void Fases::Fase2::criarInimigosMedios(sf::Vector2f posicao, sf::Vector2f tamanho)
{
    Personagens::InimigoMedio* ent = new Personagens::InimigoMedio(posicao.x, posicao.y, tamanho.x, tamanho.y);
    //ListaInimigos.push_back(static_cast<Entidades::Entidade*>(ent));
    //Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(ent));
}

void Fases::Fase2::criarInimigosDificeis(sf::Vector2f posicao, sf::Vector2f tamanho)
{

}

void Fases::Fase2::criarObstaculosMedios(sf::Vector2f posicao, sf::Vector2f tamanho)
{

}

void Fases::Fase2::criarObstaculosDificeis(sf::Vector2f posicao, sf::Vector2f tamanho)
{

}