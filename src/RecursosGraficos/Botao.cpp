//codigo usado de referencia proveniente de https://github.com/MatheusBurda/Desert/tree/master
#include "../../include/RecursosGraficos/Botao.h"
#include <SFML/Graphics.hpp>

#define LARGURA_BOTAO 350.0f
#define ALTURA_BOTAO 45.0f
#define COR_TEXTO_DEFAULT (225, 225, 225)
#define COR_TEXTO_SELECIONADO (0, 0, 0)
#define TAMANHO_FONTE 29
#define SELECIONADO "imagens/madeira.jpg"
#define NAO_SELECIONADO "imagens/madeira_escura.jpg"

// Inicialização do membro estático
Gerenciador::GerenciadorGrafico* Botao::pGGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

Botao::Botao(sf::Vector2f posicao, std::string info) :
    texto(posicao, info)
{
    textura.loadFromFile(SELECIONADO);
    textura_des.loadFromFile(NAO_SELECIONADO);
    corpo.setSize(sf::Vector2f(LARGURA_BOTAO, ALTURA_BOTAO));
    corpo.setOrigin(sf::Vector2f(LARGURA_BOTAO / 2.0f, ALTURA_BOTAO / 2.0f));
    corpo.setPosition(posicao);
    corpo.setTexture(&textura_des);

    // Corpo pode ter textura definida aqui, se necessário
    // corpo.setTexture(textura);

    texto.setTamanhoFonte(TAMANHO_FONTE);
    texto.setAlinhamentoTexto(AlinhamentoTexto::centro);
    texto.setCorTexto(211, 211, 211);

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
    {   
        this->corpo.setTexture(&textura);
        this->texto.setCorTexto(32, 79, 221); 
    }
    else
    {  
        this->corpo.setTexture(&textura_des);
        this->texto.setCorTexto(211, 211, 211); 
    }
}

void Botao::render()
{
    
    pGGrafico->desenhaEntidade(corpo);
    texto.render();
}
