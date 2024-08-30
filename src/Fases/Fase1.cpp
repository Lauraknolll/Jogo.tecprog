#include "../../include/Fases/Fase1.h"


#define CAMINHO_MAPA_FASE1 "src/mapaJogo1.json" // camonho para o mapa da fase 1

Fases::Fase1::Fase1(Estados::GerenciadorEstado* gE) :
    Fase(), Estados::Estado(gE, Estados::EstadoID::fase1), maxInimigos(5), maxObstaculos(7)
{
    ativo = false;
    dois_jogadores = false;
    setGerenciadorEstados(gE);
    Lista_Entidades = new Lista::ListaEntidade();
    pEventos = Gerenciador::GerenciadorEvento::getGerenciadorEventos();
    mapa = CAMINHO_MAPA_FASE1;
    
    carregarMapa(mapa);
    criar();

}

Fases::Fase1::~Fase1()
{
    ListaObstaculos.clear();
    ListaInimigos.clear();
}

void Fases::Fase1::criarJogadores()
{
    Personagens::Jogador* jog;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0;

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(CAMINHO_MAPA_FASE1, &x, &y, &indice, -1);
        
        if (posi != sf::Vector2f(-1, -1) && ListaJogadores.size() < 2)
        {
            jog = new Personagens::Jogador(posi.x, posi.y, 56.0, 56.0);
            ListaJogadores.push_back(static_cast<Entidades::Entidade*>(jog));
            Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(jog));
            if(dois_jogadores){
                jog->getControle()->setKeys("O", "J", "L", "M");
            }
        }
    }
    dois_jogadores = true;
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
            plat = new Obstaculos::Plataforma(posi.x, posi.y, 32.0*y, 16.0);
            ListaObstaculos.push_back(static_cast<Entidades::Entidade*>(plat));
            Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(plat));
        }
    }
}

void Fases::Fase1::criarFantasmas()
{
    Personagens::Fantasma* ini;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0, cont = 0;

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(CAMINHO_MAPA_FASE1, &x, &y, &indice, 3);
        
        if (posi != sf::Vector2f(-1, -1))
        {
            if((rand()%10 <= 7) && cont < maxInimigos)
            {
                ini = new Personagens::Fantasma(posi.x, posi.y, 60.0, 60.0);
                ListaInimigos.push_back(static_cast<Entidades::Entidade*>(ini));
                Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(ini));
            }
        }
    }
}

void Fases::Fase1::criarPedras()
{
    Obstaculos::Pedra* pedra;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0, cont = 0;

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(CAMINHO_MAPA_FASE1, &x, &y, &indice, 7);
        
        if (posi != sf::Vector2f(-1, -1))
        {
            if(( rand()%10 <= 7) && cont < maxObstaculos) // numero aleatório de obstáculos
            {
                pedra = new Obstaculos::Pedra(posi.x, posi.y, 39.0, 27.0);
                ListaObstaculos.push_back(static_cast<Entidades::Entidade*>(pedra));
                Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(pedra));
            }
        }
    }
}

void Fases::Fase1::criarGalinhas()
{
    Personagens::Galinha* ini;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0, cont = 0;

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(CAMINHO_MAPA_FASE1, &x, &y, &indice, 4);
        
        if (posi != sf::Vector2f(-1, -1))
        {
            if((rand()%10 <= 7) && cont < maxInimigos)
            {
                ini = new Personagens::Galinha(posi.x, posi.y, 62.0, 68.0);
                list<Entidades::Entidade*>::iterator it;
                it = ListaJogadores.begin();
                ini->setJogador(static_cast<Personagens::Jogador*>(*it));
                ListaInimigos.push_back(static_cast<Entidades::Entidade*>(ini));
                Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(ini));
            }
        }
    }
}

void Fases::Fase1::criarLava()
{
    Obstaculos::Lava* lava;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0, cont = 0;

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(CAMINHO_MAPA_FASE1, &x, &y, &indice, 2);
        
        if (posi != sf::Vector2f(-1, -1))
        {
            if((rand()%10 <= 7) && cont < maxObstaculos)
            {
                lava = new Obstaculos::Lava(posi.x, posi.y, 32.0*y, 16.0);
                ListaObstaculos.push_back(static_cast<Entidades::Entidade*>(lava));
                Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(lava));
            }
        }
    }
}

void Fases::Fase1::executar()
{
    
}

void Fases::Fase1::atualizar()
{
    ativo = true;
    
    Lista_Entidades->percorrerLista();
    
    gerenciarColisoes();
}

void Fases::Fase1::render()
{
    list<Entidades::Entidade*>::iterator it;
    Entidades::Entidade* ent1;
    Entidades::Entidade* ent2;
    it = ListaJogadores.begin();
    ent1 = *it;
    /*it++;
    ent2 = *it;*/
    Gerenciador::GerenciadorGrafico *pontGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
    Lista_Entidades->desenharEntidades(pontGrafico);
    pontGrafico->centralizarCamera(sf::Vector2f((ent1->getPosicao().x/* + ent2->getPosicao().x*/), 400));
}

void Fases::Fase1::criar()
{
    criarJogadores();
    criarPlataformas();

    criarFantasmas();
    criarPedras();

    criarGalinhas();
    criarLava();

    pGColisoes = new Gerenciador::GerenciadorColisoes(ListaJogadores, ListaObstaculos, ListaInimigos);
}

void Fases::Fase1::resetEstado()
{
    // Limpa todas as listas de entidades
    Lista_Entidades->cleanList();
    ListaJogadores.clear();
    ListaObstaculos.clear();
    ListaInimigos.clear();

    dois_jogadores = false;

    // Se necessário, também limpa e redefine o gerenciador de colisões
    if (pGColisoes != nullptr) {
        delete pGColisoes;
        pGColisoes = nullptr;
    }

    // Recarrega o mapa e recria os elementos da fase
    mapa = CAMINHO_MAPA_FASE1;
    carregarMapa(mapa);
    
    criar();
}

void Fases::Fase1::sair()
{
    if(ativo){
        ativo = false;
        resetEstado();
        changeEstado(Estados::EstadoID::mainMenu);
    }
}
            
void Fases::Fase1::segundoJogador()
{
    if(ativo){
        ativo = false;
        criarJogadores();
        pGColisoes = new Gerenciador::GerenciadorColisoes(ListaJogadores, ListaObstaculos, ListaInimigos);
    }
}
