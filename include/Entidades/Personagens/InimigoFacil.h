#pragma once

#include "Inimigo.h"

namespace Personagens
{
    class InimigoFacil : public Inimigo
    {
        private:
            short movimentoale;
        public:
            InimigoFacil();
            ~InimigoFacil();
            void executar();
            void moveAleatorio();
            const sf::RectangleShape getCorpo();
            void imprimir(Gerenciador::GerenciadorGrafico *gG);
            void colide(Entidade *outraEntidade, sf::Vector2f intersecao); 
    };
}