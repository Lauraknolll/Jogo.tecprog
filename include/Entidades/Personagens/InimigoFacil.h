#pragma once

#include "Inimigo.h"

namespace Personagens
{
    class InimigoFacil : public Inimigo
    {
        private:
            short movimentoale;
        public:
            InimigoFacil(float xx = 0, float yy = 0, float ww = 50.0, float hh = 50.0);
            ~InimigoFacil();
            void executar();
            void moveAleatorio();
            void atualizarPosicao();
            const sf::RectangleShape getCorpo();
            void imprimir(Gerenciador::GerenciadorGrafico *gG);
            void colide(Entidade *outraEntidade, sf::Vector2f intersecao); 
    };
}