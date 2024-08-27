#pragma once

#include <list>
#include <map>
#include <SFML/Graphics.hpp>
#include <string>

namespace Controle {
    class Observador;
} // namespace Controle

namespace Gerenciador {

    class GerenciadorInput {
    private:
        std::list<Controle::Observador*> objObserving;
        
        std::list<Controle::Observador*>::iterator it;

        std::map<sf::Keyboard::Key, std::string> keyMap;

        /* Singleton design pattern */
        static GerenciadorInput* instance;

        GerenciadorInput();

    public:
        ~GerenciadorInput();

        static GerenciadorInput* getInstance();

        void Attach(Controle::Observador* pObserver);

        void Detach(Controle::Observador* pObserver);

        void lidarTeclaPrecionada(sf::Keyboard::Key key);

        void lidarTeclaSolta(sf::Keyboard::Key key);

        std::string getNomeTecla(sf::Keyboard::Key key);
    };

} // namespace Gerenciadores