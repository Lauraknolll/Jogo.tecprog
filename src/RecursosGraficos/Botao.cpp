#include "../../include/RecursosGraficos/Botao.h"

#define LARGURA_BOTAO 200.0
#define ALTURA_BOTAO 20.0
#define COR_TEXTO 225, 225, 225
#define TAMANHO_FONTE 20

Gerenciador::GerenciadorGrafico* Botao::pGGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
Botao::Botao(sf::Vector2f posicao, std::string info):
texto(posicao, info),
textura(nullptr)
{
    
    corpo.setSize(sf::Vector2f(LARGURA_BOTAO, ALTURA_BOTAO));

    corpo.setOrigin(sf::Vector2f(LARGURA_BOTAO / 2, ALTURA_BOTAO / 2));

    corpo.setPosition(sf::Vector2f(posicao.x, posicao.y));

    corpo.setTexture(textura);

    texto.setTamanhoFont(TAMANHO_FONTE);

    texto.setAlinhamentoTexto(TextoAlignment::centro);

    texto.setCorTexto(COR_TEXTO);

    //texto.setPosition(Math::CoordF(position.x, position.y));
}

Botao::~Botao()
{

}

void Botao::selecionar(const bool selecinado)
{
    if (selecinado)
            texto.setCorTexto(0,0,0);
}

void Botao::render()
{
    pGGrafico->desenhaEntidade(corpo);

    texto.render();
}