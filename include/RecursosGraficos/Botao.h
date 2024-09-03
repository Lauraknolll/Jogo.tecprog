//codigo usado de referencia proveniente de https://github.com/MatheusBurda/Desert/tree/master
#pragma once

#include "Texto.h"

class Botao
{
private:
    static Gerenciador::GerenciadorGrafico *pGGrafico;
    sf::RectangleShape corpo;
    Texto texto;
    sf::Texture textura;
    sf::Texture textura_des;

public:
    Botao(sf::Vector2f posicao = sf::Vector2f(0, 0), std::string info = "");

    ~Botao();

    void selecionar(const bool selecionado);

    void render();
};