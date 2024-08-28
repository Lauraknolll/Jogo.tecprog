#include "../../include/Fases/Fase.h"
#define CAMINHO_MAPA "src/mapaJogo1.json"

Fases::Fase::Fase() :
    Ente(), ListaJogadores(), ListaInimigos(), ListaObstaculos(), pGColisoes(nullptr)
{
    Lista_Entidades = new Lista::ListaEntidade();
    pGColisoes = NULL;
    pEventos = Gerenciador::GerenciadorEvento::getGerenciadorEventos();
    mapa = CAMINHO_MAPA;

    carregarMapa(mapa);
    printf("iniciou");
}

Fases::Fase::~Fase()
{
    if (pGColisoes != nullptr)
    {
        delete pGColisoes;
        pGColisoes = nullptr;
    }
    ListaJogadores.clear();
    ListaInimigos.clear();
    ListaObstaculos.clear();
    Lista_Entidades->cleanList();
}

void Fases::Fase::criarJogadores(sf::Vector2f posicao, sf::Vector2f tamanho)
{
    Personagens::Jogador* jog = new Personagens::Jogador(posicao.x, posicao.y, tamanho.x, tamanho.y);
    pEventos->setJogador(jog);
    ListaJogadores.push_back(static_cast<Entidades::Entidade*>(jog));
    Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(jog));
}

void Fases::Fase::criarInimigosFaceis(sf::Vector2f posicao, sf::Vector2f tamanho)
{
    Personagens::InimigoFacil* ent = new Personagens::InimigoFacil(posicao.x, posicao.y, tamanho.x, tamanho.y);
    ListaInimigos.push_back(static_cast<Entidades::Entidade*>(ent));
    Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(ent));
}

void Fases::Fase::criarInimigosMedios(sf::Vector2f posicao, sf::Vector2f tamanho)
{
    Personagens::InimigoMedio* ent = new Personagens::InimigoMedio(posicao.x, posicao.y, tamanho.x, tamanho.y);
    ListaInimigos.push_back(static_cast<Entidades::Entidade*>(ent));
    Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(ent));
    }

void Fases::Fase::criarPLataformas(sf::Vector2f posicao, sf::Vector2f tamanho)
{
    Obstaculos::Plataforma* ent  = new Obstaculos::Plataforma(posicao.x, posicao.y, tamanho.x, tamanho.y);
    ListaObstaculos.push_back(static_cast<Entidades::Entidade*>(ent));
    Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(ent));
}

void Fases::Fase::executar()
{
    Gerenciador::GerenciadorGrafico *pontGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
    
    Lista_Entidades->percorrerLista();
    Lista_Entidades->desenharEntidades(pontGrafico);
    list<Entidades::Entidade*>::iterator it;
    Entidades::Entidade* ent;
    for( it = ListaJogadores.begin(); it != ListaJogadores.end(); it++){
        if(static_cast<Personagens::Jogador*>(*it)){
            ent = *it;
            pontGrafico->centralizarCamera(ent->getPosicao());
        }
    }
    
    pGColisoes->colide();
}

void Fases::Fase::cria()
{

    criarMapa(CAMINHO_MAPA);
    pGColisoes = new Gerenciador::GerenciadorColisoes(ListaJogadores, ListaObstaculos, ListaInimigos);

}

void Fases::Fase::carregarMapa(std::string mapJson) {
    std::ifstream arquivo(mapJson);
    
    if(!arquivo.is_open()){
        std::cerr << "Erro ao abrir o mapa (caminho mapa)" << std::endl;
        return;
    }

    arquivo >> mapa;
    arquivo.close();
    printf("oi");
}

void Fases::Fase::criarMapa(std::string caminho_mapa)
{
    // Pega as informações do mapa
    int sizeTiled = mapa["tilewidth"]; //tamhno do tile
    int width = mapa["width"];
    int height = mapa["height"]; // altura do mapa
    
    int indice = 0;
    
    Entidades::Entidade* ent ;
    //loop de entidades com tamanho variável em X
    for(int y = 0; y < height-3; y++)
    {
        for(int x = 0; x < width; x++)
        {   
            long int tileId = mapa["layers"][0]["data"][indice];
            //printf("%d", tileId);
            if(tileId != 0){
                int mult = 1;
                int cond = x+1;
                while(tileId == mapa["layers"][0]["data"][++indice] && (cond) < (width)){
                    mult++;
                    cond++;
                }
               
                sf::Vector2f posicao(x*sizeTiled, y*sizeTiled);
                
                x += mult - 1;

                sf::Vector2f tamanho(sizeTiled*mult, sizeTiled);
                
                switch (tileId)
                {
                case(-1):
                    criarJogadores(posicao, tamanho);
                break;
                case(1):
                    criarPLataformas(posicao, tamanho);
                break;
                default:
                    break;
                }
            }
            else{
                indice++;
            }
        }
        //printf("\n");
    }

}
