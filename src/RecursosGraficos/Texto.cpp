#include "../../include/RecursosGraficos/Texto.h"

#define TEXTo_SIZE 24


Gerenciador::GerenciadorGrafico* Texto::pGraphicM = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

Texto::Texto(sf::Vector2f position, std::string info, const char* path) :
info(info) {
    texto.setString(info);

    //texto.setFont(*pGraphicM->loadFont(path));

    texto.setCharacterSize(TEXTo_SIZE);

    setAlinhamentoTexto(TextoAlignment::esquerda);

    texto.setPosition(sf::Vector2f(position.x, position.y));

    texto.setFillColor(sf::Color::White);
}

Texto::~Texto() { }

void Texto::setTextoInfo(std::string info) {
    this->info = info;
    texto.setString(this->info);
}

void Texto::setPosicao(sf::Vector2f position) {
    texto.setPosition(sf::Vector2f(position.x, position.y));
}

void Texto::setCorTexto(const unsigned int R, const unsigned int G, const unsigned int B) {
    texto.setFillColor(sf::Color(R, G, B));
}

void Texto::setTamanhoFont(const unsigned int size) {
    texto.setCharacterSize(size);
}

void Texto::setAlinhamentoTexto(TextoAlignment option) {
    switch (option) {
    case TextoAlignment::esquerda:
        texto.setOrigin(0, 0);
        break;
    case TextoAlignment::centro:
        texto.setOrigin(getTamanho().x / 2, getTamanho().y);
        break;
    case TextoAlignment::direita:
        texto.setOrigin(getTamanho().x, 0);
        break;
    default:
        texto.setOrigin(getTamanho().x / 2, getTamanho().y);
        break;
    }
}

sf::Vector2f Texto::getTamanho() const {
    sf::FloatRect textoRect = texto.getLocalBounds();
    return sf::Vector2f(textoRect.width, textoRect.height);
}

void Texto::render() {
    pGraphicM->desenhaTexto(texto);
}

std::string Texto::getInfo() const {
    return info;
}

sf::Vector2f Texto::getPosicao() const {
    return sf::Vector2f(texto.getPosition().x, texto.getPosition().y);
}
