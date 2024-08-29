#include "../../include/Fases/Fase2.h"

#define CAMINHO_MAPA_FASE2 "src/mapaJogo2.json"//caminho para o mapa da fase 2

Fases::Fase2::Fase2(Estados::GerenciadorEstado* gE, Controle::ControleJogador* cont) :
    Fase(), Estados::Estado(gE, Estados::EstadoID::fase2)
{
    pInput = Gerenciador::GerenciadorInput::getInstance();
    controle = cont;
    pInput->Attach(static_cast<Controle::Observador*>(controle));
    setGerenciadorEstados(gE);
    Lista_Entidades = new Lista::ListaEntidade();
    pEventos = Gerenciador::GerenciadorEvento::getGerenciadorEventos();
    mapa = CAMINHO_MAPA_FASE2;
    carregarMapa(mapa);
    criar();
}

Fases::Fase2::~Fase2()
{
    ListaObstaculos.clear();
    ListaInimigos.clear();
}

void Fases::Fase2::criarJogadores()
{
    Personagens::Jogador* jog;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0;

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(CAMINHO_MAPA_FASE2, &x, &y, &indice, -1);
        
        if (posi != sf::Vector2f(-1, -1))
        {
            jog = new Personagens::Jogador(posi.x, posi.y, 64.0, 64.0);
            controle->setJogador(jog);
            //pEventos->setJogador(jog);
            ListaJogadores.push_back(static_cast<Entidades::Entidade*>(jog));
            Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(jog));
        }
    }
}

void Fases::Fase2::criarGalinhas()
{
    Personagens::Galinha* ini;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0;

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(CAMINHO_MAPA_FASE2, &x, &y, &indice, 4);
        
        if (posi != sf::Vector2f(-1, -1))
        {
            //std::cout << "Criando plataforma em: (" << posi.x << ", " << posi.y << ")" << std::endl;
            ini = new Personagens::Galinha(posi.x, posi.y, 64.0, 64.0);
            list<Entidades::Entidade*>::iterator it;
            it = ListaJogadores.begin();
            ini->setJogador(static_cast<Personagens::Jogador*>(*it));
            ListaInimigos.push_back(static_cast<Entidades::Entidade*>(ini));
            Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(ini));
        }
    }
}

void Fases::Fase2::criarRinos()
{
    Personagens::Rino* chefao;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0;   

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(CAMINHO_MAPA_FASE2, &x, &y, &indice, 5);
        
        if (posi != sf::Vector2f(-1, -1))
        {
            //std::cout << "Criando plataforma em: (" << posi.x << ", " << posi.y << ")" << std::endl;
            chefao = new Personagens::Rino(posi.x, posi.y, 64.0, 64.0);
            list<Entidades::Entidade*>::iterator it;
            it = ListaJogadores.begin();
            chefao->setJogador(static_cast<Personagens::Jogador*>(*it));
            ListaInimigos.push_back(static_cast<Entidades::Entidade*>(chefao));
            Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(chefao));
        }
    }

}

void Fases::Fase2::criarPlataformas()
{
    Obstaculos::Plataforma* plat;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0;

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(CAMINHO_MAPA_FASE2, &x, &y, &indice, 1);
        
        if (posi != sf::Vector2f(-1, -1))
        {
            //std::cout << "Criando plataforma em: (" << posi.x << ", " << posi.y << ")" << std::endl;
            plat = new Obstaculos::Plataforma(posi.x, posi.y, 32*y, 32);
            ListaObstaculos.push_back(static_cast<Entidades::Entidade*>(plat));
            Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(plat));
        }
    }
}

void Fases::Fase2::criarEspinhos()
{
    Obstaculos::Espinho* pinho;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0;

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(CAMINHO_MAPA_FASE2, &x, &y, &indice, 6);
        
        if (posi != sf::Vector2f(-1, -1))
        {
            //std::cout << "Criando plataforma em: (" << posi.x << ", " << posi.y << ")" << std::endl;
            pinho = new Obstaculos::Espinho(posi.x, posi.y, 41.0, 32.0);
            ListaObstaculos.push_back(static_cast<Entidades::Entidade*>(pinho));
            Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(pinho));
        }
    }
}

void Fases::Fase2::executar()
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
    pontGrafico->centralizarCamera(sf::Vector2f((ent1->getPosicao().x/* + ent2->getPosicao().x*/), 400));
    
    gerenciarColisoes();
}
void Fases::Fase2::atualizar()
{
    executar();
}

void Fases::Fase2::render()
{
    
}

void Fases::Fase2::criar()
{
    criarJogadores();
    criarPlataformas();
    criarGalinhas();
    criarRinos();
    criarEspinhos();
    
    pGColisoes = new Gerenciador::GerenciadorColisoes(ListaJogadores, ListaObstaculos, ListaInimigos);
}

void Fases::Fase2::resetEstado()
{

}