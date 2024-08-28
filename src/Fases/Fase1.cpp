#include "../../include/Fases/Fase1.h"

#define CAMINHO_MAPA_FASE1 "src/mapaJogo1.json" // camonho para o mapa da fase 1

Fases::Fase1::Fase1() :
    Fase(), ListaJogadoresFase1(), ListaObstaculosFase1(), ListaInimigosFase1(), pGColisoes(nullptr)
{
    Lista_Entidades = new Lista::ListaEntidade();
    pGEventos = Gerenciador::GerenciadorEvento::getGerenciadorEventos();
    mapa = CAMINHO_MAPA_FASE1;

    carregarMapa(mapa);
    printf("iniciou");
}

Fases::Fase1::~Fase1()
{
    ListaObstaculosFase1.clear();
    ListaInimigosFase1.clear();
}

// apenas para fins de testes
void Fases::Fase1::criarJogadores(sf::Vector2f posicao, sf::Vector2f tamanho)
{
    Personagens::Jogador* jog = new Personagens::Jogador(posicao.x, posicao.y, tamanho.x, tamanho.y);
    pGEventos->setJogador(jog);
    ListaJogadoresFase1.push_back(static_cast<Entidades::Entidade*>(jog));
    Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(jog));
}

void Fases::Fase1::criarPlataformas(sf::Vector2f posicao, sf::Vector2f tamanho)
{
    Obstaculos::Plataforma* ent  = new Obstaculos::Plataforma(posicao.x, posicao.y, tamanho.x, tamanho.y);
    ListaObstaculosFase1.push_back(static_cast<Entidades::Entidade*>(ent));
    Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(ent));
}
//

void Fases::Fase1::criarInimigosFaceis(sf::Vector2f posicao, sf::Vector2f tamanho)
{
    Personagens::InimigoFacil *ent = new Personagens::InimigoFacil(posicao.x, posicao.y, tamanho.x, tamanho.y);
    if (ent)
    {
        ListaInimigosFase1.push_back(static_cast<Entidades::Entidade *>(ent));
        Lista_Entidades->addEntidade(static_cast<Entidades::Entidade *>(ent));
    }
}

void Fases::Fase1::criarObstaculosFaceis(sf::Vector2f posicao, sf::Vector2f tamanho)
{

}

void Fases::Fase1::criarInimigosMedios(sf::Vector2f posicao, sf::Vector2f tamanho)
{
    Personagens::InimigoMedio* ent = new Personagens::InimigoMedio(posicao.x, posicao.y, tamanho.x, tamanho.y);
    ListaInimigosFase1.push_back(static_cast<Entidades::Entidade*>(ent));
    Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(ent));
}

void Fases::Fase1::criarObstaculosMedios(sf::Vector2f posicao, sf::Vector2f tamanho)
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

void Fases::Fase1::executar()
{
    Gerenciador::GerenciadorGrafico *pontGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
    
    Lista_Entidades->percorrerLista();
    Lista_Entidades->desenharEntidades(pontGrafico);
    list<Entidades::Entidade*>::iterator it;
    Entidades::Entidade* ent1;
    Entidades::Entidade* ent2;
    it = ListaJogadoresFase1.begin();
    ent1 = *it;
    it++;
    ent2 = *it;
    pontGrafico->centralizarCamera(sf::Vector2f((ent1->getPosicao().x + ent2->getPosicao().x)/2, 300));
    
    pGColisoes->colide();
}

void Fases::Fase1::cria()
{
    criarMapa(CAMINHO_MAPA_FASE1);
    pGColisoes = new Gerenciador::GerenciadorColisoes(ListaJogadoresFase1, ListaObstaculosFase1, ListaInimigosFase1);
}

void Fases::Fase1::criarMapa(std::string caminho_mapa)
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
                    criarPlataformas(posicao, tamanho);
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
