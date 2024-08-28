#include "../../include/RecursosGraficos/Botao.h"

#define LARGURA_BOTAO 200.0f
#define ALTURA_BOTAO 40.0f
#define COR_TEXTO_DEFAULT (225, 225, 225)
#define COR_TEXTO_SELECIONADO (0, 0, 0)
#define TAMANHO_FONTE 20

// Inicialização do membro estático
Gerenciador::GerenciadorGrafico* Botao::pGGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

Botao::Botao(sf::Vector2f posicao, std::string info) :
    texto(posicao, info),
    textura(nullptr)
{
    corpo.setSize(sf::Vector2f(LARGURA_BOTAO, ALTURA_BOTAO));
    corpo.setOrigin(sf::Vector2f(LARGURA_BOTAO / 2.0f, ALTURA_BOTAO / 2.0f));
    corpo.setPosition(posicao);
    corpo.setFillColor(sf::Color::Red);

    // Corpo pode ter textura definida aqui, se necessário
    // corpo.setTexture(textura);

    texto.setTamanhoFont(TAMANHO_FONTE);
    texto.setAlinhamentoTexto(TextoAlignment::centro);
    texto.setCorTexto(255,255,0);

    // Definição da posição do texto (se necessário, baseada na posição do botão)
    // texto.setPosition(sf::Vector2f(posicao.x, posicao.y));
}

Botao::~Botao()
{
    // Destruição dos recursos, se necessário
    printf("Limpou o botao");
}

void Botao::selecionar(bool selecionado)
{
    if (selecionado)
        texto.setCorTexto(255,255,255);
    else
        texto.setCorTexto(255,255,255);
}

void Botao::render()
{
    
    pGGrafico->desenhaEntidade(corpo);
    texto.render();
}
