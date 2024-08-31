#include "../../include/Fases/Fase.h"
#include "../../include/RecursosGraficos/Botao.h"

Fases::Fase::Fase() : 
Ente(), control(this)
{
    pontuacao = 0;
    pausado = false;

    // Obtenha o tamanho da janela

    pausar.setTextoInfo("PAUSADO");
    pausar.setTamanhoFonte(70);
    pausar.setCorTexto(32, 79, 221);

    mensagem.setTextoInfo("pressione ' P ' para continuar");
    mensagem.setTamanhoFonte(20);
    mensagem.setCorTexto(32, 79, 221);

    mensagem2.setTextoInfo("pressione ' esc ' para sair");
    mensagem2.setTamanhoFonte(20);
    mensagem2.setCorTexto(32, 79, 221);

    vida1.setCorTexto(32, 79, 221);
    vida2.setCorTexto(32, 79, 221);
    ponto.setCorTexto(32, 79, 221);

}

Fases::Fase::~Fase()
{
}

void Fases::Fase::executar()
{
}

void Fases::Fase::carregarMapa(std::string mapJson)
{
    std::ifstream arquivo(mapJson);

    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o mapa (caminho mapa)" << std::endl;
        return;
    }

    arquivo >> mapa;
    arquivo.close();
}

sf::Vector2f Fases::Fase::lerMapa(std::string caminho_mapa, int *xx, int *yy, int *indice, long int num_entidade)
{
    // Pega as informações do mapa
    int sizeTiled = mapa["tilewidth"]; // Tamanho do tile
    int width = mapa["width"];
    int height = mapa["height"]; // Altura do mapa
    int cont = 0;

    Entidades::Entidade *ent;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            long int tileId = mapa["layers"][0]["data"][*indice];
            if (cont == *indice)
            {
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

void Fases::Fase::gerenciarMortos()
{
    
    //it_jog = ListaJogadores.begin();
    if (ListaInimigos.size() > 0)
    {
        vector<Entidades::Entidade *>::iterator it;
        Personagens::Inimigo *paux = nullptr;

        for (it = ListaInimigos.begin(); it != ListaInimigos.end(); it++)
        {
            paux = static_cast<Personagens::Inimigo *>(*it);
            if (paux != nullptr)
            {
                if (paux->getNumVidas() <= 0)
                {
                    if(paux->getVivo()){
                        paux->setVivo(); // agora tá morto
                        pontuacao += 100;
                    }
                }
            }
        }
    }

    if (ListaJogadores.size() > 0)
    {
        list<Entidades::Entidade *>::iterator it_jog;
        Personagens::Jogador *paux = nullptr;

        for (it_jog = ListaJogadores.begin(); it_jog != ListaJogadores.end(); it_jog++)
        {
            paux = static_cast<Personagens::Jogador *>(*it_jog);
            if (paux != nullptr)
            {
                if (paux->getNumVidas() <= 0 || paux->getPosicao().y > 700.f)
                {
                    paux->setVivo(); // agora tá morto
                }
            }
        }
    }
}

bool Fases::Fase::todosMortos()
{
    if (ListaInimigos.size() > 0)
    {
        vector<Entidades::Entidade *>::iterator it;
        Personagens::Inimigo *paux = nullptr;

        for (it = ListaInimigos.begin(); it != ListaInimigos.end(); it++)
        {
            paux = static_cast<Personagens::Inimigo *>(*it);
            if (paux != nullptr)
            {
                if(paux->getVivo())
                    return false;
            }
        }

    }
    return true;
}

void Fases::Fase::criarJogadores(std::string caminho_mapa)
{
    Personagens::Jogador* jog;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0;

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(caminho_mapa, &x, &y, &indice, -1);
        
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

void Fases::Fase::criarPlataformas(std::string caminho_mapa)
{
    Obstaculos::Plataforma* plat;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0;

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(caminho_mapa, &x, &y, &indice, 1);
        
        if (posi != sf::Vector2f(-1, -1))
        {
            plat = new Obstaculos::Plataforma(posi.x, posi.y, 32.0*y, 16.0);
            ListaObstaculos.push_back(static_cast<Entidades::Entidade*>(plat));
            Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(plat));
        }
    }
}

void Fases::Fase::criarGalinhas(std::string caminho_mapa, int maxIni)
{
    Personagens::Galinha* ini;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0, cont = 0;

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(caminho_mapa, &x, &y, &indice, 4);
        
        if (posi != sf::Vector2f(-1, -1))
        {
            if(cont < 3)
            {
                ini = new Personagens::Galinha(posi.x, posi.y, 62.0, 68.0);
                list<Entidades::Entidade*>::iterator it;
                it = ListaJogadores.begin();
                ini->setJogador(static_cast<Personagens::Jogador*>(*it));
                ListaInimigos.push_back(static_cast<Entidades::Entidade*>(ini));
                Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(ini));
                cont++;
            }
            else if((rand()%10 < 5) && (3 < cont < maxIni))
            {
                ini = new Personagens::Galinha(posi.x, posi.y, 62.0, 68.0);
                list<Entidades::Entidade*>::iterator it;
                it = ListaJogadores.begin();
                ini->setJogador(static_cast<Personagens::Jogador*>(*it));
                ListaInimigos.push_back(static_cast<Entidades::Entidade*>(ini));
                Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(ini));
                cont++;
            }
        }
    }
}

void Fases::Fase::criarLava(std::string caminho_mapa, int maxObs)
{
    Obstaculos::Lava* lava;
    sf::Vector2f posi(0,0);
    int x = 0, y = 0, indice = 0, cont = 0;

    while (posi != sf::Vector2f(-1, -1))
    {
        posi = lerMapa(caminho_mapa, &x, &y, &indice, 2);
        
        if (posi != sf::Vector2f(-1, -1))
        {
            if(cont < 3)
            {
                lava = new Obstaculos::Lava(posi.x, posi.y, 32.0*y, 16.0);
                ListaObstaculos.push_back(static_cast<Entidades::Entidade*>(lava));
                Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(lava));
                cont++;
            }
            if((rand()%10 < 5) && (3 < cont < maxObs))
            {
                lava = new Obstaculos::Lava(posi.x, posi.y, 32.0*y, 16.0);
                ListaObstaculos.push_back(static_cast<Entidades::Entidade*>(lava));
                Lista_Entidades->addEntidade(static_cast<Entidades::Entidade*>(lava));
                cont++;
            }
        }
    }
}

bool Fases::Fase::checarJogadores()
{
    if (ListaJogadores.size() > 0)
    {
        list<Entidades::Entidade *>::iterator it;
        Personagens::Jogador *paux = nullptr;

        for (it = ListaJogadores.begin(); it != ListaJogadores.end(); it++)
        {
            paux = static_cast<Personagens::Jogador *>(*it);
            if (paux != nullptr)
            {
                if(paux->getVivo())
                    
                    return false;
            }
        }

    }
    return true;
}

int* Fases::Fase::getPontuacao()
{
    return &pontuacao;
}

void Fases::Fase::pause()
{
    pausado = !pausado;
}

void Fases::Fase::mensagemPausado()
{
    sf::View camera;
    sf::Vector2f centro;
    Gerenciador::GerenciadorGrafico* GG = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
    camera = GG->getCamera();
    
    centro = camera.getCenter();

    pausar.setPosicao(sf::Vector2f(centro.x - 250, centro.y - 60));
    mensagem.setPosicao(sf::Vector2f(centro.x - 250, centro.y + 40));
    mensagem2.setPosicao(sf::Vector2f(centro.x - 250, centro.y + 90));

    pausar.setCorTexto(32, 79, 221);
    mensagem.setCorTexto(32, 79, 221);
    mensagem2.setCorTexto(32, 79, 221);

    pausar.render();
    mensagem.render();
    mensagem2.render();
}

void Fases::Fase::hud()
{
    
    Gerenciador::GerenciadorGrafico* GG = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
    camera = GG->getCamera();
    
    centro = camera.getCenter();

    vida1.setPosicao(sf::Vector2f(centro.x - 600, centro.y - 400));
    vida2.setPosicao(sf::Vector2f(centro.x - 400, centro.y - 400));
    ponto.setPosicao(sf::Vector2f(centro.x - 200, centro.y - 400));

    list<Entidades::Entidade*>::iterator it;
    Entidades::Entidade* ent1;
    Entidades::Entidade* ent2;
    it = ListaJogadores.begin();
    ent1 = *it;
    vida1.setTextoInfo("P1: "+std::to_string(static_cast<Personagens::Jogador*>(ent1)->getNumVidas()) + "/50");
    
    ponto.setTextoInfo("PONTUCAO: "+std::to_string(pontuacao));

    if(ListaJogadores.size()){
        vida1.render();
        ponto.render();
        if(ListaJogadores.size() > 1){
            it++;
            ent2 = *it;
            vida2.setTextoInfo("P2:"+std::to_string(static_cast<Personagens::Jogador*>(ent2)->getNumVidas())+ "/50");
            vida2.render();
        }
    }
}


