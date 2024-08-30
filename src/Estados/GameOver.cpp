#include "../../include/Estados/GameOver.h"

Menus::GameOver::GameOver(Estados::GerenciadorEstado* GE):
Menu(),
Estado(static_cast<Estados::GerenciadorEstado*>(GE), Estados::EstadoID::gameOver)
{
    max = 0;

    Gerenciador::GerenciadorGrafico* GM = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
    Botao* bt = NULL;
    float w, h;

    // Obtenha o tamanho da janela
    w = GM->getJanela()->getSize().x;
    h = GM->getJanela()->getSize().y;

    bt = new Botao(sf::Vector2f(w / 2.0f, h / 2.0f + 150), "MENU");
    bt->selecionar(true);
    vectorBotao.push_back(bt);

    titulo.setTextoInfo("GAME OVER");
    titulo.setTamanhoFonte(120);
    titulo.setCorTexto(32, 79, 221);
    titulo.setAlinhamentoTexto(AlinhamentoTexto::centro);

    titulo.setPosicao(sf::Vector2f(w / 2.0f, h / 2.0f));
}
Menus::GameOver::~GameOver()
{

}

void Menus::GameOver::atualizar()
{
    ativo = true;
    if (titulo.getPosicao().y < 200)
        titulo.setPosicao(sf::Vector2f(titulo.getPosicao().x, titulo.getPosicao().y + 1));
}
void Menus::GameOver::render()
{
    updateView();
    it = vectorBotao.begin();
    (*it)->render();
    titulo.render();
}
void Menus::GameOver::executar()
{
    if(ativo){
        changeEstado(Estados::mainMenu);
        ativo = false;
    }
}
void Menus::GameOver::resetEstado()
{

}