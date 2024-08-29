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



sf::Vector2f Fases::Fase::lerMapa(std::string caminho_mapa, int* xx, int* yy, int* indice, long int num_entidade)
{
    // Pega as informações do mapa
    int sizeTiled = mapa["tilewidth"]; // Tamanho do tile
    int width = mapa["width"];
    int height = mapa["height"]; // Altura do mapa
    int cont = 0;
    
    Entidades::Entidade* ent;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            long int tileId = mapa["layers"][0]["data"][*indice];
            if(cont == *indice){
                if (tileId != 0)
                {
                    int mult = 1;
                    int cond = x + 1;
                    while (tileId == mapa["layers"][0]["data"][++(*indice)] && cond < width)
                    {
                        
                        ++mult;
                        ++cond;
                    }
           
                    sf::Vector2f posicao(x * sizeTiled, y * sizeTiled);
                    *yy = mult;

                    sf::Vector2f tamanho(sizeTiled * mult, sizeTiled);

                    if (tileId == num_entidade)
                    {
                        return posicao;
                    }
                }
                else
                {
                    ++(*indice);
                }
            }
            cont++;
        }
    }
    return sf::Vector2f(-1, -1);
}

void Fases::Fase::gerenciarColisoes()
{
    pGColisoes->colide();
}
