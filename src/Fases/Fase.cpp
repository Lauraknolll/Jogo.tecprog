#include "../../include/Fases/Fase.h"
#define CAMINHO_MAPA "src/mapaJogo1.json"

Fases::Fase::Fase() :
    Ente()
{

}

Fases::Fase::~Fase()
{

}

void Fases::Fase::executar()
{

}

/*
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

}*/
