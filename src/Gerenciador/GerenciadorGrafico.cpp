#include "../../include/Gerenciador/GerenciadorGrafico.h"

Gerenciador::GerenciadorGrafico* Gerenciador::GerenciadorGrafico::pInstanciaGG = nullptr; 

Gerenciador::GerenciadorGrafico::GerenciadorGrafico() :
    janela(new sf::RenderWindow(sf::VideoMode(800.0f, 600.0f), "Jogo")), MapaTexturas(), camera(sf::Vector2f(800.0, 600.0), sf::Vector2f(1200.0, 800.0))
{   
    janela->setView(camera);
}

Gerenciador::GerenciadorGrafico::~GerenciadorGrafico()
{
    //tem que deketar as coisas do mapa tbm
    if(janela)
    {
        delete janela;
        janela = nullptr;
    }
}

Gerenciador::GerenciadorGrafico* Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()
{
    if(pInstanciaGG == nullptr) /*  primeira  vez que o método é chamado */
    {
        pInstanciaGG = new GerenciadorGrafico();
    }
    return pInstanciaGG; /* todas as outras vezes  */
}

sf::RenderWindow* Gerenciador::GerenciadorGrafico::getJanela()
{
    return janela;
}

void Gerenciador::GerenciadorGrafico::limpaJanela()
{
    janela->clear();
}

void Gerenciador::GerenciadorGrafico::fecharJanela()
{
    janela->close();
}

const bool Gerenciador::GerenciadorGrafico::verificarJanelaAberta()
{
    return janela->isOpen();
}

void Gerenciador::GerenciadorGrafico::desenhaEntidade(sf::RectangleShape corpo)
{
    janela->draw(corpo);
}

void Gerenciador::GerenciadorGrafico::monstraEntidade()
{
    janela->display();
}

sf::Texture* Gerenciador::GerenciadorGrafico::carregaTextura(std::string caminho)
{
    /*  Tenta encontrar se a textura já existe no mapa */
    std::map<std::string, sf::Texture*>::iterator it;
    for(it = MapaTexturas.begin(); it != MapaTexturas.end(); it++)
    {
        if(it->first == caminho)
        {
            return it->second;
        }
    }
    
    /*  Se não existe cria uma nova */
    sf::Texture* textura = new sf::Texture();

    if(!textura->loadFromFile(caminho))
    {
        std::cout << "Erro ao abrir o arquivo" << caminho << std::endl;
        exit(1);
    }

    MapaTexturas.insert(std::pair<std::string, sf::Texture*>(caminho, textura));

    return textura;
}

void Gerenciador::GerenciadorGrafico::centralizarCamera(sf::Vector2f centro)
{
    camera.setCenter(centro.x, centro.y);
    janela->setView(camera);
}






