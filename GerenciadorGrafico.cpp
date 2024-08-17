#include "GerenciadorGrafico.h"

Gerenciador::GerenciadorGrafico* Gerenciador::GerenciadorGrafico::pInstanciaGG = nullptr; 

Gerenciador::GerenciadorGrafico::GerenciadorGrafico() :
    janela(new sf::RenderWindow(sf::VideoMode(800.0f, 600.0f), "Jogo"))
{

}

Gerenciador::GerenciadorGrafico::~GerenciadorGrafico()
{
    if(janela)
    {
        delete janela;
        janela = nullptr;
    }
}

Gerenciador::GerenciadorGrafico* Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()
{
    if(pInstanciaGG == nullptr) //primeira  vez que o método é chamado
    {
        pInstanciaGG = new GerenciadorGrafico();
    }
    return pInstanciaGG; //todas as outras vezes
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








