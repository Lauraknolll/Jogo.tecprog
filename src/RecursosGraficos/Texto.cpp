#include "../../include/RecursosGraficos/Texto.h"

#define TEXTO_SIZE 24
#define CAMINHO_FONTE "arial.ttf"

// Inicialização do membro estático
Gerenciador::GerenciadorGrafico* Texto::pGGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

Texto::Texto(sf::Vector2f position, std::string info, const char* path) :
    info(info) 
{
    texto.setString(info);

    font.loadFromFile(CAMINHO_FONTE);

    texto.setFont(font);


    
    texto.setCharacterSize(20);
    
    setAlinhamentoTexto(AlinhamentoTexto::esquerda);

    texto.setPosition(sf::Vector2f(position.x, position.y));

    texto.setFillColor(sf::Color::White);
    
}

Texto::~Texto() 
{ 
    
}

void Texto::setTextoInfo(std::string info) 
{
    this->info = info;
    texto.setString(this->info);
}

void Texto::setPosicao(sf::Vector2f position) 
{
    texto.setPosition(position);
}

void Texto::setCorTexto(const unsigned int R, const unsigned int G, const unsigned int B) 
{
    texto.setFillColor(sf::Color(R, G, B));
}

void Texto::setTamanhoFonte(const unsigned int size) 
{
    texto.setCharacterSize(size);
}

void Texto::setAlinhamentoTexto(AlinhamentoTexto option) 
{
    
    // Ajusta a origem para o alinhamento correto
    switch (option) 
    {
    case AlinhamentoTexto::esquerda:
        texto.setOrigin(0, 0);
        break;
    case AlinhamentoTexto::centro:
        
        texto.setOrigin(getTamanho().x / 2, getTamanho().y / 2);
        break;
    case AlinhamentoTexto::direita:
        texto.setOrigin(getTamanho().x, getTamanho().y);
        break;
    default:
        texto.setOrigin(0, 0); // Caso inesperado, pode ser ajustado conforme necessário
        break;
    }
}

sf::Vector2f Texto::getTamanho() const 
{
    sf::FloatRect textoRect = texto.getLocalBounds();
    return sf::Vector2f(textoRect.width, textoRect.height);
}

void Texto::render() 
{
    
    pGGrafico->desenhaTexto(texto);

}

std::string Texto::getInfo() const 
{
    return info;
}

sf::Vector2f Texto::getPosicao() const 
{
    return texto.getPosition();
}
