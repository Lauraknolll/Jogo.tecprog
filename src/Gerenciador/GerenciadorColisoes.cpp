#include "../../include/Gerenciador/GerenciadorColisoes.h"

#include <iostream>
using namespace std;

#include "math.h"
#include "../../include/Entidades/Personagens/Jogador.h"
#include "../../include/Entidades/Personagens/Rino.h"

Gerenciador::GerenciadorColisoes::GerenciadorColisoes(list<Entidades::Entidade *> *Jogador1, list<Entidades::Entidade *> *Obstaculos1, vector<Entidades::Entidade *> *Inimigos1 /*, States::Level* plvl*/) : Jogadores(Jogador1), Obstaculos(Obstaculos1), Inimigos(Inimigos1) /*,  plvl(plvl) */ {}

Gerenciador::GerenciadorColisoes::~GerenciadorColisoes()
{
    Jogadores = nullptr;
    Obstaculos = nullptr;
    Inimigos = nullptr;
}

void Gerenciador::GerenciadorColisoes::tratarColisoesJogadoresObstaculos()
{
    Entidades::Entidade *ent1 = nullptr;
    Entidades::Entidade *ent2 = nullptr;
    list<Entidades::Entidade *>::iterator it1;
    list<Entidades::Entidade *>::iterator it2;

    /* Colisão entre os jogadores e os obstáculos */
    for (it1 = Jogadores->begin(); it1 != Jogadores->end(); it1++)
    {
        for (it2 = Obstaculos->begin(); it2 != Obstaculos->end(); it2++)
        {
            ent1 = (*it1);
            ent2 = (*it2);
            if (ent1 != nullptr && ent2 != nullptr)
            {

                sf::RectangleShape corpo1 = ent1->getCorpo();
                sf::RectangleShape corpo2 = ent2->getCorpo();

                sf::Vector2f pos1 = corpo1.getPosition();
                sf::Vector2f pos2 = corpo2.getPosition();

                sf::Vector2f tam1 = corpo1.getSize();
                sf::Vector2f tam2 = corpo2.getSize();

                sf::Vector2f distanciaEntreCentros(
                    fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)),
                    fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f)));

                sf::Vector2f somaMetadeRetangulo(tam1.x / 2.0f + tam2.x / 2.0f, tam1.y / 2.0f + tam2.y / 2.0f);
                sf::Vector2f intersecao = sf::Vector2f(distanciaEntreCentros.x - somaMetadeRetangulo.x, distanciaEntreCentros.y - somaMetadeRetangulo.y);

                /*  Condição pra colisão*/
                if (intersecao.x < 0.0f && intersecao.y < 0.0f)
                {
                    ent1->colide(ent2, intersecao);
                    ent2->colide(ent1, intersecao);
                }
            }
        }
    }
}

void Gerenciador::GerenciadorColisoes::tratarColisoesJogadoresInimigos()
{
    Entidades::Entidade *ent1 = nullptr;
    Entidades::Entidade *ent2 = nullptr;
    list<Entidades::Entidade *>::iterator it1;
    vector<Entidades::Entidade *>::iterator it2;
    
    /* Colisão entre os jogadores e os inimigos */
    for (it1 = Jogadores->begin(); it1 != Jogadores->end(); it1++)
    {
        for (it2 = Inimigos->begin(); it2 != Inimigos->end(); it2++)
        {
            ent1 = (*it1);
            ent2 = (*it2);
            
            if (ent1 != nullptr && ent2 != nullptr && (static_cast<Personagens::Inimigo*>(ent2))->getVivo())
            {

                sf::RectangleShape corpo1 = ent1->getCorpo();
                sf::RectangleShape corpo2 = ent2->getCorpo();

                sf::Vector2f pos1 = corpo1.getPosition();
                sf::Vector2f pos2 = corpo2.getPosition();

                sf::Vector2f tam1 = corpo1.getSize();
                sf::Vector2f tam2 = corpo2.getSize();

                sf::Vector2f distanciaEntreCentros(
                    fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)),
                    fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f)));

                sf::Vector2f somaMetadeRetangulo(tam1.x / 2.0f + tam2.x / 2.0f, tam1.y / 2.0f + tam2.y / 2.0f);
                sf::Vector2f intersecao = sf::Vector2f(distanciaEntreCentros.x - somaMetadeRetangulo.x, distanciaEntreCentros.y - somaMetadeRetangulo.y);

                /*  Condição pra colisão*/
                if (intersecao.x < 0.0f && intersecao.y < 0.0f)
                {
                    ent1->colide(ent2, intersecao);
                    ent2->colide(ent1, intersecao);
                }
                
                if(dynamic_cast<Personagens::Rino*>(ent2))
                {
                    if(static_cast<Personagens::Rino*>(ent2)->getProjetil())
                    {
                        ent2 = static_cast<Personagens::Rino*>(ent2)->getProjetil();
                        
                        sf::RectangleShape corpo2 = ent2->getCorpo();
                        
                        sf::Vector2f pos2 = corpo2.getPosition();
                        
                        sf::Vector2f tam2 = corpo2.getSize();

                        sf::Vector2f distanciaEntreCentros(
                            fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)),
                            fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f)));

                        sf::Vector2f somaMetadeRetangulo(tam1.x / 2.0f + tam2.x / 2.0f, tam1.y / 2.0f + tam2.y / 2.0f);
                        sf::Vector2f intersecao = sf::Vector2f(distanciaEntreCentros.x - somaMetadeRetangulo.x, distanciaEntreCentros.y - somaMetadeRetangulo.y);

                        /*  Condição pra colisão*/
                        if (intersecao.x < 0.0f && intersecao.y < 0.0f)
                        {
                            ent1->colide(ent2, intersecao);
                            ent2->colide(ent1, intersecao);
                        }
                    }
                }
            }
        }
    }
}

void Gerenciador::GerenciadorColisoes::colide()
{

    tratarColisoesJogadoresObstaculos();
    tratarColisoesJogadoresInimigos();
}
