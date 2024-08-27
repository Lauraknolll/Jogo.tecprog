#pragma once

#include "../Gerenciador/GerenciadorGrafico.h"

#include <SFML/Graphics.hpp>
#include <string>

#define FONT_PATH "./assets/Fonts/MainFont.ttf"



enum TextoAlignment {
    esquerda,
    centro,
    direita
};

class Texto {
private:
    std::string info;

    sf::Text texto;

    static Gerenciador::GerenciadorGrafico* pGraphicM;

public:
    Texto(sf::Vector2f position = sf::Vector2f(0, 0), std::string info = "", const char* path = FONT_PATH);

    ~Texto();

    void setTextoInfo(std::string info);

    void setPosicao(sf::Vector2f position);

    void setCorTexto(const unsigned int R, const unsigned int G, const unsigned int B);

    void setTamanhoFont(const unsigned int size);

    void setAlinhamentoTexto(TextoAlignment option);

    sf::Vector2f getTamanho() const;

    void render();

    std::string getInfo() const;

    sf::Vector2f getPosicao() const;
};

