#include "../include/Tilemap.h"

#include "../include/Entidades/Entidade.h"
#include "../include/Entidades/Personagens/Jogador.h"
#include "../include/Entidades/Personagens/InimigoFacil.h"
#include "../include/Entidades/Personagens/InimigoMedio.h"
#include "../include/Entidades/Obstaculos/Plataforma.h"
#include "../include/Entidades/Obstaculos/Lava.h"


Tilemap::Tilemap(std::string mapJson, std::string caminhoImagem)
{
    textura_mapa = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
    pGEvento = Gerenciador::GerenciadorEvento::getGerenciadorEventos();
    carregarMapa(mapJson, caminhoImagem);
}

Tilemap::~Tilemap()
{

}

Entidades::Entidade* Tilemap::criarEntidade(sf::Vector2f posicao, sf::Vector2f tamanho, int tipo)
{
    float x, y, w, h;
    x = posicao.x;
    y = posicao.y;
    w = tamanho.x;
    h = tamanho.y;
    
    switch (tipo){
        case (-1) : //jogador
            return new Personagens::Jogador(x, y, w, h);
            break;
        case (1) : //plataforma sprite 1
            return new Obstaculos::Plataforma(x, y, w, h);
            break;
        
    }
     /*- ASSIM POR DIANTE PARA CADA TIPO DE ENTIDADE QUE VC NECESSITA CRIAR
    */
   return NULL;
}

void Tilemap::carregarMapa(std::string mapJson, std::string caminhoImagem="") {
    std::ifstream arquivo(mapJson);
    
    if(!arquivo.is_open()){
        std::cerr << "Erro ao abrir o mapa (caminho mapa)" << std::endl;
        return;
    }

    arquivo >> mapa;
    arquivo.close();
    printf("oi");
       //se o caminho da imagem não for passado, ele pega o caminho do json e troca a extensão para .png
    //if (caminhoImagem == "")
        //caminhoImagem = caminhoMapa.substr(0, caminhoMapa.find_last_of(".")) + ".png";

    /*if(!textura_mapa->carregaTextura(caminhoImagem)){
        std::cerr << "Erro ao carregar a textura do mapa" << std::endl;
        return;
    }*/


}

void Tilemap::criarMapa(Lista::ListaEntidade* jogador, Lista::ListaEntidade* inimigo, Lista::ListaEntidade* obstaculo/*, sf::Texture* textura_mapa*/)
{
    // Pega as informações do mapa
    int sizeTiled = mapa["tilewidth"]; //tamhno do tile
    int width = mapa["width"];
    int height = mapa["height"]; // altura do mapa

    printf("Altura: %d, Largura: %d, Tamanho: %d", height, width, sizeTiled);

    int indice = 0;

    //loop de entidades com tamanho fixo (sizeTiled x sizeTiled)
    /*for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int tileId = mapa["layers"][0]["data"][indice++];
            if(tileId != 0){
                sf::Vector2f posicao(x * sizeTiled, y * sizeTiled);
                sf::Vector2f tamanho(sizeTiled, sizeTiled);
                criarEntidade(posicao, tamanho, tileId, entidades);
            }
        }
    }*/
    Entidades::Entidade* ent ;
    //loop de entidades com tamanho variável em X
    for(int y = 0; y < height-3; y++)
    {
        for(int x = 0; x < width-1; x++)
        {   
            
            long int tileId = mapa["layers"][0]["data"][indice];
            printf("%d", tileId);
            if(tileId != 0){
               int mult = 1;
                while(tileId == mapa["layers"][0]["data"][++indice]){
                    mult++;
                }
                sf::Vector2f posicao(x*sizeTiled, y*sizeTiled);
                
                x += mult - 1;
                if (x >= width) {
                    break;
                }

                sf::Vector2f tamanho(sizeTiled*mult, sizeTiled);
                ent = criarEntidade(posicao, tamanho, tileId);
                switch (ent->getID())
                {
                case (Entidades::jogador):
                    pGEvento->setJogador(static_cast<Personagens::Jogador*>(ent));
                    jogador->addEntidade(ent);
                    break;
                case (Entidades::plataforma):
                    obstaculo->addEntidade(ent);
                    break;
                
                default:
                    break;
                }
                 //cria a entidade
                //entidades->addEntidade(ent);  //adiciona a entidade no vetor de entidades
               
            }
            else{
                indice++;
            }
        }
        printf("\n");
    }

}