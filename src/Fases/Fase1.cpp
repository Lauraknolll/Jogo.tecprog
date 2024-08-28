#include "../../include/Fases/Fase1.h"

#define CAMINHO_MAPA_FASE1 "src/mapaJogo1.json" // camonho para o mapa da fase 1

Fases::Fase1::Fase1() :
    Fase()
{
    Lista_Entidades = new Lista::ListaEntidade();
    pEventos = Gerenciador::GerenciadorEvento::getGerenciadorEventos();
    mapa = CAMINHO_MAPA_FASE1;

    carregarMapa(mapa);
}

Fases::Fase1::~Fase1()
{
    ListaObstaculos.clear();
    ListaInimigos.clear();
}

// apenas para fins de testes
void Fases::Fase1::criarJogadores()
{
    Personagens::Jogador* jog;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0;

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(CAMINHO_MAPA_FASE1, &x, &y, &indice, -1);
        
        if (posi != sf::Vector2f(-1, -1))
        {
            //std::cout << "Criando jogador em: (" << posi.x << ", " << posi.y << ")" << std::endl;
            jog = new Personagens::Jogador(posi.x, posi.y, 32, 32);
            pEventos->setJogador(jog);
            ListaJogadores.push_back(static_cast<Entidades::Entidade*>(jog));
            Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(jog));
        }
    }
}

void Fases::Fase1::criarPlataformas()
{
    Obstaculos::Plataforma* plat;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0;

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(CAMINHO_MAPA_FASE1, &x, &y, &indice, 1);
        
        if (posi != sf::Vector2f(-1, -1))
        {
            //std::cout << "Criando plataforma em: (" << posi.x << ", " << posi.y << ")" << std::endl;
            plat = new Obstaculos::Plataforma(posi.x, posi.y, 32*y, 32);
            ListaObstaculos.push_back(static_cast<Entidades::Entidade*>(plat));
            Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(plat));
        }
    }
}
//

void Fases::Fase1::criarInimigosFaceis()
{
    
}

void Fases::Fase1::criarObstaculosFaceis()
{

}

void Fases::Fase1::criarInimigosMedios()
{
   
}

void Fases::Fase1::criarObstaculosMedios()
{

}
void Fases::Fase1::executar()
{
    Gerenciador::GerenciadorGrafico *pontGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
    
    Lista_Entidades->percorrerLista();
    Lista_Entidades->desenharEntidades(pontGrafico);
    list<Entidades::Entidade*>::iterator it;
    Entidades::Entidade* ent1;
    Entidades::Entidade* ent2;
    it = ListaJogadores.begin();
    ent1 = *it;
    it++;
    ent2 = *it;
    pontGrafico->centralizarCamera(sf::Vector2f((ent1->getPosicao().x + ent2->getPosicao().x)/2, 300));
    
    pGColisoes->colide();
}

void Fases::Fase1::cria()
{
    criarJogadores();
    criarPlataformas();

    /*criarInimigosFaceis();
    criarObstaculosFaceis();
    criarInimigosMedios();*/
    
    pGColisoes = new Gerenciador::GerenciadorColisoes(ListaJogadores, ListaObstaculos, ListaInimigos);
}
