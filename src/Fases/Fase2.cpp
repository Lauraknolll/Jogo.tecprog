#include "../../include/Fases/Fase2.h"

#define CAMINHO_MAPA_FASE2 "src/mapaFase2.json"//caminho para o mapa da fase 2

Fases::Fase2::Fase2(Estados::Mediator* gE) :
    Fase(), Estados::Estado(gE, Estados::EstadoID::fase2), maxInimigos(7), maxObstaculos(10)
{
    ativo = false;
    setMediator(gE);
    Lista_Entidades = new Lista::ListaEntidade();
    pEventos = Gerenciador::GerenciadorEvento::getGerenciadorEventos();
    mapa = CAMINHO_MAPA_FASE2;
    carregarMapa(mapa);
    criar();
}

Fases::Fase2::~Fase2()
{
    ListaJogadores.clear();
    ListaObstaculos.clear();
    ListaInimigos.clear();
}

void Fases::Fase2::criarRinos()
{
    Personagens::Rino* chefao;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0, cont = 0; 

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(CAMINHO_MAPA_FASE2, &x, &y, &indice, 5);
        
        if (posi != sf::Vector2f(-1, -1))
        {
            if(cont < 3)
            {
                chefao = new Personagens::Rino(posi.x, posi.y, 96.0, 64.0);
                list<Entidades::Entidade*>::iterator it;
                it = ListaJogadores.begin();
                chefao->setJogador(static_cast<Personagens::Jogador*>(*it));
                ListaInimigos.push_back(static_cast<Entidades::Entidade*>(chefao));
                Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(chefao));
                cont++;
            }
            else if((rand()%10 < 5) && (3 < cont < maxInimigos)) //numero aleatório de inimigos
            {
                chefao = new Personagens::Rino(posi.x, posi.y, 96.0, 64.0);
                list<Entidades::Entidade*>::iterator it;
                it = ListaJogadores.begin();
                chefao->setJogador(static_cast<Personagens::Jogador*>(*it));
                ListaInimigos.push_back(static_cast<Entidades::Entidade*>(chefao));
                Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(chefao));
                cont++;
            }
        }
    }

}

void Fases::Fase2::criarEspinhos()
{
    Obstaculos::Espinho* pinho;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0, cont = 0;

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(CAMINHO_MAPA_FASE2, &x, &y, &indice, 6);
        
        if (posi != sf::Vector2f(-1, -1))
        {
            if(cont < 3)
            {
                pinho = new Obstaculos::Espinho(posi.x, posi.y, 41.0, 26.0);
                ListaObstaculos.push_back(static_cast<Entidades::Entidade*>(pinho));
                Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(pinho));        
                cont++;       
            }
            if(( rand()%10 < 5) && (3 < cont < maxObstaculos)) // numero aleatório de obstáculos (50%)
            {
                pinho = new Obstaculos::Espinho(posi.x, posi.y, 41.0, 26.0);
                ListaObstaculos.push_back(static_cast<Entidades::Entidade*>(pinho));
                Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(pinho));
                cont++;
            }
        }
    }
}

void Fases::Fase2::executar()
{
    
}

void Fases::Fase2::atualizar()
{
    ativo = true;

    if(!pausado)
    {
        gerenciarMortos();
    
        Lista_Entidades->percorrerLista();
        
        gerenciarColisoes();
    
        venceuJogo();
        
        morreu();
    }
    else
    {
        mensagemPausado();
    }
}

void Fases::Fase2::render()
{
    fundo();
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
    hud();
}

void Fases::Fase2::criar()
{
    criarJogadores(CAMINHO_MAPA_FASE2);
    criarPlataformas(CAMINHO_MAPA_FASE2);

    criarGalinhas(CAMINHO_MAPA_FASE2, maxInimigos);
    criarLava(CAMINHO_MAPA_FASE2, maxObstaculos);

    criarRinos();
    criarEspinhos();
    
    pGColisoes = new Gerenciador::GerenciadorColisoes(&ListaJogadores, &ListaObstaculos, &ListaInimigos);
}

void Fases::Fase2::resetEstado()
{

    pontuacao = 0;
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
    mapa = CAMINHO_MAPA_FASE2;
    carregarMapa(mapa);
    pausado = false;
    criar();
}

void Fases::Fase2::sair()
{
    if(ativo && pausado){
        ativo = false;
        pausado = false;
        resetEstado();
        changeEstado(Estados::EstadoID::mainMenu);
    }
}
            
void Fases::Fase2::segundoJogador()
{
    if(ativo){
        ativo = false;
        criarJogadores(CAMINHO_MAPA_FASE2);
        pGColisoes = new Gerenciador::GerenciadorColisoes(&ListaJogadores, &ListaObstaculos, &ListaInimigos);
    }
}

void Fases::Fase2::morreu()
{
    if(checarJogadores()){
        ativo = false;
        changeEstado(Estados::EstadoID::gameOver);
    }
}

void Fases::Fase2::venceuJogo()
{
    if(todosMortos())
    {
        ativo = false;
        changeEstado(Estados::telaFim);
    }
}

