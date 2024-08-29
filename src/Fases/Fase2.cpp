#include "../../include/Fases/Fase2.h"

#define CAMINHO_MAPA_FASE2 "src/mapaJogo2.json"//caminho para o mapa da fase 2

Fases::Fase2::Fase2(Estados::GerenciadorEstado* gE, Controle::ControleJogador* cont) :
    Fase(), Estados::Estado(gE, Estados::EstadoID::fase2), maxInimigos(7), maxObstaculos(10)
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
            jog = new Personagens::Jogador(posi.x, posi.y, 56.0, 56.0);
            controle->setJogador(jog);
            //pEventos->setJogador(jog);
            ListaJogadores.push_back(static_cast<Entidades::Entidade*>(jog));
            Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(jog));
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
            plat = new Obstaculos::Plataforma(posi.x, posi.y, 32.0*y, 16.0); 
            ListaObstaculos.push_back(static_cast<Entidades::Entidade*>(plat));
            Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(plat));
        }
    }
}

void Fases::Fase2::criarGalinhas()
{
    Personagens::Galinha* ini;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0, cont = 0;

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(CAMINHO_MAPA_FASE2, &x, &y, &indice, 4);
        
        if (posi != sf::Vector2f(-1, -1))
        {
            if((rand()%10 <= 7) && cont < maxInimigos) //número aleatório de inimigos
            {
                ini = new Personagens::Galinha(posi.x, posi.y, 62.0, 68.0);
                list<Entidades::Entidade*>::iterator it;
                it = ListaJogadores.begin();
                ini->setJogador(static_cast<Personagens::Jogador*>(*it)); //pra poder perseguir
                ListaInimigos.push_back(static_cast<Entidades::Entidade*>(ini));
                Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(ini));
                cont++;
            }
        }
    }
}

void Fases::Fase2::criarLava()
{
    Obstaculos::Lava* lava;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0, cont = 0;

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(CAMINHO_MAPA_FASE2, &x, &y, &indice, 2);
        
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
            if((rand()%10 <= 7) && cont < maxInimigos) //numero aleatório de inimigos
            {
                chefao = new Personagens::Rino(posi.x, posi.y, 96.0, 64.0);
                list<Entidades::Entidade*>::iterator it;
                it = ListaJogadores.begin();
                chefao->setJogador(static_cast<Personagens::Jogador*>(*it));
                ListaInimigos.push_back(static_cast<Entidades::Entidade*>(chefao));
                Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(chefao));
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
            if(( rand()%10 <= 7) && cont < maxObstaculos) // numero aleatório de obstáculos (50%)
            {
                pinho = new Obstaculos::Espinho(posi.x, posi.y, 41.0, 26.0);
                ListaObstaculos.push_back(static_cast<Entidades::Entidade*>(pinho));
                Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(pinho));
            }
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
    pontGrafico->centralizarCamera(sf::Vector2f((ent1->getPosicao().x/* + ent2->getPosicao().x*/), 350));

    gerenciarColisoes();
    gerenciarMortos();
    
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
    criarLava();

    criarRinos();
    criarEspinhos();
    
    pGColisoes = new Gerenciador::GerenciadorColisoes(ListaJogadores, ListaObstaculos, ListaInimigos);
}

void Fases::Fase2::resetEstado()
{

}

void Fases::Fase2::gerenciarMortos() //substitui retira mortos do gerenciador de colisão
{
    if(ListaInimigos.size() > 0)
    {
        vector<Entidades::Entidade*>::iterator it;
        Personagens::Inimigo* paux = nullptr;

        for(int i = 0; i < ListaInimigos.size(); i++)
        {
            paux = static_cast<Personagens::Inimigo*>(ListaInimigos[i]);
            if(paux != nullptr)
            {
                if(paux->getNumVidas() == 0)
                {
                    *it = ListaInimigos[i];
                    std::cout << "Retirou alguém" << std::endl;
                    ListaInimigos.erase(it);
                //i--;
                //if(i < 0)
                //    i = -1;
                }
            }
        }
    }
    else
    {

    }
}