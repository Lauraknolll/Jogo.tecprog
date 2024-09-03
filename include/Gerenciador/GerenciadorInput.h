//codigo usado de referencia proveniente de https://github.com/MatheusBurda/Desert/tree/master
#pragma once

#include <list>
#include <map>
#include <SFML/Graphics.hpp>
#include <string>

namespace Controle
{
    class Observador;
}

namespace Gerenciador
{

    class GerenciadorInput
    {
    private:
        std::list<Controle::Observador *> objObservador;

        std::list<Controle::Observador *>::iterator it;

        std::map<sf::Keyboard::Key, std::string> keyMap;

        /* padrão Singleton */
        static GerenciadorInput *pInstanciaGI;

        GerenciadorInput();

    public:
        ~GerenciadorInput();

        static GerenciadorInput *getGerenciadorInput();

        void Attach(Controle::Observador *pObservador);

        void Detach(Controle::Observador *pObservador);

        void lidarTeclaPressionada(sf::Keyboard::Key key);

        void lidarTeclaSolta(sf::Keyboard::Key key);

        std::string getNomeTecla(sf::Keyboard::Key key);
    };

}