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
            if(cont < 3)
            {
                ini = new Personagens::Fantasma(posi.x, posi.y, 60.0, 60.0);
                ListaInimigos.push_back(static_cast<Entidades::Entidade*>(ini));
                Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(ini));
                cont++;
            }
            else if ((rand()%10 < 5) && (3 < cont < maxInimigos))
            {
                ini = new Personagens::Fantasma(posi.x, posi.y, 60.0, 60.0);
                ListaInimigos.push_back(static_cast<Entidades::Entidade*>(ini));
                Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(ini));
                cont++;
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
            if(cont < 3)
            {
                pedra = new Obstaculos::Pedra(posi.x, posi.y, 39.0, 27.0);
                ListaObstaculos.push_back(static_cast<Entidades::Entidade*>(pedra));
                Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(pedra));
                cont++;
            }
            else if(( rand()%10 < 5) && (3 < cont < maxObstaculos)) // numero aleatório de obstáculos
            {
                pedra = new Obstaculos::Pedra(posi.x, posi.y, 39.0, 27.0);
                ListaObstaculos.push_back(static_cast<Entidades::Entidade*>(pedra));
                Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(pedra));
                cont++;
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

    gerenciarMortos();
    
    Lista_Entidades->percorrerLista();
    
    gerenciarColisoes();

    vaiPraProximoFase();
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
    criarJogadores(CAMINHO_MAPA_FASE1);
    criarPlataformas(CAMINHO_MAPA_FASE1);

    criarFantasmas();
    criarPedras();

    criarGalinhas(CAMINHO_MAPA_FASE1, maxInimigos);
    criarLava(CAMINHO_MAPA_FASE1, maxObstaculos);

    pGColisoes = new Gerenciador::GerenciadorColisoes(&ListaJogadores, &ListaObstaculos, &ListaInimigos);
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
        criarJogadores(CAMINHO_MAPA_FASE1);
        pGColisoes = new Gerenciador::GerenciadorColisoes(&ListaJogadores, &ListaObstaculos, &ListaInimigos);
    }
}

void Fases::Fase1::vaiPraProximoFase()
{
    if(todosMortos())
    {
        changeEstado(Estados::fase2);
    }
}


