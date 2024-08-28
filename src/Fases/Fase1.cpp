#include "../../include/Fases/Fase1.h"

#define CAMINHO_MAPA_FASE1 "src/mapaJogo1.json" // camonho para o mapa da fase 1

Fases::Fase1::Fase1() :
    Fase(), ListaObstaculosFase1(), ListaInimigosFase1()
{
    mapa = CAMINHO_MAPA_FASE1;
}

Fases::Fase1::~Fase1()
{
    ListaObstaculosFase1.clear();
    ListaInimigosFase1.clear();
}

void Fases::Fase1::criarInimigosFaceis(sf::Vector2f posicao, sf::Vector2f tamanho)
{
    Personagens::InimigoFacil *ent = new Personagens::InimigoFacil(posicao.x, posicao.y, tamanho.x, tamanho.y);
    if (ent)
    {
        ListaInimigos.push_back(static_cast<Entidades::Entidade *>(ent));
        Lista_Entidades->addEntidade(static_cast<Entidades::Entidade *>(ent));
    }
}

void Fases::Fase1::criarObstaculosFaceis(sf::Vector2f posicao, sf::Vector2f tamanho)
{

}

void Fases::Fase1::carregarMapa(std::string mapJson) {
    std::ifstream arquivo(mapJson);
    
    if(!arquivo.is_open()){
        std::cerr << "Erro ao abrir o mapa (caminho mapa)" << std::endl;
        return;
    }

    arquivo >> mapa;
    arquivo.close();
}


