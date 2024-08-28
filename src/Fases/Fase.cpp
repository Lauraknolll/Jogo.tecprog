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


void Fases::Fase::carregarMapa(std::string mapJson) {
    std::ifstream arquivo(mapJson);
    
    if(!arquivo.is_open()){
        std::cerr << "Erro ao abrir o mapa (caminho mapa)" << std::endl;
        return;
    }

    arquivo >> mapa;
    arquivo.close();
}



sf::Vector2f Fases::Fase::lerMapa(std::string caminho_mapa, int* xx, int* yy, int* indice, int num_entidade)
{
    //Pega as informações do mapa
    int sizeTiled = mapa["tilewidth"]; //tamhno do tile
    int width = mapa["width"];
    int height = mapa["height"]; // altura do mapa
    
    Entidades::Entidade* ent ;
    //loop de entidades com tamanho variável em X
    for(*yy; *yy < height-3; *yy++)
    {
        for(*xx; *xx < width; *xx++)
        {   
            long int tileId = mapa["layers"][0]["data"][*indice];
            //printf("%d", tileId);
            if(tileId != 0){
                int mult = 1;
                int cond = (*xx)+1;
                while(tileId == mapa["layers"][0]["data"][++(*indice)] && (cond) < (width)){
                    mult++;
                    cond++;
                }
               
                sf::Vector2f posicao((*xx)*sizeTiled, (*yy)*sizeTiled);
                
                *xx += mult - 1;

                sf::Vector2f tamanho(sizeTiled*mult, sizeTiled);

                if(tileId == num_entidade){
                    return posicao;
                }
                
                
            }
            else{
                (*indice)++;
            }
        }
        return sf::Vector2f(-1, -1);
        
    }

}
